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
        int coluna_desejada, linha_aux = 7;
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

bool Lig4::checador_vertical(int linha_aux, int coluna_aux){
    int jogada = this->tabuleiro[linha_aux][coluna_aux];
    int contagem = 1;

    for (int i = linha_aux; i < linhas - 1 || contagem < 4 ; i++) {
        if (this->tabuleiro[i][coluna_aux] == jogada) {
            contagem++;
        } else {
            break;
        }
    }
    return contagem == 4;
}

bool Lig4::verificar_vertical(int linha_aux, int coluna_aux){
    int jogada = this->tabuleiro[linha_aux][coluna_aux];
    for(int i = 0 ; i < colunas-3 ; i++){
        if(this->tabuleiro[i][coluna_aux] == jogada){
            if(checador_horizontal(i, coluna_aux)) return true;
        }
    }
    return false;
}

bool Lig4::checador_horizontal(int linha_aux ,int coluna_aux){
    int jogada = this->tabuleiro[linha_aux][coluna_aux];
    int contagem = 1;

    for (int j = coluna_aux; j < colunas - 1 || contagem < 4 ; j++) {
        if (this->tabuleiro[linha_aux][j + 1] == jogada) {
            contagem++;
        } else {
            break;
        }
    }
    return contagem == 4;
}

bool Lig4::verificar_horizontal(int linha_aux, int coluna_aux ){
    int jogada = this->tabuleiro[linha_aux][coluna_aux];
    for(int i = 0 ; i < colunas-3 ; i++){
        if(this->tabuleiro[linha_aux][i] == jogada){
            if(checador_horizontal(linha_aux, i)) return true;
        }
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
    int posicao_atual;
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
    int posicao_atual;
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
    if(verificar_diagonal_subindo_direita(linha_aux,coluna_aux)) return true;
    if(verificar_diagonal_subindo_esquerda(linha_aux,coluna_aux)) return true;
    return false;
}