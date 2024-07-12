#include "include/jogador.hpp"
#include "include/jogo.hpp"
#include "include/Lig4.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    jogador p1("felipe","felipe", 1);
    jogador p2("borges","borges", 2);

    Lig4 teste (p1, p2);

    while(1){
        teste.imprimir_tabuleiro();
        bool tabuleiro_cheio = teste.verificar_tabuleiro_cheio();
        if(tabuleiro_cheio){
            cout << "O jogo acabou" << endl;
            break;
        }
        //bool ganhou = teste.verificar_vitoria
        //teste.realizar_jogada();
    }
    
    return 0;
}