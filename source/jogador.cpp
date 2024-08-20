/**
 * @file jogador.cpp
 * @brief Implementação das funções da classe `jogador`, que gerencia as informações e estatísticas de um jogador nos jogos Reversi e Lig4.
 */

#include "../include/jogador.hpp"

/**
 * @brief Construtor padrão da classe `jogador`.
 * 
 * Inicializa o jogador com valores padrão.
 */
jogador::jogador() {
    this->nome = "default";
    this->apelido = "default";
    this->vitorias_reversi = 0;
    this->derrotas_reversi = 0;
    this->vitorias_lig4 = 0;
    this->derrotas_lig4 = 0;
}

/**
 * @brief Construtor que inicializa o jogador com nome e apelido específicos.
 * 
 * @param nome Nome completo do jogador.
 * @param apelido Apelido do jogador.
 * 
 * @throw invalid_argument Se o nome ou apelido forem vazios.
 */
jogador::jogador(string nome, string apelido) {
    if (nome.empty() || apelido.empty()) {
        throw invalid_argument("Nome e apelido não podem ser vazios.");
    }
    this->nome = nome;
    this->apelido = apelido;
    this->vitorias_reversi = 0;
    this->derrotas_reversi = 0;
    this->vitorias_lig4 = 0;
    this->derrotas_lig4 = 0;
}

/**
 * @brief Incrementa o número de vitórias no jogo Reversi.
 */
void jogador::ganhador_reversi() {
    vitorias_reversi++;
}

/**
 * @brief Incrementa o número de derrotas no jogo Reversi.
 */
void jogador::perdedor_reversi() {
    derrotas_reversi++;
}

/**
 * @brief Incrementa o número de vitórias no jogo Lig4.
 */
void jogador::ganhador_lig4() {
    vitorias_lig4++;
}

/**
 * @brief Incrementa o número de derrotas no jogo Lig4.
 */
void jogador::perdedor_lig4() {
    derrotas_lig4++;
}
