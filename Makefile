# Compiler and Flags
CXX = g++
CFLAGS = -g -std=c++11 -Wall

# Directories
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = __tests__

# Source files
SRC_FILES = $(SRC_DIR)/main.cpp $(SRC_DIR)/String.cpp $(SRC_DIR)/StringConstructor.cpp $(SRC_DIR)/StringOperator.cpp $(SRC_DIR)/Console.cpp

TEST_SRC_FILES = $(SRC_DIR)/test.cpp $(SRC_DIR)/String.cpp $(SRC_DIR)/StringConstructor.cpp $(SRC_DIR)/StringOperator.cpp $(SRC_DIR)/Console.cpp

# Object files
OBJ = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TEST_OBJ = $(TEST_SRC_FILES:$(SRC_DIR)/%.cpp=$(TEST_DIR)/%.o)

# Output executable
OUT = $(BUILD_DIR)/main.exe
TEST_OUT = $(TEST_DIR)/test.exe

# Default target (build executable)
all: $(OUT)

# Link object files to create the executable
$(OUT): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(OUT)

$(TEST_OUT): $(TEST_OBJ)
	$(CXX) $(CFLAGS) $(TEST_OBJ) -o $(TEST_OUT)

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TEST_DIR):
	mkdir -p $(TEST_DIR)

# Compile each .cpp file into a .o object file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/%.o: $(SRC_DIR)/%.cpp | $(TEST_DIR)
	$(CXX) $(CFLAGS) -c $< -o $@


test: $(TEST_OUT)
	./$(TEST_OUT)

# Run the executable
run: $(OUT)
	./$(OUT)

# Clean up generated files
clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/*.exe
	rm -rf $(TEST_DIR)/*.o $(TEST_DIR)/*.exe
	@echo Cleaned...

# Ensure the "all", "run", and "clean" targets are not confused with filenames
.PHONY: all run clean test
