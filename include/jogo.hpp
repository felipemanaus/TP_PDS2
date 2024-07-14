#ifndef JOGO_HPP
#define JOGO_HPP

#include <vector>
#include <iostream>

using namespace std;
class jogo {
protected:
    int linhas;
    int colunas;
    vector<vector<int>> tabuleiro;

public:
    jogo ();
    virtual ~jogo() = default;
    virtual void imprimir_tabuleiro(); // tambem serve pro lig4 do msm jeito
    virtual bool verificar_tabuleiro_cheio();
};

#endif 