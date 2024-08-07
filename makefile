ifeq ($(OS), Windows_NT)
    RM = del
    BAR = "\"
    EXE = main.exe
else
    RM = rm -f
    BAR = /
    EXE = main
endif

all: obj main

main: obj/cadastro.o obj/jogador.o obj/jogo.o obj/lig4.o obj/reversi.o obj/main.o
	g++ -Wall -std=c++11 -o $(EXE) obj/cadastro.o obj/jogador.o obj/jogo.o obj/lig4.o obj/reversi.o obj/main.o

obj/cadastro.o: source/cadastro.cpp include/cadastro.hpp
	g++ -Wall -std=c++11 -c source/cadastro.cpp -o obj/cadastro.o

obj/jogador.o: source/jogador.cpp include/jogador.hpp
	g++ -Wall -std=c++11 -c source/jogador.cpp -o obj/jogador.o

obj/jogo.o: source/jogo.cpp include/jogo.hpp
	g++ -Wall -std=c++11 -c source/jogo.cpp -o obj/jogo.o

obj/lig4.o: source/lig4.cpp include/lig4.hpp
	g++ -Wall -std=c++11 -c source/lig4.cpp -o obj/lig4.o

obj/reversi.o: source/reversi.cpp include/reversi.hpp
	g++ -Wall -std=c++11 -c source/reversi.cpp -o obj/reversi.o

obj/main.o: main.cpp include/cadastro.hpp include/jogador.hpp include/jogo.hpp include/lig4.hpp include/reversi.hpp
	g++ -Wall -std=c++11 -c main.cpp -o obj/main.o

clean:
	$(RM) obj$(BAR)*.o $(EXE)