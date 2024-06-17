CXX = clang++
CXXFLAGS = -std=c++11 -Wall
TARGET_MAIN = catan
TARGET_TEST = test
SRCS_MAIN = main.cpp Board.cpp Player.cpp
SRCS_TEST = test.cpp Board.cpp Player.cpp
OBJS_MAIN = $(SRCS_MAIN:.cpp=.o)
OBJS_TEST = $(SRCS_TEST:.cpp=.o)
DEPS = Board.hpp Player.hpp Types.hpp

all: $(TARGET_MAIN) $(TARGET_TEST)

$(TARGET_MAIN): $(OBJS_MAIN)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TARGET_TEST): $(OBJS_TEST)
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test.o: test.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

Board.o: Board.cpp Board.hpp Player.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Player.o: Player.cpp Player.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_MAIN) $(OBJS_TEST) $(TARGET_MAIN) $(TARGET_TEST)

