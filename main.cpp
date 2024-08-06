#include "include/cadastro.hpp"
#include "include/jogador.hpp"
#include "include/jogo.hpp"
#include "include/lig4.hpp"
#include "include/reversi.hpp"

int main() {
    cadastro cadastro;
    string entrada;

    while(true) {
        cout << "Digite uma das entradas:" << endl;
        cout << "CJ ou Cadastrar Jogador" << endl;
        cout << "RJ ou Remover Jogador" << endl;
        cout << "LJ ou Listar Jogadores" << endl;
        cout << "EP ou Executar Partida" << endl;
        cout << "FS ou Finalizar Sistema" << endl;
        cout << "<string>" << endl;
        // A parte de digitar duas palavras ainda não está implementada (stringstream)

        cin >> entrada;

        if(entrada == "CJ" || entrada == "Cadastrar Jogador") {
            cout << "Digite o apelido e o nome:" << endl;
            cout << "<Apelido> <Nome>" << endl;
            string apelido, nome;
            cin >> apelido >> nome;
            cadastro.cadastrar_jogador(apelido, nome);
        }

        if(entrada == "RJ" || entrada == "Remover Jogador") {
            cout << "Digite o apelido:" << endl;
            cout << "<Apelido>" << endl;
            string apelido;
            cin >> apelido;
            cadastro.remover_jogador(apelido);
        }

        if(entrada == "LJ" || entrada == "Listar Jogadores") {
            cadastro.listar_jogadores();
        }

        if(entrada == "EP" || entrada == "Executar Partida") {
            cout << "Digite o jogo e os apelidos dos dois jogadores:" << endl;
            cout << "<Jogo: (R|L)> <Apelido Jogador 1> <Apelido Jogador 2>" << endl;
            string jogo, um, dois;
            cin >> jogo >> um >> dois;

            if(jogo == "L") {
                jogador* p1 = nullptr;
                jogador* p2 = nullptr;

                for(auto& j : cadastro.jogadores) {
                    if(j.apelido == um) {
                        p1 = &j;
                    } else if(j.apelido == dois) {
                        p2 = &j;
                    }
                }

                if(p1 == nullptr || p2 == nullptr) {
                    cout << "ERRO: Um ou ambos os jogadores não estão cadastrados." << endl;
                    continue;
                }

                Lig4 lig4(*p1, *p2);
                lig4.jogar();
            }
            
            if(jogo == "R") {
                Reversi teste;
                teste.jogar();
            }
        }

        if(entrada == "FS" || entrada == "Finalizar Sistema") {
            return 0;
        }
    }
}