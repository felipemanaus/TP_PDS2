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
    bool verificar_vitoria(int, int);
    
private:
    bool verificar_vitoria_horizontal(int);
    bool verificar_vitoria_vertical(int);
    bool verificar_vitoria_diagonal(int, int);
};

#endif