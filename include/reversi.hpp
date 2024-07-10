#ifndef REVERSI_HPP
#define REVERSI_HPP

using namespace std;

#include "jogo.hpp"

class reversi : public jogo {
public:
    reversi();
    ~reversi()override;

    void realizar_jogada(int linha, int coluna, int jogador) override;
    bool jogada_valida(int linha, int coluna) const override;
    void imprimir_tabuleiro()  const override;
    bool verificar_vitoria(int jogador) const override;

    vector<vector<int>> jogadas_validas (int jogador) const;

private:
    bool virar_discos(int linhas, int colunas, int jogador);
    bool esta_no_tabuleiro(int linhas, int colunas) const;


};

#endif

































#endif