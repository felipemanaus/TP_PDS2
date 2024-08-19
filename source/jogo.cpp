#include "../include/jogo.hpp"

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