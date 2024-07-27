#include "../include/Reversi.hpp"
#include "../include/jogo.hpp"
#include <iostream>
#include <vector>
#include <random>



using namespace std;



Reversi::Reversi() : jogo() {
    tabuleiro.resize(linhas);
    for (int i=0; i<linhas; i++){
        tabuleiro[i].resize(colunas, ' ');
    }
    tabuleiro[3][3] = seleciona_cor_aleatoria();
    tabuleiro[4][4] = tabuleiro[3][3];
    tabuleiro[3][4] = encontrar_complemento_da_cor(tabuleiro[3][3]);
    tabuleiro[4][3] = tabuleiro[3][4];
    cout << "B: BLACK" << endl << "W: WHITE" << endl;
    imprimir_tabuleiro();
    contagem_pontos();
    cor_inicial = seleciona_cor_aleatoria();
    cout << endl << "A cor " << cor_inicial << " começa jogando" << endl;
    cout << endl << "Jogadas possíveis para " << cor_inicial << ": " << endl;
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            if (e_valido(i, j, cor_inicial)){
                jogadas_possiveis_linha.push_back(i);
                jogadas_possiveis_coluna.push_back(j);
                cout << "(" << i << ", " << j << ")" << endl;
            }
        }
    }
    cout << endl << endl;
}


vector<vector<char>> Reversi::get_tabuleiro() {
    return tabuleiro;
}


char Reversi::get_cor_inicial() {
    return cor_inicial;
}


vector<int> Reversi::get_jogadas_possiveis_linha() {
    return jogadas_possiveis_linha;
}


vector<int> Reversi::get_jogadas_possiveis_coluna() {
    return jogadas_possiveis_coluna;
}


void Reversi::imprimir_tabuleiro() {
    cout << endl << endl;
    
  //imprime indice das colunas
  cout << "    "; 
      for(int j = 0 ; j < colunas ; j++){
          cout << j << "  ";
      }
      cout << endl;
      cout << "    "; 
      for(int j = 0 ; j < colunas ; j++){
          cout << "__" << " ";
      }
      cout << endl;

  //imprime linhas
  for(int i = 0 ; i < linhas ; i++){
    cout << i << "  |";
    for(int j = 0 ; j < colunas ; j++){
      cout << tabuleiro[i][j] << " |";
    }
    cout << endl;
    cout << "   |";
    for(int j = 0 ; j < colunas ; j++){
        cout << "__" << "|";
    }
    cout << endl;
    }
    cout << endl;
}




//confere se o tabuleiro está cheio
bool Reversi::verificar_tabuleiro_cheio () {
    int i, j;
    for (i = 0; i < 8; ++i){
        for (j = 0; j < 8; ++j){
            if (tabuleiro[i][j] == ' ')
                break;
        }
        if (j < 8)
            break;
    }
    if (i == 8 && j == 8)
        return true;
    else
        return false;
}




char Reversi::encontrar_complemento_da_cor(char cor_jogando){
    if ('B' == cor_jogando)
        return 'W';
    else
        return 'B';
}



//escolhe uma cor de forma aleatória para começar o jogo
char Reversi::seleciona_cor_aleatoria () {

    vector<char> cores = {'B', 'W'};

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, cores.size() - 1);

    int indice_aleatorio = distrib(gen);

    
    return cores[indice_aleatorio];
    
}



void Reversi::contagem_pontos () {
    int cont_b = 0;
    int cont_w = 0;

    for (int i = 0; i <= 7; ++i)
        for (int j = 0; j <= 7; ++j) {
            if (tabuleiro[i][j] == 'B')
                ++cont_b;
            else if (tabuleiro[i][j] == 'W')
                ++cont_w;
        }

    cout << endl << "B: " << cont_b << " pontos" << endl << "W: " << cont_w << " pontos" << endl;

}



bool Reversi::confere_vertical(int i, int j, char cor_jogando) {

    if (tabuleiro[i][j] == ' ') {

        //confere vertical para cima
            if (i >= 2) {
                if (tabuleiro[i - 1][j] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int x = i - 2; x >= 0; --x) {
                        if (tabuleiro[x][j] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][j] == cor_jogando)
                            return true;
                        if (tabuleiro[x][j] == ' ')
                            break;
                    }
                }
            }
            //confere vertical para baixo
            if (i <= 5) {
                if (tabuleiro[i + 1][j] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int x = i + 2; x <= 7; ++x) {
                        if (tabuleiro[x][j] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][j] == cor_jogando)
                            return true;
                        if (tabuleiro[x][j] == ' ')
                            break;
                    }
                }
            }
    }

    return false;

}



