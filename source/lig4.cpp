#include "../include/Lig4.hpp"
#include "../include/jogo.hpp"
#include <iostream>

using namespace std;


//tabuleiro 6x7
Lig4::Lig4(jogador p1, jogador p2) : jogo() {
    jogadores = {p1, p2};
}

bool Lig4::jogada_valida(int coluna) {
    //checa se a coluna esta cheia
    if(this->tabuleiro[0][coluna] != 0) return false;
    else return true;        
    
}
void Lig4::realizar_jogada() {
    for(jogador aux : jogadores){
        int i = aux.jogada;
        int coluna_desejada, linha_aux = 5;
        cout << "digite a coluna de sua jogada jogador " << i << endl;
        cin >> coluna_desejada;
        if (jogada_valida(coluna_desejada)) {
            while (this->tabuleiro[linha_aux][coluna_desejada] != 0){
                linha_aux--;
            }
        this->tabuleiro[linha_aux][coluna_desejada] = i;
        }
        else{
            while(this->tabuleiro[0][coluna_desejada] != 0){
                cout << "coluna ja ocupada, escolha outra jogador " << i << endl;
                cin >> coluna_desejada;
            }
        }
    }       
}

