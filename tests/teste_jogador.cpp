#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_MULTITHREADING

#include "doctest.h"
#include "../include/jogador.hpp"

// Testando o construtor padrão jogador()
TEST_CASE("Jogador: Construtor padrão") {
    jogador j;
    
    // Verifica se os atributos são inicializados corretamente com os valores padrão
    CHECK(j.nome == "default");
    CHECK(j.apelido == "default");
    CHECK(j.vitorias_reversi == 0);
    CHECK(j.derrotas_reversi == 0);
    CHECK(j.vitorias_lig4 == 0);
    CHECK(j.derrotas_lig4 == 0);
}

// Testando o construtor com parâmetros jogador(string nome, string apelido)
TEST_CASE("Jogador: Construtor com parâmetros") {
    jogador j("Alice", "A");
    
    // Verifica se os atributos são inicializados corretamente com os valores fornecidos
    CHECK(j.nome == "Alice");
    CHECK(j.apelido == "A");
    CHECK(j.vitorias_reversi == 0);
    CHECK(j.derrotas_reversi == 0);
    CHECK(j.vitorias_lig4 == 0);
    CHECK(j.derrotas_lig4 == 0);
}

// Testando a função ganhador_reversi
TEST_CASE("Jogador: ganhador_reversi") {
    jogador j("Alice", "A");
    j.ganhador_reversi();
    
    // Verifica se a vitória no Reversi foi registrada corretamente
    CHECK(j.vitorias_reversi == 1);
}

// Testando a função perdedor_reversi
TEST_CASE("Jogador: perdedor_reversi") {
    jogador j("Alice", "A");
    j.perdedor_reversi();
    
    // Verifica se a derrota no Reversi foi registrada corretamente
    CHECK(j.derrotas_reversi == 1);
}

// Testando a função ganhador_lig4
TEST_CASE("Jogador: ganhador_lig4") {
    jogador j("Alice", "A");
    j.ganhador_lig4();
    
    // Verifica se a vitória no Lig4 foi registrada corretamente
    CHECK(j.vitorias_lig4 == 1);
}

// Testando a função perdedor_lig4
TEST_CASE("Jogador: perdedor_lig4") {
    jogador j("Alice", "A");
    j.perdedor_lig4();
    
    // Verifica se a derrota no Lig4 foi registrada corretamente
    CHECK(j.derrotas_lig4 == 1);
}
