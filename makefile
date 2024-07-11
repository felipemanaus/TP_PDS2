OBJDIR = obj
SRCDIR = source
INCDIR = include


# Detecta o sistema operacional
ifeq ($(OS), Windows_NT)
    RM = del
	BAR = "\"
    EXE = main.exe
else
    RM = rm -f
	BAR = /
    EXE = main
endif

all: main

OBJFILES = $(OBJDIR)/jogador.o $(OBJDIR)/jogo.o $(OBJDIR)/Lig4.o $(OBJDIR)/main.o

main: $(OBJFILES)
	g++ -Wall -std=c++11 -o main $(OBJFILES)

$(OBJDIR)/jogador.o: $(SRCDIR)/jogador.cpp $(INCDIR)/jogador.hpp
	g++ -Wall -std=c++11 -c $(SRCDIR)/jogador.cpp -o $(OBJDIR)/jogador.o

$(OBJDIR)/jogo.o: $(SRCDIR)/jogo.cpp $(INCDIR)/jogo.hpp
	g++ -Wall -std=c++11 -c $(SRCDIR)/jogo.cpp -o $(OBJDIR)/jogo.o

$(OBJDIR)/Lig4.o: $(SRCDIR)/Lig4.cpp $(INCDIR)/Lig4.hpp
	g++ -Wall -std=c++11 -c $(SRCDIR)/Lig4.cpp -o $(OBJDIR)/Lig4.o

$(OBJDIR)/main.o: main.cpp $(INCDIR)/jogador.hpp $(INCDIR)/jogo.hpp $(INCDIR)/Lig4.hpp
	g++ -Wall -std=c++11 -c main.cpp -o $(OBJDIR)/main.o

clean:
	$(RM) $(OBJDIR)$(BAR)*.o $(EXE)
