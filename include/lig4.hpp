#ifndef LIG4_HPP
#define LIG4_HPP

#include "./jogo.hpp"
#include "./jogador.hpp"
#include <utility>
#include <vector>
#include <iostream>


using namespace std;

class Lig4 : public jogo{    
public:
    pair<jogador,jogador> jogadores; 
    Lig4(jogador, jogador);
    bool jogada_valida(int);
    jogador* jogar();
    //nao precisa da funcao imprime_tabuleiro

    bool verificar_vertical(int,int);

    bool verificar_horizontal(int,int);

    bool verificar_diagonal(int, int);

    bool verificar_vitoria(int, int);
    
};

#endif