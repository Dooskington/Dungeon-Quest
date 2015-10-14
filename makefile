#
# makefile
# Declan Hopkins
# 10/10/2015
#

CC = g++
SRC_PATH = src
BIN_PATH = bin
BIN_NAME = DungeonQuest
C_FLAGS = -Wall
SRC_FILES := $(wildcard $(SRC_PATH)/*.cpp)
OBJ_FILES := $(SRC_FILES:$(SRC_PATH)%.cpp=$(BIN_PATH)%.o)

# Build the project in either debug or release
all: debug

# Build the project and package it into an app bundle
release: clean build
	@echo "*** Release build complete ***"

# Build the project and run it through the terminal
debug: clean build
	@echo "*** Debug build complete ***"
	@./$(BIN_PATH)/$(BIN_NAME)

# Link all the .o files in the bin/ directory to create the executable
build: $(OBJ_FILES)
	@echo "*** Linking ***"
	@$(CC) $(OBJ_FILES) -o $(BIN_PATH)/$(BIN_NAME)

# Compile all the .cpp files in the src/ directory to the bin/ directory
$(BIN_PATH)/%.o: $(SRC_PATH)/%.cpp
	@echo "*** Compiling" $< "***"
	@$(CC) -c $< -o $@ $(C_FLAGS)

# Clean up all the raw binaries
clean:
	@echo "*** Cleaning Binaries ***"
	@rm -f $(BIN_PATH)/$(BIN_NAME) $(BIN_PATH)/*.o
