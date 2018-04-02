CXX=g++
CXXFLAGS=-W -Wall -g -std=c++11
LDFLAGS=
EXEC=auto
SRC= ../src/Cellule.cc ../src/Grille.cc main.cc
OBJ= $(SRC:.cc=.o)

all: $(EXEC)

auto: $(OBJ)
	@$(CXX) -o $@ $^ $(LDFLAGS)

main.o: ../include/Grille.h

%.o: ..%.cc
	@$(CXX) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o
	@rm -rf ../src/*.o

mrproper: clean
	@rm -rf $(EXEC)
