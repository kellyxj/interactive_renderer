#include "VBOBox.hpp"

VBOBox::VBOBox() {
    initialized = false;
}

bool VBOBox::init(SDL_GLContext* _context, std::vector<double> & vboContents, std::string _vertexShaderSource, std::string _fragmentShaderSource) {
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
                //get attribute locations and bind buffers
            }
        }
    }

    initialized = success;
    return success;
}

void VBOBox::switchToMe() {
    
}

bool VBOBox::isReady() {
    
}

void VBOBox::adjust() {
    
}

void VBOBox::draw() {
    
}

void VBOBox::reload() {
    
}
