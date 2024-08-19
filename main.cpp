#include "include/cadastro.hpp"
#include "include/jogador.hpp"
#include "include/jogo.hpp"
#include "include/lig4.hpp"
#include "include/reversi.hpp"

int main() {
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
        cout << "<string>" << endl;

        cin >> entrada;

        if(entrada == "CJ") {
            cout << "Digite o apelido e o nome:" << endl;
            cout << "<Apelido> <Nome>" << endl;
            string apelido, nome;
            cin >> apelido >> nome;
            cadastro.cadastrar_jogador(apelido, nome);
        }

        if(entrada == "RJ") {
            cout << "Digite o apelido:" << endl;
            cout << "<Apelido>" << endl;
            string apelido;
            cin >> apelido;
            cadastro.remover_jogador(apelido);
        }

        if(entrada == "LJ") {
            cadastro.listar_jogadores();
        }

        if(entrada == "EP") {
            cout << "Digite o jogo e os apelidos dos dois jogadores:" << endl;
            cout << "<Jogo: (R|L)> <Apelido Jogador 1> <Apelido Jogador 2>" << endl;
            string jogo, um, dois;
            cin >> jogo >> um >> dois;

            if(um == dois) {
                throw std::invalid_argument("Os jogadores não podem ser iguais.");
            }

            jogador* p1 = cadastro.procurar_apelido(um);
            jogador* p2 = cadastro.procurar_apelido(dois);

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
        }

        if(entrada == "FS") {
            return 0;
        }
    }
}