CXX = clang++
CXXFLAGS = -std=c++11 -Wall
TARGET = catan
SRCS = main.cpp Board.cpp Player.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = Board.hpp Player.hpp Types.hpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
