CXX=g++

CXXFLAGS=-g -O2

LDFLAGS=-lm

all: Main 

Main: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^