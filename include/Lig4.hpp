#ifndef LIG4_HPP
#define LIG4_HPP

#include "./jogo.hpp"
#include "./jogador.hpp"
#include <vector>
#include <iostream>


using namespace std;

class Lig4 : public jogo{    
public:
    vector<jogador> jogadores; 
    Lig4(jogador, jogador);
    bool jogada_valida(int);
    void realizar_jogada();
    //nao precisa da funcao imprime_tabuleiro
};

#endif