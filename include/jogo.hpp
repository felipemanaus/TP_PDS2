/**
 * @file jogo.hpp
 * @brief Declaração da classe base abstrata `jogo`, que define a estrutura para jogos com tabuleiros, incluindo métodos para impressão e verificação do tabuleiro.
 */

#ifndef JOGO_HPP
#define JOGO_HPP

#include <iostream>
#include <vector>

using namespace std;

/**
 * @class jogo
 * @brief Classe base abstrata que representa um jogo genérico com um tabuleiro.
 * 
 * Esta classe fornece a estrutura básica para um jogo que envolve um tabuleiro, 
 * com métodos para imprimir o tabuleiro e verificar se ele está cheio. 
 * Classes derivadas devem implementar os métodos virtuais.
 */
class jogo {
    protected:
        int linhas;                        ///< Número de linhas do tabuleiro.
        int colunas;                       ///< Número de colunas do tabuleiro.
        vector<vector<int>> tabuleiro;     ///< Representação do tabuleiro como uma matriz bidimensional.

    public:
        /**
         * @brief Construtor padrão da classe jogo.
         */
        jogo();

        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~jogo() = default;

        /**
         * @brief Imprime o tabuleiro do jogo.
         * 
         * Este método é puramente virtual e deve ser implementado pelas classes derivadas.
         */
        virtual void imprimir_tabuleiro() = 0;

        /**
         * @brief Verifica se o tabuleiro está cheio.
         * 
         * Este método é puramente virtual e deve ser implementado pelas classes derivadas.
         * @return true se o tabuleiro estiver cheio, false caso contrário.
         */
        virtual bool verificar_tabuleiro_cheio() = 0;
};

#endif

