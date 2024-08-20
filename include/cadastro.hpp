/**
 * @file cadastro.hpp
 * @brief Declaração da classe `cadastro`, responsável por gerenciar o cadastro de jogadores, incluindo operações de adição, remoção, listagem e persistência de dados.
 */

#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include "../include/jogador.hpp"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/**
 * @class cadastro
 * @brief Gerencia o cadastro de jogadores, permitindo adicionar, remover, listar e salvar os dados.
 */
class cadastro {
    private:
        std::vector<jogador> jogadores; ///< Vetor que armazena os jogadores cadastrados.

    public:
        /**
         * @brief Construtor padrão da classe cadastro.
         */
        cadastro();

        /**
         * @brief Cadastra um novo jogador.
         * @param apelido Apelido do jogador.
         * @param nome Nome completo do jogador.
         */
        void cadastrar_jogador(string apelido, string nome);

        /**
         * @brief Remove um jogador do cadastro.
         * @param apelido Apelido do jogador a ser removido.
         */
        void remover_jogador(string apelido);

        /**
         * @brief Lista todos os jogadores cadastrados.
         */
        void listar_jogadores();

        /**
         * @brief Salva os dados dos jogadores em um arquivo.
         */
        void salvar_dados();

        /**
         * @brief Carrega os dados dos jogadores de um arquivo.
         */
        void carregar_dados();

        /**
         * @brief Procura por um jogador pelo apelido.
         * @param apelido Apelido do jogador a ser procurado.
         * @return Ponteiro para o jogador encontrado, ou nullptr se não encontrado.
         */
        jogador* procurar_apelido(string apelido);
};

#endif
