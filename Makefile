CXX = g++

COMPILER_FLAGS = -Wall

LINKER_FLAGS = -lSDL2main -lSDL2 -lGL -lGLEW

SRC_DIR = ./src/
OBJ_DIR = ./obj/
BIN_DIR = ./bin/

SRC_NAMES = main.cpp wrappers/SDLBox.cpp

SOURCES = $(foreach source_name, $(SRC_NAMES), $(SRC_DIR)$(source_name))
OBJECTS = $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SOURCES))

OBJ_NAME = main
EXE = $(BIN_DIR)$(OBJ_NAME)

all : $(EXE)

$(EXE) : $(OBJECTS)
	$(CXX) $^ -o $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp
	$(CXX) $(COMPILER_FLAGS) $(LINKER_FLAGS) $< -c -o $@

.PHONY: clean
clean: 
	rm -rf $(OBJECTS) $(EXE)