#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include "../include/jogador.hpp"
#include <iostream>
#include <vector>
#include <fstream>

class cadastro {
    private:
        vector<jogador> jogadores;

    public:
        cadastro();
        void cadastrar_jogador(string apelido, string nome);
        void remover_jogador(string apelido);
        void listar_jogadores();
        void salvar_dados();
        void carregar_dados();
        jogador* procurar_apelido(string apelido);
};

#endif