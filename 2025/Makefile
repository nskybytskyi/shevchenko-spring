# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++20 -O3 -march=native

# Output executable
TARGET = main

# Source files
SRCS = main.cpp solution.cpp frequency_table.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the build files
clean:
	rm -f $(OBJS) $(TARGET)

# Remove the executable and object files
.PHONY: all clean
