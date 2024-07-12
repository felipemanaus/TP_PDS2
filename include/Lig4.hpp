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

    bool checador_vertical (int,int);
    bool verificar_vertical(int,int);

    bool checador_horizontal(int,int);
    bool verificar_horizontal(int,int);

    bool checar_diagonal_descendo_direita(int,int);
    bool verificar_diagonal_subindo_esquerda(int,int);

    bool checar_diagonal_descendo_esquerda(int,int);
    bool verificar_diagonal_subindo_direita(int,int);


    bool verificar_vitoria(int, int);
    
};

#endif