bool Reversi::confere_horizontal(int i, int j, char cor_jogando) {

    if (tabuleiro[i][j] == ' ') {

        //confere horizontal para a esquerda
            if (j >= 2) {
                if (tabuleiro[i][j - 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int y = j - 2; y >= 0; --y){
                        if (tabuleiro[i][y] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[i][y] == cor_jogando)
                            return true;
                        if (tabuleiro[i][y] == ' ')
                            break;
                    }
                }
            }
            //confere horizontal para a direita
            if (j <= 5) {
                if (tabuleiro[i][j + 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int y = j + 2; y <= 7; ++y){
                        if (tabuleiro[i][y] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[i][y] == cor_jogando)
                            return true;
                        if (tabuleiro[i][y] == ' ')
                            break;
                    }
                }
            } 
    }

    return false;
}
    



bool Reversi::confere_diagonal(int i, int j, char cor_jogando) {

    if (tabuleiro[i][j] == ' ') {

        //confere diagonal a noroeste
            if (i >= 2 && j >= 2) {
                if (tabuleiro[i - 1][j - 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int x = i - 2, y = j - 2; x >= 0 && y >= 0; --x, --y) {
                        if (tabuleiro[x][y] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][y] == cor_jogando)
                            return true;
                        if (tabuleiro[x][y] == ' ')
                            break;
                    }
                }
            }

            //confere diagonal a nordeste
            if (i >= 2 && j <= 5) {
                if (tabuleiro[i - 1][j + 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int x = i - 2, y = j + 2; x >= 0 && y <= 7; --x, ++y) {
                        if (tabuleiro[x][y] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][y] == cor_jogando)
                            return true;
                        if (tabuleiro[x][y] == ' ')
                            break;
                    }
                }
            }

            //confere diagonal a sudoeste
            if (i <= 5 && j >= 2) {
                if (tabuleiro[i + 1][j - 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int x = i + 2, y = j - 2; x <= 7 && y >= 0; ++x, --y) {
                        if (tabuleiro[x][y] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][y] == cor_jogando)
                            return true;
                        if (tabuleiro[x][y] == ' ')
                            break;
                    }
                }
            }

            //confere diagonal a sudeste
            if (i <= 5 && j <= 5) {
                if (tabuleiro[i + 1][j + 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int x = i + 2, y = j + 2; x <= 7 && y <= 7; ++x, ++y) {
                        if (tabuleiro[x][y] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][y] == cor_jogando)
                            return true;
                        if (tabuleiro[x][y] == ' ')
                            break;
                    }
                }
            }
    }

    return false;
}



//confere se dada posição do tabuleiro é uma jogada válida
bool Reversi::e_valido(int i, int j, char cor_jogando) {
    
    if (confere_vertical(i, j, cor_jogando))
        return true;
    if (confere_horizontal(i, j, cor_jogando))
        return true;
    if (confere_diagonal(i, j, cor_jogando))
        return true;
    
    return false;
}



void Reversi::jogadas_possiveis (char cor_jogando) {
    
    jogadas_possiveis_linha.clear();
    jogadas_possiveis_coluna.clear();

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j){
            if (e_valido(i, j, cor_jogando)){
                jogadas_possiveis_linha.push_back(i);
                jogadas_possiveis_coluna.push_back(j);
                cout << "(" << i << ", " << j << ")" << endl;
            }
        }
    }
    
}



vector<vector<char>> Reversi::inversao_da_cor_vertical(int i, int j, char cor_jogando) {
    int x;
    
        
            //altera a cor na vertical para cima
            if (i >= 2) {
                if (tabuleiro[i - 1][j] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (x = i - 2; x >= 0; --x) {
                        if (tabuleiro[x][j] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][j] == cor_jogando) {
                            for (int k = i - 1; k > x; --k)
                                tabuleiro[k][j] = cor_jogando;
                            break;
                        }
                        if (tabuleiro[x][j] == ' ')
                            break;
                    }
                }
            }
        
            //altera a cor na vertical para baixo
            if (i <= 5) {
                if (tabuleiro[i + 1][j] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (x = i + 2; x <= 7; ++x) {
                        if (tabuleiro[x][j] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][j] == cor_jogando) {
                            for (int k = i + 1; k < x; ++k)
                                tabuleiro[k][j] = cor_jogando;
                            break;
                        }
                        if (tabuleiro[x][j] == ' ')
                            break;
                    }
                }
            }

    return tabuleiro;
    
}



