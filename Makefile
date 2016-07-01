CXX=g++

CXXFLAGS=-g -O2 -std=c++11

LDFLAGS=-lm

all: Main 

Main: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
