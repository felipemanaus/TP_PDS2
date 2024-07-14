#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include "../include/jogador.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class cadastro {
    public:
        vector<jogador> jogadores;

        cadastro();
        void cadastrar_jogador(string apelido, string nome);
        void remover_jogador(string apelido);
        void listar_jogadores();
        void salvar_dados();
        void carregar_dados();
};

#endif