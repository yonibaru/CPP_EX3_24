CXX = clang++
CXXFLAGS = -std=c++11 -Wall
TARGET = main
SRCS = main.cpp Board.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = Board.hpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
