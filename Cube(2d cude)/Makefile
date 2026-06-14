
CXX = g++
CXXFLAGS = -I./include
LIBS = -lglfw -lGL -ldl
SRC_GLAD = ./src/glad.c

all: main

main: main.cpp $(SRC_GLAD)
	$(CXX) main.cpp $(SRC_GLAD) -o main $(CXXFLAGS) $(LIBS)
