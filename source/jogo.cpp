#include "../include/jogo.hpp"

jogo::jogo (){
    this->linhas = 8;
    this->colunas = 8;
    this->tabuleiro.resize(linhas);
    for (int i=0; i<linhas; i++){
        this->tabuleiro[i].resize(colunas, 0);
    }
}

void jogo::imprimir_tabuleiro(){
    //imprime indice das colunas
    cout << "      "; 
        for(int j = 0 ; j < colunas ; j++){
            cout << j << "   ";
        }
        cout << endl;
        cout << "      "; 
        for(int j = 0 ; j < colunas ; j++){
            cout << "__" << "  ";
        }
        cout << endl;

    //imprime linhas
    for(int i = 0 ; i < linhas ; i++){
        cout << i << "    |";
        for(int j = 0 ; j < colunas ; j++){
            cout << tabuleiro[i][j] << "   ";
        }
        cout << endl ;
    }
    cout << endl ;
}

bool jogo::verificar_tabuleiro_cheio(){
    int contador_de_posicoes_ocupadas = 0;
    for(int i = 0 ; i < linhas ; i++){
        for(int j = 0 ; j < colunas ; j++){
            if(tabuleiro[i][j] != 0){
                contador_de_posicoes_ocupadas++;
            }
        }
    }
    if(contador_de_posicoes_ocupadas == colunas*linhas) return true;
    else return false;
}