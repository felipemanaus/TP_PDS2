#include "include/jogador.hpp"
#include "include/jogo.hpp"
#include "include/Lig4.hpp"
#include "include/Reversi.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    jogador p1("felipe", "felipe", 1);
    jogador p2("borges", "borges", 2);

    Lig4 teste(p1, p2);

    /*while (true) {
        teste.imprimir_tabuleiro();
        bool tabuleiro_cheio = teste.verificar_tabuleiro_cheio();
        if (tabuleiro_cheio) {
            cout << "O jogo acabou" << endl;
            break;
        }
        teste.realizar_jogada();
    }*/

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
