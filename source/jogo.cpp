/**
 * @file jogo.cpp
 * @brief Implementação da classe base `jogo`, que define a estrutura inicial para jogos com tabuleiros.
 */

#include "../include/jogo.hpp"

/**
 * @brief Construtor da classe `jogo`.
 * 
 * Inicializa um tabuleiro com 8x8 posições, preenchido com zeros. Lança uma exceção caso a alocação do tabuleiro falhe.
 * 
 * @throw std::runtime_error Se a alocação do tabuleiro falhar.
 */
jogo::jogo() {
    try {
        this->linhas = 8;
        this->colunas = 8;
        this->tabuleiro.resize(linhas);
        for (int i = 0; i < linhas; i++) {
            this->tabuleiro[i].resize(colunas, 0);
        }
        // Verifique se a alocação do tabuleiro foi bem-sucedida
        if (this->tabuleiro.empty()) {
            throw std::runtime_error("Falha na alocação do tabuleiro.");
        }
    } catch (const std::exception &e) {
        std::cerr << "Erro na inicialização do jogo: " << e.what() << std::endl;
        throw; // Re-lançar a exceção para tratamento externo, se necessário
    }
}
