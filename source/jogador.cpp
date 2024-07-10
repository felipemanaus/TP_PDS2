#include "jogador.hpp"

jogador::jogador (string nome , string apelido){
    this->nome = nome;
    this->apelido = apelido;
    this->quantidade_vitorias = 0;
    this->quantidade_derrotas = 0;
}

void jogador::aumenta_vitorias (){
    this->quantidade_vitorias++;
}

void jogador::aumenta_derrotas (){
    this->quantidade_derrotas++;
}

string jogador::get_apelido() const {
    return this->apelido;
}