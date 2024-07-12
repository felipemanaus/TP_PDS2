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

    teste.jogar();
    
    
    return 0;
}