#include "include/cadastro.hpp"
#include "include/jogador.hpp"
#include "include/jogo.hpp"
#include "include/lig4.hpp"
#include "include/reversi.hpp"

int main() {
    
    cadastro cadastro;
    char letra;

    cout << "Digite uma das letras: C, R, L, E ou F." << endl;
    cout << "<string>" << endl;

    while(cin >> letra) {
        switch(letra) {
            case 'C': {
                string apelido, nome;
                cout << "Digite o apelido e o nome:" << endl;
                cin >> apelido >> nome;
                cadastro.cadastrar_jogador(apelido, nome);
            }

            case 'R': {
                string apelido;
                cout << "Digite o apelido:" << endl;
                cin >> apelido;
                cadastro.remover_jogador(apelido);
            }

            case 'L': {
                cadastro.listar_jogadores();
            }

            case 'E': {
                string apelido1, apelido2;
                cout << "Digite os apelidos:" << endl;
                cout << "<Apelido Jogador 1> <Apelido Jogador 2>" << endl;
                cin >> apelido1 >> apelido2;
                
                jogador* p1 = nullptr;
                jogador* p2 = nullptr;
                for(auto& j : cadastro.jogadores) {
                    if (j.apelido == apelido1) {
                        p1 = &j;
                    } else if (j.apelido == apelido2) {
                        p2 = &j;
                    }
                }
                if(p1 == nullptr || p2 == nullptr) {
                    cout << "ERRO: Um ou ambos os jogadores não estão cadastrados." << endl;
                    break;
                }
                Lig4 teste(*p1, *p2);
                teste.jogar();

                break;
            }

            case 'F': {
                return 0;
            }
        }
    }
    
    
    Reversi teste;
    teste.jogar();

    
    return 0;
}

    


