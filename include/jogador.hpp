#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class jogador {
    public:
        string nome;
        string apelido;
        int vitorias_reversi;
        int derrotas_reversi;
        int vitorias_lig4;
        int derrotas_lig4;

    public:
        jogador();
        jogador(string nome, string apelido);
        void ganhador_reversi();
        void perdedor_reversi();
        void ganhador_lig4();
        void perdedor_lig4();
};

#endif