/**
 * @file cadastro.cpp
 * @brief Implementação das funções da classe `cadastro` para gerenciar o cadastro de jogadores, incluindo operações de cadastro, remoção, listagem e persistência de dados.
 */

#include "../include/cadastro.hpp"

/**
 * @brief Construtor da classe `cadastro`.
 * 
 * Tenta carregar os dados do arquivo ao instanciar a classe.
 */
cadastro::cadastro() {
    try {
        carregar_dados();
    } catch (const exception& e) {
        cout << "Erro ao carregar dados: " << e.what() << endl;
    }
}

/**
 * @brief Cadastra um novo jogador.
 * 
 * Verifica se o apelido já existe, adiciona o jogador ao vetor e salva os dados.
 * 
 * @param apelido Apelido do jogador.
 * @param nome Nome completo do jogador.
 */
void cadastro::cadastrar_jogador(string apelido, string nome) {
    try {
        for(auto& i : jogadores) {
            if(i.apelido == apelido) {
                throw runtime_error("ERRO: jogador repetido");
            }
        }
        jogadores.push_back(jogador(nome, apelido));
        salvar_dados();
        cout << "Jogador " << apelido << " cadastrado com sucesso" << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}

/**
 * @brief Remove um jogador do cadastro.
 * 
 * Procura pelo apelido e remove o jogador correspondente. Salva os dados atualizados.
 * 
 * @param apelido Apelido do jogador a ser removido.
 */
void cadastro::remover_jogador(string apelido) {
    try {
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
        throw runtime_error("ERRO: jogador inexistente");
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}

/**
 * @brief Lista todos os jogadores cadastrados.
 * 
 * Exibe o apelido, nome e o número de vitórias e derrotas em Reversi e Lig4 para cada jogador.
 */
void cadastro::listar_jogadores() {
    try {
        for(auto& i : jogadores) {
            cout << i.apelido << " " << i.nome << endl;
            cout << "REVERSI - V: " << i.vitorias_reversi << " D: " << i.derrotas_reversi << endl;
            cout << "LIG4    - V: " << i.vitorias_lig4 << " D: " << i.derrotas_lig4 << endl;
        }

        char caractere;
        cout << endl << "Digite qualquer caractere e depois pressione a tecla ENTER para voltar a tela inicial:" << endl;
        cin >> caractere;
    } catch (const exception& e) {
        cout << "Erro ao listar jogadores: " << e.what() << endl;
    }
}

/**
 * @brief Salva os dados dos jogadores em um arquivo.
 * 
 * Salva os dados de todos os jogadores cadastrados em um arquivo de texto.
 */
void cadastro::salvar_dados() {
    try {
        ofstream arquivo("dados.txt");
        if(!arquivo.is_open()) {
            throw runtime_error("Erro ao abrir o arquivo para salvar dados.");
        }
        for(auto& i : jogadores) {
            arquivo << i.nome << " " << i.apelido << " "
                    << i.vitorias_reversi << " " << i.derrotas_reversi << " "
                    << i.vitorias_lig4 << " " << i.derrotas_lig4 << endl;
        }
        arquivo.close();
    } catch (const exception& e) {
        cout << e.what() << endl;
        throw; // Propaga a exceção
    }
}

/**
 * @brief Carrega os dados dos jogadores de um arquivo.
 * 
 * Lê os dados de um arquivo de texto e os carrega no vetor de jogadores.
 */
void cadastro::carregar_dados() {
    try {
        ifstream arquivo("dados.txt");
        if(!arquivo.is_open()) {
            throw runtime_error("Erro ao abrir o arquivo para carregar dados.");
        }

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
    } catch (const exception& e) {
        cout << "Erro ao carregar dados: " << e.what() << endl;
        throw; // Propaga a exceção
    }
}

/**
 * @brief Procura por um jogador pelo apelido.
 * 
 * Retorna um ponteiro para o jogador encontrado ou nullptr se não encontrado.
 * 
 * @param apelido Apelido do jogador a ser procurado.
 * @return Ponteiro para o jogador ou nullptr se não encontrado.
 */
jogador* cadastro::procurar_apelido(string apelido) {
    try {
        for(auto& it : jogadores) {
            if(it.apelido == apelido) {
                return &it;
            }
        }
        throw runtime_error("ERRO: Jogador não cadastrado.");
    } catch (const exception& e) {
        cout << e.what() << endl;
        return nullptr;
    }
}
