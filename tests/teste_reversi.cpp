#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_MULTITHREADING

#include "doctest.h"
#include "../include/Reversi.hpp"

// Testando o construtor Reversi
TEST_CASE("Reversi: Construtor") {
    Reversi jogo;

    // Verifica se o tabuleiro foi inicializado corretamente
    CHECK(jogo.get_tabuleiro()[3][3] == 'W');
    CHECK(jogo.get_tabuleiro()[4][4] == 'W');
    CHECK(jogo.get_tabuleiro()[3][4] == 'B');
    CHECK(jogo.get_tabuleiro()[4][3] == 'B');
}


// Testando a função encontrar_complemento_da_cor
TEST_CASE("Reversi: encontrar_complemento_da_cor") {
    Reversi jogo;

    // Verifica se as cores são alternadas corretamente
    CHECK(jogo.encontrar_complemento_da_cor('B') == 'W');
    CHECK(jogo.encontrar_complemento_da_cor('W') == 'B');
}

// Testando a função confere_vertical
TEST_CASE("Reversi: confere_vertical") {
    Reversi jogo;

    // Simula uma situação onde a jogada é válida na vertical
    jogo.set_tabuleiro(3, 3, 'B');
    jogo.set_tabuleiro(2, 3, 'W');
    jogo.set_tabuleiro(1, 3, 'W');
    jogo.set_tabuleiro(0, 3, 'B');

    CHECK(jogo.confere_vertical(2, 3, 'B') == true);
}

// Testando a função confere_horizontal
TEST_CASE("Reversi: confere_horizontal") {
    Reversi jogo;

    // Simula uma situação onde a jogada é válida na horizontal
    jogo.set_tabuleiro(3, 3, 'B');
    jogo.set_tabuleiro(3, 2, 'W');
    jogo.set_tabuleiro(3, 1, 'W');
    jogo.set_tabuleiro(3, 0, 'B');

    CHECK(jogo.confere_horizontal(3, 2, 'B') == true);
}

// Testando a função confere_diagonal
TEST_CASE("Reversi: confere_diagonal") {
    Reversi jogo;

    // Simula uma situação onde a jogada é válida na diagonal
    jogo.set_tabuleiro(3, 3, 'B');
    jogo.set_tabuleiro(2, 2, 'W');
    jogo.set_tabuleiro(1, 1, 'W');
    jogo.set_tabuleiro(0, 0, 'B');

    CHECK(jogo.confere_diagonal(2, 2, 'B') == true);
}

// Testando a função e_valido
TEST_CASE("Reversi: e_valido") {
    Reversi jogo;

    // Simula uma jogada válida
    jogo.set_tabuleiro(3, 3, 'B');
    jogo.set_tabuleiro(2, 2, 'W');
    jogo.set_tabuleiro(1, 1, 'W');
    jogo.set_tabuleiro(0, 0, 'B');

    CHECK(jogo.e_valido(2, 2, 'B') == true);
}


// Testando o método jogar
TEST_CASE("Reversi: jogar") {
    Reversi jogo;

    // Simulação simples de uma jogada
    char resultado = jogo.jogar();
    
    // Verifica se o retorno está dentro das possibilidades esperadas
    CHECK((resultado == 'B' || resultado == 'W' || resultado == 'D'));
}
