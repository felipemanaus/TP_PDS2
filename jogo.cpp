#include "jogo.hpp"

jogo::jogo (int linhas, int colunas){
    this->linhas = linhas;
    this->colunas = colunas;
    this->tabuleiro.resize(linhas);
    for (int i=0; i<linhas; i++){
        this->tabuleiro[i].resize(colunas, 0);
    }
}