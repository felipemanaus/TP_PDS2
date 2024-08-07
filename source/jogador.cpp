#include "../include/jogador.hpp"

jogador::jogador(){
    this->nome = "default";
    this->apelido = "default";
    this->vitorias_reversi = 0;
    this->derrotas_reversi = 0;
    this->vitorias_lig4 = 0;
    this->derrotas_lig4 = 0;
}

jogador::jogador(string nome, string apelido) {
    this->nome = nome;
    this->apelido = apelido;
    this->vitorias_reversi = 0;
    this->derrotas_reversi = 0;
    this->vitorias_lig4 = 0;
    this->derrotas_lig4 = 0;
}

void jogador::ganhador_reversi() {
    vitorias_reversi++;
}

void jogador::perdedor_reversi() {
    derrotas_reversi++;
}

void jogador::ganhador_lig4() {
    vitorias_lig4++;
}

void jogador::perdedor_lig4() {
    derrotas_lig4++;
}