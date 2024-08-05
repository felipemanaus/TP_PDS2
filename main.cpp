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

    Reversi partida;
    int linha, coluna, i;

    while (cin >> linha >> coluna) {
        if (linha < 0 || linha > 7 || coluna < 0 || coluna > 7) {
            cout << "ERRO: jogada inválida" << endl;
            continue;
        }

        for (i = 0; i < static_cast<int>(partida.get_jogadas_possiveis_linha().size()) && 
                    i < static_cast<int>(partida.get_jogadas_possiveis_coluna().size()); ++i) {
            if (linha == partida.get_jogadas_possiveis_linha()[i] && coluna == partida.get_jogadas_possiveis_coluna()[i]) {
                partida.get_tabuleiro()[linha][coluna] = partida.get_cor_inicial();
                partida.inversao_da_cor_vertical(linha, coluna, partida.get_cor_inicial());
                partida.inversao_da_cor_horizontal(linha, coluna, partida.get_cor_inicial());
                partida.inversao_da_cor_diagonal(linha, coluna, partida.get_cor_inicial());
                partida.imprimir_tabuleiro();
                partida.contagem_pontos();
                break;
            }
        }

        if (i == static_cast<int>(partida.get_jogadas_possiveis_linha().size()) || 
            i == static_cast<int>(partida.get_jogadas_possiveis_coluna().size())) {
            cout << "ERRO: jogada inválida" << endl;
            continue;
        }

        if (partida.verificar_tabuleiro_cheio())
            return 0;

        cout << endl << "Jogadas possíveis para " << partida.encontrar_complemento_da_cor(partida.get_cor_inicial()) << ": " << endl;
        partida.jogadas_possiveis(partida.encontrar_complemento_da_cor(partida.get_cor_inicial()));
        cout << endl;

        if (partida.get_jogadas_possiveis_linha().empty() && partida.get_jogadas_possiveis_coluna().empty()) {
            cout << "PASS" << endl;
            cout << endl << "Jogadas possíveis para " << partida.get_cor_inicial() << ": " << endl;
            partida.jogadas_possiveis(partida.get_cor_inicial());
            cout << endl;
            if (partida.get_jogadas_possiveis_linha().empty() && partida.get_jogadas_possiveis_coluna().empty()) {
                cout << "PASS";
                return 0;
            } else {
                continue;
            }
        }

        while (cin >> linha >> coluna) {
            if (linha < 0 || linha > 7 || coluna < 0 || coluna > 7) {
                cout << "ERRO: jogada inválida" << endl;
                continue;
            }

            for (i = 0; i < static_cast<int>(partida.get_jogadas_possiveis_linha().size()) && 
                        i < static_cast<int>(partida.get_jogadas_possiveis_coluna().size()); ++i) {
                if (linha == partida.get_jogadas_possiveis_linha()[i] && coluna == partida.get_jogadas_possiveis_coluna()[i]) {
                    partida.get_tabuleiro()[linha][coluna] = partida.encontrar_complemento_da_cor(partida.get_cor_inicial());
                    partida.inversao_da_cor_vertical(linha, coluna, partida.encontrar_complemento_da_cor(partida.get_cor_inicial()));
                    partida.inversao_da_cor_horizontal(linha, coluna, partida.encontrar_complemento_da_cor(partida.get_cor_inicial()));
                    partida.inversao_da_cor_diagonal(linha, coluna, partida.encontrar_complemento_da_cor(partida.get_cor_inicial()));
                    partida.imprimir_tabuleiro();
                    partida.contagem_pontos();
                    break;
                }
            }

            if (i == static_cast<int>(partida.get_jogadas_possiveis_linha().size()) || 
                i == static_cast<int>(partida.get_jogadas_possiveis_coluna().size())) {
                cout << "ERRO: jogada inválida" << endl;
                continue;
            }

            if (partida.verificar_tabuleiro_cheio())
                return 0;

            cout << endl << "Jogadas possíveis para " << partida.get_cor_inicial() << ": " << endl;
            partida.jogadas_possiveis(partida.get_cor_inicial());
            cout << endl;

            if (partida.get_jogadas_possiveis_linha().empty() && partida.get_jogadas_possiveis_coluna().empty()) {
                cout << "PASS" << endl;
                cout << endl << "Jogadas possíveis para " << partida.encontrar_complemento_da_cor(partida.get_cor_inicial()) << ": " << endl;
                partida.jogadas_possiveis(partida.encontrar_complemento_da_cor(partida.get_cor_inicial()));
                cout << endl;
                if (partida.get_jogadas_possiveis_linha().empty() && partida.get_jogadas_possiveis_coluna().empty()) {
                    cout << "PASS";
                    return 0;
                } else {
                    continue;
                }
            } else {
                break;
            }
        }
    }
    return 0;
}

    


