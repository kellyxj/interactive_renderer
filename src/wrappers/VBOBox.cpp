#include "VBOBox.hpp"

VBOBox::VBOBox() {
    initialized = false;
}

bool VBOBox::init(SDL_GLContext _context, std::vector<float> & vboContents, std::string _vertexShaderSource, std::string _fragmentShaderSource) {
    bool success = true;
    
    context = _context;
    programID = glCreateProgram();

    GLuint vertexShader = glCreateShader( GL_VERTEX_SHADER );
    const char* vertexShaderSource = _vertexShaderSource.c_str();

    glShaderSource( vertexShader, 1, &vertexShaderSource, NULL );
	glCompileShader( vertexShader );

    GLint vShaderCompiled = GL_FALSE;
	glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &vShaderCompiled );
	if( vShaderCompiled != GL_TRUE )
	{
		printf( "Unable to compile vertex shader %d!\n", vertexShader );
        printShaderLog(vertexShader);
        success = false;
	}
    else {
        glAttachShader( programID, vertexShader );

        GLuint fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
        const char* fragmentShaderSource = _fragmentShaderSource.c_str();

        glShaderSource( fragmentShader, 1, &fragmentShaderSource, NULL );
        glCompileShader( fragmentShader );

        GLint fShaderCompiled = GL_FALSE;
		glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &fShaderCompiled );
		if( fShaderCompiled != GL_TRUE )
		{
			printf( "Unable to compile fragment shader %d!\n", fragmentShader );
			printShaderLog( fragmentShader );
			success = false;
		}
        else {
            glAttachShader(programID, fragmentShader);
            glLinkProgram(programID);

            GLint programSuccess = GL_TRUE;
			glGetProgramiv( programID, GL_LINK_STATUS, &programSuccess );
            if( programSuccess != GL_TRUE )
			{
				printf( "Error linking program %d!\n", programID );
				printProgramLog( programID );
				success = false;
			}
            else {
                printUniformsAndAttributes(programID);
                GLint count;
                glGetProgramiv(programID, GL_ACTIVE_ATTRIBUTES, &count);
                GLsizei name_length;

                for(int i = 0; i < count; i++) {
                    GLAttribute attribute;
                    glGetActiveAttrib(programID, (GLuint)i, MAX_NAME_SIZE, &name_length, &attribute.size, &attribute.type, attribute.name);
                    attributes.push_back(attribute);
                }
                glGetProgramiv(programID, GL_ACTIVE_UNIFORMS, &count);
                for(int i = 0; i < count; i++) {
                    GLUniform uniform;
                    glGetActiveUniform(programID, (GLuint)i, MAX_NAME_SIZE, &name_length, &uniform.size, &uniform.type, uniform.name);
                    uniforms.push_back(uniform);
                }

                glGenBuffers( 1, &vboLocation );
				glBindBuffer( GL_ARRAY_BUFFER, vboLocation );

                nVerts = vboContents.size();
                GLfloat vertexData[nVerts];
                std::copy(vboContents.begin(), vboContents.end(), vertexData);

				glBufferData( GL_ARRAY_BUFFER, nVerts * sizeof(GLfloat), vertexData, GL_STATIC_DRAW );
            }
        }
    }
    initialized = success;
    return success;
}

void VBOBox::switchToMe() {
    if(initialized) {
        glUseProgram(programID);
        for(GLAttribute attribute : attributes) {
            glEnableVertexAttribArray(attribute.index);
        }
        glBindBuffer( GL_ARRAY_BUFFER, vboLocation );

        int currentOffset = 0;
        for(GLAttribute attribute : attributes) {
            //currently hard coding sizeof vec4
            //TODO: create table mapping GLenum types to size in bytes
            glVertexAttribPointer(attribute.index, attribute.size, attribute.type, false, 4*sizeof(GLfloat), (void *)currentOffset);
            currentOffset += 4*sizeof(GLfloat);
        }
    }
}

bool VBOBox::isReady() {
    return false;
}

void VBOBox::adjust() {
    //TODO: uniforms are hard coded. Refactor to allow any number of uniforms
    mat4 modelMatrix;
    mat4 mvpMatrix;

    modelMatrix.setIdentity();
    mvpMatrix.setIdentity();

    GLfloat * modelMatrixData = (GLfloat*)modelMatrix.entries;
    GLfloat * mvpMatrixData = (GLfloat*)mvpMatrix.entries;

    glUniformMatrix4fv(0, 1, false, modelMatrixData);
    glUniformMatrix4fv(1, 1, false, mvpMatrixData);
}

void VBOBox::draw() {
    glDrawArrays(GL_POINTS, 0, nVerts);
}

void VBOBox::reload() {
    
}
