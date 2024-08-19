#ifndef LIG4_HPP
#define LIG4_HPP

#include "./jogo.hpp"
#include "./jogador.hpp"
#include <utility>

class Lig4 : public jogo {
    public:
        pair<jogador,jogador> jogadores; 
        Lig4(jogador, jogador);
        void imprimir_tabuleiro() override;
        bool jogada_valida(int);
        bool verificar_tabuleiro_cheio() override;
        int jogar();

        bool verificar_vertical(int, int);
        bool verificar_horizontal(int, int);
        bool verificar_diagonal(int, int);
        bool verificar_vitoria(int, int);
};

#endif