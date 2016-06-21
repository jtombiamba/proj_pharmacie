CXX=g++

CXXFLAGS=-g -O2

LDFLAGS=

all: Main

Main: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
