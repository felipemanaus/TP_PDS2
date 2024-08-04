OBJDIR = obj
SRCDIR = source
INCDIR = include

# Detecta o sistema operacional
ifeq ($(OS), Windows_NT)
	RM = del
	BAR = ""
	EXE = main.exe
	MKDIR = if not exist $(OBJDIR) mkdir $(OBJDIR)
else
	RM = rm -f
	BAR = /
	EXE = main
	MKDIR = mkdir -p $(OBJDIR)
endif

all: $(OBJDIR) $(EXE)

$(OBJDIR):
	$(MKDIR)

$(EXE): $(OBJDIR)/jogador.o $(OBJDIR)/jogo.o $(OBJDIR)/lig4.o $(OBJDIR)/reversi.o $(OBJDIR)/main.o
	g++ -Wall -std=c++11 -o $(EXE) $(OBJDIR)/jogador.o $(OBJDIR)/jogo.o $(OBJDIR)/lig4.o $(OBJDIR)/reversi.o $(OBJDIR)/main.o

$(OBJDIR)/jogador.o: $(SRCDIR)/jogador.cpp $(INCDIR)/jogador.hpp
	g++ -Wall -std=c++11 -c $(SRCDIR)/jogador.cpp -o $(OBJDIR)/jogador.o

$(OBJDIR)/jogo.o: $(SRCDIR)/jogo.cpp $(INCDIR)/jogo.hpp
	g++ -Wall -std=c++11 -c $(SRCDIR)/jogo.cpp -o $(OBJDIR)/jogo.o

$(OBJDIR)/lig4.o: $(SRCDIR)/lig4.cpp $(INCDIR)/lig4.hpp
	g++ -Wall -std=c++11 -c $(SRCDIR)/lig4.cpp -o $(OBJDIR)/lig4.o

$(OBJDIR)/reversi.o: $(SRCDIR)/reversi.cpp $(INCDIR)/reversi.hpp
	g++ -Wall -std=c++11 -c $(SRCDIR)/reversi.cpp -o $(OBJDIR)/reversi.o

$(OBJDIR)/main.o: main.cpp $(INCDIR)/jogador.hpp $(INCDIR)/jogo.hpp $(INCDIR)/lig4.hpp $(INCDIR)/reversi.hpp
	g++ -Wall -std=c++11 -c main.cpp -o $(OBJDIR)/main.o

clean:
	$(RM) $(OBJDIR)$(BAR)*.o $(EXE)

.PHONY: all clean
