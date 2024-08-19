#include "../include/jogo.hpp"

jogo::jogo (){
    this->linhas = 8;
    this->colunas = 8;
    this->tabuleiro.resize(linhas);
    for (int i=0; i<linhas; i++){
        this->tabuleiro[i].resize(colunas, 0);
    }
}