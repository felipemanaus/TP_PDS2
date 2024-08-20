/**
 * @file Reversi.hpp
 * @brief Declaração da classe `Reversi`, que implementa o jogo Reversi, onde dois jogadores competem para capturar o maior número de peças no tabuleiro.
 */

#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "./jogo.hpp"
#include "./jogador.hpp"

/**
 * @class Reversi
 * @brief Implementa o jogo Reversi, onde dois jogadores competem para capturar o maior número de peças no tabuleiro.
 */
class Reversi : public jogo {
    private:
        std::vector<std::vector<char>> tabuleiro; ///< Tabuleiro do jogo Reversi representado como uma matriz de caracteres.
        char cor_inicial;                         ///< Cor inicial do jogador que faz a primeira jogada.
        std::vector<int> jogadas_possiveis_linha; ///< Vetor que armazena as linhas das jogadas possíveis.
        std::vector<int> jogadas_possiveis_coluna;///< Vetor que armazena as colunas das jogadas possíveis.

    public:
        std::vector<jogador> jogadores;           ///< Vetor que armazena os jogadores participantes.

        /**
         * @brief Construtor padrão do jogo Reversi.
         */
        Reversi();

        /**
         * @brief Imprime o tabuleiro do jogo Reversi.
         */
        void imprimir_tabuleiro() override;

        /**
         * @brief Verifica se o tabuleiro está cheio.
         * @return true se o tabuleiro estiver cheio, false caso contrário.
         */
        bool verificar_tabuleiro_cheio() override;

        /**
         * @brief Encontra a cor oposta à cor fornecida.
         * @param cor Cor atual.
         * @return A cor complementar.
         */
        char encontrar_complemento_da_cor(char cor);

        /**
         * @brief Conta os pontos de cada jogador com base no tabuleiro atual.
         */
        void contagem_pontos();

        /**
         * @brief Verifica se há capturas possíveis na vertical.
         * @param linha Linha da jogada.
         * @param coluna Coluna da jogada.
         * @param cor Cor do jogador.
         * @return true se houver capturas, false caso contrário.
         */
        bool confere_vertical(int linha, int coluna, char cor);

        /**
         * @brief Verifica se há capturas possíveis na horizontal.
         * @param linha Linha da jogada.
         * @param coluna Coluna da jogada.
         * @param cor Cor do jogador.
         * @return true se houver capturas, false caso contrário.
         */
        bool confere_horizontal(int linha, int coluna, char cor);

        /**
         * @brief Verifica se há capturas possíveis nas diagonais.
         * @param linha Linha da jogada.
         * @param coluna Coluna da jogada.
         * @param cor Cor do jogador.
         * @return true se houver capturas, false caso contrário.
         */
        bool confere_diagonal(int linha, int coluna, char cor);

        /**
         * @brief Verifica se uma jogada é válida.
         * @param linha Linha da jogada.
         * @param coluna Coluna da jogada.
         * @param cor Cor do jogador.
         * @return true se a jogada for válida, false caso contrário.
         */
        bool e_valido(int linha, int coluna, char cor);

        /**
         * @brief Calcula e armazena as jogadas possíveis para uma cor específica.
         * @param cor Cor do jogador.
         */
        void jogadas_possiveis(char cor);

        /**
         * @brief Imprime as jogadas possíveis no tabuleiro.
         */
        void imprime_jogadas_possiveis();

        /**
         * @brief Marca as jogadas possíveis no tabuleiro.
         */
        void marca_as_jogadas_possiveis_no_tabuleiro();

        /**
         * @brief Desmarca as jogadas possíveis do tabuleiro.
         */
        void desmarca_as_jogadas_possiveis_do_tabuleiro();

        /**
         * @brief Inverte as peças na vertical para uma jogada específica.
         * @param linha Linha da jogada.
         * @param coluna Coluna da jogada.
         * @param cor Cor do jogador.
         * @return Novo estado do tabuleiro após a inversão.
         */
        std::vector<std::vector<char>> inversao_da_cor_vertical(int linha, int coluna, char cor);

        /**
         * @brief Inverte as peças na horizontal para uma jogada específica.
         * @param linha Linha da jogada.
         * @param coluna Coluna da jogada.
         * @param cor Cor do jogador.
         * @return Novo estado do tabuleiro após a inversão.
         */
        std::vector<std::vector<char>> inversao_da_cor_horizontal(int linha, int coluna, char cor);

        /**
         * @brief Inverte as peças nas diagonais para uma jogada específica.
         * @param linha Linha da jogada.
         * @param coluna Coluna da jogada.
         * @param cor Cor do jogador.
         * @return Novo estado do tabuleiro após a inversão.
         */
        std::vector<std::vector<char>> inversao_da_cor_diagonal(int linha, int coluna, char cor);

        /**
         * @brief Verifica se há um vencedor com base no estado atual do tabuleiro.
         * @return Cor do jogador vencedor, ou vazio se não houver vencedor.
         */
        char verificar_vitoria();

        /**
         * @brief Executa o jogo até o final, alternando entre os jogadores.
         * @return Cor do jogador vencedor ou vazio se o jogo empatar.
         */
        char jogar();
};

#endif
