
# compile with debug information
ifeq ($(mode),release)
	CXXFLAGS=-O3 -Wall
else
	mode = debug
	CXXFLAGS=-O0 -g -Wall
endif

all: main

main: runs.hpp intervaltree.hpp suffixtree.hpp main.cpp 