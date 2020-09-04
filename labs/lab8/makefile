
CC = g++
CFLAGS = -Wall -g -std=c++11
LFLAGS = -lm
TARGET = out

all: main.cpp
		$(CC) $(CFLAGS) main.cpp -o $(TARGET) $(LFLAGS)

# Generate source and object lists
SRCS := main.cpp src/date/Date.cpp
HDRS := src/date/Date.hpp
OBJS := main.o src/date/Date.o

# Link al built objects
build:$(OBJS)
	@mkdir -p $(dir $(TARGET))
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

%.o:%.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

SRCS := $(wildcard *.cpp) $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
HDRS := $(wildcard *.hpp) $(wildcard src/*.hpp) $(wildcard src/**/*.hpp)

which:
	@echo "FOUND SOURCES: ${SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"
	@echo "GENERATED OBJS: ${OBJS}"

OBJS := $(patsubst %.cpp, bin/%.o, $(wildcard*.cpp))
OBJS += $(filter %.o, $(patsubst src/%.cpp, bin/%.o, $(SRCS)))

bin/%.o: %.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bin/%.o: src/%.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)
	rm -rf bin

run: build
	./$(TARGET) dates.txt sorted.txt
