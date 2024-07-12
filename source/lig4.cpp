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

bool Lig4::verificar_vitoria_horizontal(int linha_aux){
    for(int j=0; j<colunas-3; j++){ //verifico as colunas respectivas àquela linha 
        int contador = 0;
        for (int k=0; k<4; k++){
            if (tabuleiro[linha_aux][j] != 0 && tabuleiro[linha_aux][j+k]){
                contador++;
            }
            else{
                contador = 0;
            }
        }
        if (contador == 4){
            return true;
        }
    }
    return false;
}



bool Lig4::verificar_vitoria_vertical(int coluna_aux ){
    for(int i=0; i<linhas-3; i++){ //verifico as linhas respectivas àquela coluna
        int contador = 0;
        for (int k=0; k<4; k++){
            if (tabuleiro[i][coluna_aux] != 0 && tabuleiro[i+k][coluna_aux]){
                contador++;
            }
            else{
                contador = 0;
            }
        }
        if (contador == 4){
            return true;
        }
    }
    return false;
}


bool Lig4::verificar_vitoria_diagonal(int linha_aux, int coluna_aux){
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

bool Lig4::verificar_vitoria(int linha_aux, int coluna_aux){
    if (verificar_vitoria_horizontal(linha_aux) || verificar_vitoria_vertical(coluna_aux) || verificar_vitoria_diagonal(linha_aux, coluna_aux))
        return true;
    else 
        return false;
}



void Lig4::realizar_jogada() {
    for (jogador aux : jogadores) {
        int i = aux.jogada;
        int coluna_desejada, linha_aux = 7;  // Corrigido para a última linha válida do tabuleiro 8x8
        cout << "Digite a coluna de sua jogada jogador " << i << endl;
        cin >> coluna_desejada;
        if (jogada_valida(coluna_desejada)) {
            while (linha_aux >= 0 && this->tabuleiro[linha_aux][coluna_desejada] != 0) {
                linha_aux--;
            }
            if (linha_aux >= 0) {
                this->tabuleiro[linha_aux][coluna_desejada] = i;
                if (verificar_vitoria(linha_aux, coluna_desejada)) {
                    cout << "O jogador " << i << " é o vencedor! Parabéns!!" << endl;
                    return;  // Use 'return' para parar o jogo
                }
            } else {
                cout << "Coluna cheia, escolha outra coluna." << endl;
            }
        } else {
            cout << "Coluna inválida, escolha outra coluna." << endl;
        }
    }
}