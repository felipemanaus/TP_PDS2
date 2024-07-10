#include "include/jogador.hpp"
#include "include/jogo.hpp"
#include "include/Lig4.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    //usando o formato de jogo 6x7
    int linhas = 6;
    int colunas = 7;
    int numero_de_elementos = linhas * colunas;
    int matriz_de_jogo [linhas] [colunas];

    //setando como matriz de zeros
    for(int i = 0 ; i < linhas ; i++){
        for(int j = 0 ; j < colunas ; j++){
            matriz_de_jogo[i][j]=0;
        }
    }

    
    //loop de jogo
    while(1){
        int colunas_cheias = 0;
        for(int j = 0 ; j < colunas ; j++){
            if(matriz_de_jogo[0][j] != 0){
                colunas_cheias++;
            }
        }
        if(colunas_cheias == colunas){
            cout << "O jogo acabou" << endl;
            break;
        }

        //printando os indices das colunas
        cout << "      "; 
        for(int j = 0 ; j < colunas ; j++){
            cout << j << "   ";
        }
        cout << endl;
        cout << "      "; 
        for(int j = 0 ; j < colunas ; j++){
            cout << "" << "  ";
        }
        cout << endl;

        //printando os indices das linhas e a matriz 
        for(int i = 0 ; i < linhas ; i++){
            cout << i << "    |";
            for(int j = 0 ; j < colunas ; j++){
                cout << matriz_de_jogo[i][j] << "   ";
            }
            cout << endl ;
        }
        cout << endl ;



        //loop das jogadas
        for(int i = 1 ; i < 3 ; i++){
            int coluna_desejada, linha_aux = 5;
            cout << "digite a coluna de sua jogada jogador " << i << endl;
            cin >> coluna_desejada;
            while(matriz_de_jogo[0][coluna_desejada] != 0){
                cout << "coluna ja ocupada, escolha outra jogador " << i << endl;
                cin >> coluna_desejada;
            }
            while(matriz_de_jogo[linha_aux][coluna_desejada] != 0){
                linha_aux--;
            }
            matriz_de_jogo[linha_aux][coluna_desejada] = i;

          


        }
        
   
    }

    return 0;
}