vector<vector<char>> Reversi::inversao_da_cor_horizontal(int i, int j, char cor_jogando) {
    int y;

        
      //altera a cor na horizontal para a esquerda  
        if (j >= 2) {
            
            if (tabuleiro[i][j - 1] == encontrar_complemento_da_cor(cor_jogando)) {
                for (y = j - 2; y >= 0; --y) {
                    if (tabuleiro[i][y] == encontrar_complemento_da_cor(cor_jogando))
                        continue;
                    if (tabuleiro[i][y] == cor_jogando) {
                        for (int k = j - 1; k > y; --k)
                            tabuleiro[i][k] = cor_jogando;
                        break;
                    }
                    if (tabuleiro[i][y] == ' ')
                        break;
                }
            }
            
        }
        
        //altera a cor na horizontal para a direita
        if (j <= 5) {
            if (tabuleiro[i][j + 1] == encontrar_complemento_da_cor(cor_jogando)) {
                for (y = j + 2; y <= 7; ++y) {
                    if (tabuleiro[i][y] == encontrar_complemento_da_cor(cor_jogando))
                        continue;
                    if (tabuleiro[i][y] == cor_jogando) {
                        for (int k = j + 1; k < y; ++k)
                            tabuleiro[i][k] = cor_jogando;
                        break;
                    }
                    if (tabuleiro[i][y] == ' ')
                        break;
                }
            }
        } 
  

    return tabuleiro;
}



vector<vector<char>> Reversi::inversao_da_cor_diagonal(int i, int j, char cor_jogando) {
    int x, y;


        //altera a cor na diagonal a noroeste
            if (i >= 2 && j >= 2) {
                if (tabuleiro[i - 1][j - 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (x = i - 2, y = j - 2; x >= 0 && y >= 0; --x, --y) {
                        if (tabuleiro[x][y] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][y] == cor_jogando) {
                            for (int k = i - 1, l = j - 1; k > x && l > y; --k, --l)
                                tabuleiro[k][l] = cor_jogando;
                            break;
                        }
                        if (tabuleiro[x][y] == ' ')
                            break;
                    }                
                }
            }

            //altera a cor na diagonal a nordeste
            if (i >= 2 && j <= 5) {
                if (tabuleiro[i - 1][j + 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (x = i - 2, y = j + 2; x >= 0 && y <= 7; --x, ++y) {
                        if (tabuleiro[x][y] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][y] == cor_jogando) {
                            for (int k = i - 1, l = j + 1; k > x && l < y; --k, ++l)
                                tabuleiro[k][l] = cor_jogando;
                            break;
                        }
                        if (tabuleiro[x][y] == ' ')
                            break;
                    }
                }
            }

            //altera a cor na diagonal a sudoeste
            if (i <= 5 && j >= 2) {
                if (tabuleiro[i + 1][j - 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (x = i + 2, y = j - 2; x <= 7 && y >= 0; ++x, --y) {
                        if (tabuleiro[x][y] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][y] == cor_jogando) {
                            for (int k = i + 1, l = j - 1; k < x && l > y; ++k, --l)
                                tabuleiro[k][l] = cor_jogando;
                            break;
                        }
                        if (tabuleiro[x][y] == ' ')
                            break;
                    }
                }
            }

            //altera a cor na diagonal a sudeste
            if (i <= 5 && j <= 5) {
                if (tabuleiro[i + 1][j + 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (x = i + 2, y = j + 2; x <= 7 && y <= 7; ++x, ++y) {
                        if (tabuleiro[x][y] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][y] == cor_jogando) {
                            for (int k = i + 1, l = j + 1; k < x && l < y; ++k, ++l)
                                tabuleiro[k][l] = cor_jogando;
                            break;
                        }
                        if (tabuleiro[x][y] == ' ')
                            break;
                    }
                }
            }

    return tabuleiro;
    
}