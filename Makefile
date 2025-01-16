# Makefile for Snake Game

CXX = g++
CXXFLAGS = -std=c++11 -Iinclude -lncurses
CXXFLAGS += -g

SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
EXEC = clashFighter

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Default rule to build the executable
all: $(EXEC)

# Linking the object files to create the executable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) -lncurses

# Rule to compile .cpp files to .o object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object and executable files
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

# To run the game
run: $(EXEC)
	./$(EXEC)