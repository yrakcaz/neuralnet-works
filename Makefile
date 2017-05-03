EXE=neuralnet-works
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++11 -pedantic -Iinclude/
LDFLAGS=
LIB=src/json/jsoncpp.cpp
SRC=src/training.cc src/neuron.cc src/brain.cc src/main.cc
OBJ=$(SRC:.cc=.o)
OBJ+=$(LIB:.cpp=.o)
TAR=yrakcaz-$(EXE)

-include makefile.rules

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXE) $^ $(LDFLAGS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJ) $(EXE) $(TAR).tar.bz2

distclean: clean
	rm -f makefile.rules

export:
	git archive HEAD --prefix=$(TAR)/ | bzip2 > $(TAR).tar.bz2

.PHONY: all clean distclean export
