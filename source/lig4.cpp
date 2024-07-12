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

void Lig4::jogar(){
    while(1){
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

bool Lig4::checar_diagonal_descendo_direita(int linha_aux,int coluna_aux){
    int jogada = this->tabuleiro[linha_aux][coluna_aux];
    int contagem = 0;

    for (int i = linha_aux, j = coluna_aux; i < linhas - 1 || j < colunas - 1 || contagem < 4 ; i++,j++) {
        if (this->tabuleiro[i+1][j+1] == jogada) {
            contagem++;
        }
        else break;
    }
    return contagem == 4;
}

bool Lig4::verificar_diagonal_subindo_esquerda(int linha_aux,int coluna_aux){
    int jogada = this->tabuleiro[linha_aux][coluna_aux];
    int i = linha_aux,j = coluna_aux;
    for(; i >= 0 || j >= 0 ; i--,j--){}

    for(;i < linhas - 3 || j < colunas - 3; i++, j++){
        if(this->tabuleiro[i][j] == jogada){
            if(checar_diagonal_descendo_direita(i, j)) return true;
        }
    }
    return false;
}


bool Lig4::checar_diagonal_descendo_esquerda(int linha_aux,int coluna_aux){
    int jogada = this->tabuleiro[linha_aux][coluna_aux];
    int contagem = 0;

    for (int i = linha_aux, j = coluna_aux; i < linhas - 1 || j > 1 || contagem < 4 ; i++,j--) {
        if (this->tabuleiro[i+1][j-1] == jogada) {
            contagem++;
        }
        else break;
    }
    return contagem == 4;
}

bool Lig4::verificar_diagonal_subindo_direita(int linha_aux,int coluna_aux){
    int jogada = this->tabuleiro[linha_aux][coluna_aux];
    int i = linha_aux,j = coluna_aux;
    for(; i >= 0 || j <= colunas ; i--,j++){}

    for(;i < linhas - 3 || j < colunas - 3; i++, j--){
        if(this->tabuleiro[i][j] == jogada){
            if(checar_diagonal_descendo_direita(i, j)) return true;
        }
    }
    return false;
}

bool Lig4::verificar_vitoria(int linha_aux,int coluna_aux){
    if(verificar_vertical(linha_aux,coluna_aux)) return true;
    if(verificar_horizontal(linha_aux,coluna_aux)) return true;
    //if(verificar_diagonal_subindo_direita(linha_aux,coluna_aux)) return true;
    //if(verificar_diagonal_subindo_esquerda(linha_aux,coluna_aux)) return true;
    return false;
}