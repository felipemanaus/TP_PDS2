#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_MULTITHREADING

#include <sstream>
#include <string>
#include "doctest.h"
#include "../include/jogo.hpp"



// Testando a função imprimir_tabuleiro
TEST_CASE("Jogo: Imprimir Tabuleiro") {
    jogo j;

    // Redireciona o cout para uma stringstream para capturar a saída
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // Imprime o tabuleiro
    j.imprimir_tabuleiro();

    // Volta o cout ao normal
    std::cout.rdbuf(prevcoutbuf);

    // Testa se a saída gerada contém os índices das colunas e linhas corretamente
    std::string output = buffer.str();
    CHECK(output.find("0   1   2   3   4   5   6   7") != std::string::npos);
    CHECK(output.find("|0   0   0   0   0   0   0   0") != std::string::npos);
}

// Testando a função verificar_tabuleiro_cheio
TEST_CASE("Jogo: Verificar Tabuleiro Cheio") {
    jogo j;

    // Testa quando o tabuleiro está vazio
    CHECK(j.verificar_tabuleiro_cheio() == false);

}
