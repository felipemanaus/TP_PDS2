/**
 * @file Lig4.hpp
 * @brief Declaração da classe `Lig4`, que implementa o jogo Lig4, um jogo de tabuleiro onde dois jogadores competem para alinhar quatro peças.
 */

#ifndef LIG4_HPP
#define LIG4_HPP

#include "./jogo.hpp"
#include "./jogador.hpp"
#include <utility>

/**
 * @class Lig4
 * @brief Implementa o jogo Lig4, uma variação do jogo de tabuleiro onde dois jogadores competem para alinhar quatro peças.
 */
class Lig4 : public jogo {
    public:
        std::pair<jogador, jogador> jogadores; ///< Par de jogadores que estão jogando.

        /**
         * @brief Construtor para inicializar o jogo com dois jogadores.
         * @param jogador1 Primeiro jogador.
         * @param jogador2 Segundo jogador.
         */
        Lig4(jogador jogador1, jogador jogador2);

        /**
         * @brief Imprime o tabuleiro do jogo Lig4.
         */
        void imprimir_tabuleiro() override;

        /**
         * @brief Verifica se uma jogada é válida.
         * @param coluna Coluna onde a jogada está sendo feita.
         * @return true se a jogada for válida, false caso contrário.
         */
        bool jogada_valida(int coluna);

        /**
         * @brief Verifica se o tabuleiro está cheio.
         * @return true se o tabuleiro estiver cheio, false caso contrário.
         */
        bool verificar_tabuleiro_cheio() override;

        /**
         * @brief Executa uma jogada no jogo.
         * @return O índice do jogador vencedor ou -1 se não houver vencedor.
         */
        int jogar();

    private:
        /**
         * @brief Verifica uma condição de vitória na vertical.
         * @param linha Linha a ser verificada.
         * @param coluna Coluna a ser verificada.
         * @return true se houver uma vitória, false caso contrário.
         */
        bool verificar_vertical(int linha, int coluna);

        /**
         * @brief Verifica uma condição de vitória na horizontal.
         * @param linha Linha a ser verificada.
         * @param coluna Coluna a ser verificada.
         * @return true se houver uma vitória, false caso contrário.
         */
        bool verificar_horizontal(int linha, int coluna);

        /**
         * @brief Verifica uma condição de vitória nas diagonais.
         * @param linha Linha a ser verificada.
         * @param coluna Coluna a ser verificada.
         * @return true se houver uma vitória, false caso contrário.
         */
        bool verificar_diagonal(int linha, int coluna);

        /**
         * @brief Verifica se há uma condição de vitória em qualquer direção.
         * @param linha Linha a ser verificada.
         * @param coluna Coluna a ser verificada.
         * @return true se houver uma vitória, false caso contrário.
         */
        bool verificar_vitoria(int linha, int coluna);
};

#endif
