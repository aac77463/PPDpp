# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++20 -g
TARGET = main
SRCS = main.cpp interp1d.cpp sigma_init.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to link the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)
