/**
 * @file main.cpp
 * @brief Ponto de entrada para o sistema de gerenciamento de jogadores e execução de partidas dos jogos Reversi e Lig4.
 */

#include "include/cadastro.hpp"
#include "include/jogador.hpp"
#include "include/jogo.hpp"
#include "include/lig4.hpp"
#include "include/reversi.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * @brief Função principal do sistema.
 * 
 * Exibe um menu para o usuário, permitindo cadastrar jogadores, remover jogadores, listar jogadores, 
 * executar partidas de Reversi ou Lig4, e finalizar o sistema.
 * 
 * @return int Retorna 0 ao finalizar o sistema.
 */
int main() {
    try {
        cadastro cadastro;
        string entrada;

        while(true) {
            system("cls");
            cout << "Digite uma das entradas:" << endl;
            cout << "CJ(Cadastrar Jogador)" << endl;
            cout << "RJ(Remover Jogador)" << endl;
            cout << "LJ(Listar Jogadores)" << endl;
            cout << "EP(Executar Partida)" << endl;
            cout << "FS(Finalizar Sistema)" << endl;
            cout << endl;
            cin >> entrada;

            if(entrada == "CJ") {
                string apelido, nome;
                cout << "Digite o apelido e o nome:" << endl;
                cout << "<Apelido> <Nome>" << endl;
                cin >> apelido >> nome;
                try {
                    cadastro.cadastrar_jogador(apelido, nome);
                } catch(const exception& e) {
                    cerr << "Erro ao cadastrar jogador: " << e.what() << endl;
                }
            }

            if(entrada == "RJ") {
                string apelido;
                cout << "Digite o apelido:" << endl;
                cout << "<Apelido>" << endl;
                cin >> apelido;
                try {
                    cadastro.remover_jogador(apelido);
                } catch(const exception& e) {
                    cerr << "Erro ao remover jogador: " << e.what() << endl;
                }
            }

            if(entrada == "LJ") {
                try {
                    cadastro.listar_jogadores();
                } catch(const exception& e) {
                    cerr << "Erro ao listar jogadores: " << e.what() << endl;
                }
            }

            if(entrada == "EP") {
                string jogo, um, dois;
                cout << "Digite o jogo e os apelidos dos dois jogadores:" << endl;
                cout << "<Jogo: (R|L)> <Apelido Jogador 1> <Apelido Jogador 2>" << endl;
                cin >> jogo >> um >> dois;

                try {
                    if(um == dois) {
                        throw invalid_argument("Os jogadores não podem ser iguais.");
                    }

                    jogador* p1 = cadastro.procurar_apelido(um);
                    jogador* p2 = cadastro.procurar_apelido(dois);

                    if(!p1 || !p2) {
                        throw invalid_argument("Um ou ambos os jogadores não foram encontrados.");
                    }

                    if(jogo == "L") {
                        Lig4 l(*p1, *p2);
                        int aux = l.jogar();

                        if(aux == 1) {
                            p1->ganhador_lig4();
                            p2->perdedor_lig4();
                        }
                                            
                        if(aux == 2) {
                            p1->perdedor_lig4();
                            p2->ganhador_lig4();
                        }
                    }

                    if(jogo == "R") {
                        Reversi r;
                        char aux = r.jogar();

                        if(aux == 'W') {
                            p1->ganhador_reversi();
                            p2->perdedor_reversi();
                        }
                                    
                        if(aux == 'B') {
                            p1->perdedor_reversi();
                            p2->ganhador_reversi();
                        }

                        char caractere;
                        cout << endl << endl << "Digite qualquer caractere e depois pressione a tecla ENTER para voltar a tela inicial:" << endl;
                        cin >> caractere;
                    }

                    cadastro.salvar_dados();
                } catch(const exception& e) {
                    cerr << "Erro ao executar a partida: " << e.what() << endl;
                }
            }

            if(entrada == "FS") {
                return 0;
            }
        }
    } catch(const exception& e) {
        cerr << "Erro no sistema: " << e.what() << endl;
        return 1;
    }
}
