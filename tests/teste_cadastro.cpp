#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_MULTITHREADING


#include "doctest.h"
#include "../include/cadastro.hpp"
#include <fstream>

// Função auxiliar para remover o arquivo de dados antes de cada teste
void remove_dados_anteriores() {
    std::remove("dados.txt");
}

// Testando o construtor cadastro
TEST_CASE("Cadastro: Construtor e Carregamento de Dados") {
    remove_dados_anteriores();
    
    cadastro c;

    // Verifica se o vetor de jogadores está vazio quando não há dados
    CHECK(c.jogadores.size() == 0);

    // Adiciona um jogador manualmente ao arquivo e carrega os dados
    std::ofstream arquivo("dados.txt");
    arquivo << "Alice A 5 2 3 1" << std::endl;
    arquivo.close();

    cadastro c2;
    CHECK(c2.jogadores.size() == 1);
    CHECK(c2.jogadores[0].nome == "Alice");
    CHECK(c2.jogadores[0].apelido == "A");
    CHECK(c2.jogadores[0].vitorias_reversi == 5);
    CHECK(c2.jogadores[0].derrotas_reversi == 2);
    CHECK(c2.jogadores[0].vitorias_lig4 == 3);
    CHECK(c2.jogadores[0].derrotas_lig4 == 1);
}

// Testando a função cadastrar_jogador
TEST_CASE("Cadastro: Cadastrar Jogador") {
    remove_dados_anteriores();
    
    cadastro c;
    c.cadastrar_jogador("A", "Alice");
    CHECK(c.jogadores.size() == 1);
    CHECK(c.jogadores[0].nome == "Alice");
    CHECK(c.jogadores[0].apelido == "A");

    // Tenta cadastrar o mesmo jogador novamente
    c.cadastrar_jogador("A", "Alice");
    CHECK(c.jogadores.size() == 1); // Verifica se o tamanho não mudou
}

// Testando a função remover_jogador
TEST_CASE("Cadastro: Remover Jogador") {
    remove_dados_anteriores();
    
    cadastro c;
    c.cadastrar_jogador("A", "Alice");
    c.remover_jogador("A");

    CHECK(c.jogadores.size() == 0); // Verifica se o jogador foi removido
    c.remover_jogador("B"); // Tentativa de remover jogador inexistente
    CHECK(c.jogadores.size() == 0); // Verifica se o tamanho não mudou
}

// Testando a função listar_jogadores
TEST_CASE("Cadastro: Listar Jogadores") {
    remove_dados_anteriores();
    
    cadastro c;
    c.cadastrar_jogador("A", "Alice");
    c.cadastrar_jogador("B", "Bob");

    // Redireciona o cout para uma stringstream para capturar a saída
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    c.listar_jogadores();

    // Volta o cout ao normal
    std::cout.rdbuf(prevcoutbuf);

    std::string output = buffer.str();
    CHECK(output.find("A Alice") != std::string::npos);
    CHECK(output.find("B Bob") != std::string::npos);
}

// Testando as funções salvar_dados e carregar_dados
TEST_CASE("Cadastro: Salvar e Carregar Dados") {
    remove_dados_anteriores();
    
    cadastro c;
    c.cadastrar_jogador("A", "Alice");
    c.cadastrar_jogador("B", "Bob");
    c.salvar_dados();

    cadastro c2;
    c2.carregar_dados();

    CHECK(c2.jogadores.size() == 2);
    CHECK(c2.jogadores[0].nome == "Alice");
    CHECK(c2.jogadores[1].nome == "Bob");
}


