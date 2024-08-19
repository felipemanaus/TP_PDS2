#include "../include/cadastro.hpp"

cadastro::cadastro() {
    carregar_dados();
}

void cadastro::cadastrar_jogador(string apelido, string nome) {
    for(auto& i : jogadores) {
        if(i.apelido == apelido) {
            cout << "ERRO: jogador repetido" << endl;
            return;
        }
    }
    jogadores.push_back(jogador(nome, apelido));
    salvar_dados();
    cout << "Jogador " << apelido << " cadastrado com sucesso" << endl;
}

void cadastro::remover_jogador(string apelido) {
    int aux = -1;
    for(auto& i : jogadores) {
        aux++;
        if(i.apelido == apelido) {
            jogadores.erase(jogadores.begin() + aux);
            salvar_dados();
            cout << "Jogador " << apelido << " removido com sucesso" << endl;
            return;
        }
    }
    cout << "ERRO: jogador inexistente" << endl;
}

void cadastro::listar_jogadores() {
    for(auto& i : jogadores) {
        cout << i.apelido << " " << i.nome << endl;
        cout << "REVERSI - V: " << i.vitorias_reversi << " D: " << i.derrotas_reversi << endl;
        cout << "LIG4    - V: " << i.vitorias_lig4 << " D: " << i.derrotas_lig4 << endl;
    }

    char caractere;
    cout << endl << endl << "Digite qualquer caractere e depois pressione a tecla ENTER para voltar a tela inicial:" << endl;
    cin >> caractere;
}

void cadastro::salvar_dados() {
    ofstream arquivo("dados.txt");
    for(auto& i : jogadores) {
        arquivo << i.nome << " " << i.apelido << " "
                << i.vitorias_reversi << " " << i.derrotas_reversi << " "
                << i.vitorias_lig4 << " " << i.derrotas_lig4 << endl;
    }
    arquivo.close();
}

void cadastro::carregar_dados() {
    ifstream arquivo("dados.txt");
    if(!arquivo.is_open()) return;

    string nome, apelido;
    int vitorias_reversi, derrotas_reversi, vitorias_lig4, derrotas_lig4;
    while(arquivo >> nome >> apelido >> vitorias_reversi >> derrotas_reversi >> vitorias_lig4 >> derrotas_lig4) {
        jogador i(nome, apelido);
        i.vitorias_reversi = vitorias_reversi;
        i.derrotas_reversi = derrotas_reversi;
        i.vitorias_lig4 = vitorias_lig4;
        i.derrotas_lig4 = derrotas_lig4;
        jogadores.push_back(i);
    }
    arquivo.close();
}