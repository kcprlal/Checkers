CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinc

SRCS = src/main.cpp src/Board.cpp src/Gameplay.cpp src/CinHandling.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = app

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run
