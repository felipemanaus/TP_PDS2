/**
 * @file jogador.hpp
 * @brief Declaração da classe `jogador`, que representa as informações básicas de um jogador, como nome, apelido, vitórias e derrotas em diferentes jogos.
 */

#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * @class jogador
 * @brief Representa um jogador, armazenando seu nome, apelido e o número de vitórias e derrotas em diferentes jogos.
 */
class jogador {
    public:
        string nome;               ///< Nome completo do jogador.
        string apelido;            ///< Apelido do jogador.
        int vitorias_reversi;      ///< Número de vitórias no jogo Reversi.
        int derrotas_reversi;      ///< Número de derrotas no jogo Reversi.
        int vitorias_lig4;         ///< Número de vitórias no jogo Lig4.
        int derrotas_lig4;         ///< Número de derrotas no jogo Lig4.

    public:
        /**
         * @brief Construtor padrão da classe jogador.
         */
        jogador();

        /**
         * @brief Construtor que inicializa o jogador com nome e apelido.
         * @param nome Nome completo do jogador.
         * @param apelido Apelido do jogador.
         */
        jogador(string nome, string apelido);

        /**
         * @brief Incrementa o número de vitórias no jogo Reversi.
         */
        void ganhador_reversi();

        /**
         * @brief Incrementa o número de derrotas no jogo Reversi.
         */
        void perdedor_reversi();

        /**
         * @brief Incrementa o número de vitórias no jogo Lig4.
         */
        void ganhador_lig4();

        /**
         * @brief Incrementa o número de derrotas no jogo Lig4.
         */
        void perdedor_lig4();
};

#endif
