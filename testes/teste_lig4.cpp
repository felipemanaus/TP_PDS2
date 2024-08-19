#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_MULTITHREADING

#include "doctest.h"
#include "../include/lig4.hpp"
#include "../include/jogador.hpp"

// Testando o construtor Lig4
TEST_CASE("Lig4: Construtor") {
    jogador j1("Alice", "A");
    jogador j2("Bob", "B");
    Lig4 jogo(j1, j2);
    
    CHECK(jogo.jogadores.first.nome == "Alice");
    CHECK(jogo.jogadores.second.nome == "Bob");
}

// Testando a função jogada_valida
TEST_CASE("Lig4: jogada_valida") {
    jogador j1("Alice", "A");
    jogador j2("Bob", "B");
    Lig4 jogo(j1, j2);
    
    CHECK(jogo.jogada_valida(0) == true);
    CHECK(jogo.jogada_valida(-1) == false);
    CHECK(jogo.jogada_valida(7) == false);
}

// Testando a função verificar_vitoria (corrigido)
TEST_CASE("Lig4: verificar_vitoria") {
    jogador j1("Alice", "A");
    jogador j2("Bob", "B");
    Lig4 jogo(j1, j2);

    // Simula jogadas para criar uma situação de vitória
    jogo.jogada_valida(0); jogo.jogar();  // Jogada 1
    jogo.jogada_valida(0); jogo.jogar();  // Jogada 2
    jogo.jogada_valida(0); jogo.jogar();  // Jogada 3
    jogo.jogada_valida(0); jogo.jogar();  // Jogada 4
    
    // Agora verifica se há vitória na coluna 0
    CHECK(jogo.verificar_vitoria(3, 0) == true);
}

// Testando o método jogar
TEST_CASE("Lig4: jogar") {
    jogador j1("Alice", "A");
    jogador j2("Bob", "B");
    Lig4 jogo(j1, j2);

    // Simulando uma jogada
    int resultado = jogo.jogar();
    
    // Verifica se o resultado é um código válido
    CHECK((resultado == 'X' || resultado == 'O' || resultado == 0));
}
