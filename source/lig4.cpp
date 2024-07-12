#include "../include/Lig4.hpp"
#include "../include/jogo.hpp"
#include <iostream>

using namespace std;


Lig4::Lig4(jogador p1, jogador p2) : jogo() {
    jogadores = {p1, p2};
}

bool Lig4::jogada_valida(int coluna) {
    //checa se a coluna esta cheia
    if(this->tabuleiro[0][coluna] != 0) return false;
    else return true;        
    
}

void Lig4::jogar(){
    while(1){
        system("cls");
        this->imprimir_tabuleiro();
        bool tabuleiro_cheio = this->verificar_tabuleiro_cheio();
        if(tabuleiro_cheio){
            cout << "O jogo acabou" << endl;
            break;
        }
        bool venceu;
        for(jogador aux : jogadores){
            int i = aux.jogada;
            int coluna_desejada, linha_aux = 7;
            cout << "digite a coluna de sua jogada jogador " << i << endl;
            cin >> coluna_desejada;
            while(!jogada_valida(coluna_desejada)){
                cout << "coluna ja ocupada, escolha outra jogador " << i << endl;
                cin >> coluna_desejada;
            }
        
            while (this->tabuleiro[linha_aux][coluna_desejada] != 0){
                linha_aux--;
            }
            this->tabuleiro[linha_aux][coluna_desejada] = i;
            bool ganhou = this->verificar_vitoria(linha_aux, coluna_desejada);
            if (ganhou){
                this->imprimir_tabuleiro();
                cout << "jogador " << i << " venceu!!!!" << endl;
                venceu = true;
                break;
            }
        }
        if (venceu) break;
    }
}

bool Lig4::verificar_vertical(int linha_aux, int coluna_aux){
    int jogada = this->tabuleiro[linha_aux][coluna_aux];
    int contador = 1;
    int i_cima = linha_aux;
    int i_baixo = linha_aux;

    
    while(1){
        if(contador==4) return true;
        if(i_cima > 0 && this->tabuleiro[i_cima - 1][coluna_aux] == jogada){
            contador++;
            i_cima--;
        }
        else break;
    }
            
    while(1){
        if(contador==4) return true;
        if(i_baixo < 7 && this->tabuleiro[i_baixo + 1][coluna_aux] == jogada){
            contador++;
            i_baixo++;
        }
        else break;
    }
    return false;
}


bool Lig4::verificar_horizontal(int linha_aux, int coluna_aux ){
    int jogada = this->tabuleiro[linha_aux][coluna_aux];
    int contador = 1;
    int j_esquerda = coluna_aux;
    int j_direita = coluna_aux;

    
    while(1){
        if(contador==4) return true;
        if(j_esquerda > 0 && this->tabuleiro[linha_aux][j_esquerda - 1] == jogada){
            contador++;
            j_esquerda--;
        }
        else break;
    }
            
    while(1){
        if(contador==4) return true;
        if(j_direita < 7 && this->tabuleiro[linha_aux][j_direita + 1] == jogada){
            contador++;
            j_direita++;
        }
        else break;
    }
    return false;
}

bool Lig4::verificar_diagonal(int linha_aux, int coluna_aux){
    int posicao =  tabuleiro[linha_aux][coluna_aux];
    int contador = 0;
    for (int i=-3; i<4; i++){
        int x = linha_aux + i;
        int y = coluna_aux + i;
        if (x >= 0 && x < linhas && y >= 0 && y < colunas && tabuleiro[x][y] == posicao){
            contador++;
            if (contador == 4)
                return true;
        }
        else {
            contador = 0;
        }
    }

    contador = 0;
    for (int j=-3; j<4; j++){
        int x = linha_aux + j;
        int y = coluna_aux - j;
        if (x >= 0 && x < linhas && y >= 0 && y < colunas && tabuleiro[x][y] == posicao){
            contador++;
            if (contador == 4)
                return true;
        }
        else {
            contador = 0;
        }
    }
    return false;
}



bool Lig4::verificar_vitoria(int linha_aux,int coluna_aux){
    if(verificar_vertical(linha_aux,coluna_aux) || verificar_horizontal(linha_aux, coluna_aux) || verificar_diagonal(linha_aux, coluna_aux)){
        return true;
    }
    else{
        return false;
    }
}