#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>

using namespace std;

class jogador {
    public:
        string nome;
        string apelido;
        int vitorias_reversi;
        int derrotas_reversi;
        int vitorias_lig4;
        int derrotas_lig4;

        jogador(string nome, string apelido);
        void ganhador_reversi();
        void perdedor_reversi();
        void ganhador_lig4();
        void perdedor_lig4();
};

#endif