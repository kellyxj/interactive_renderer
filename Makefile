CXX = g++

COMPILER_FLAGS = -Wall

LINKER_FLAGS = -lSDL2main -lSDL2 -lGL -lGLEW

SRC_DIR = ./src/
OBJ_DIR = ./obj/
BIN_DIR = ./bin/

#TODO: rewrite this so I don't have to type these manually
SRC_NAMES = wrappers/window.cpp wrappers/SDLBox.cpp wrappers/runner.cpp wrappers/VBOBox.cpp\
primitives/vec4.cpp primitives/mat4.cpp\
geometry/geometry.cpp geometry/plane.cpp geometry/sphere.cpp\
renderers/meshRenderer.cpp\
utils/logger.cpp utils/shaderLoader.cpp\
scene.cpp main.cpp

SOURCES = $(foreach source_name, $(SRC_NAMES), $(SRC_DIR)$(source_name))
OBJECTS = $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SOURCES))

OBJ_NAME = main
EXE = $(BIN_DIR)$(OBJ_NAME)

all : $(EXE)

$(EXE) : $(OBJECTS)
	$(CXX) $(COMPILER_FLAGS) $^ -o $@ $(LINKER_FLAGS)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp
	$(CXX) $< -c -o $@

.PHONY: clean
clean: 
	rm -rf $(OBJECTS) $(EXE)