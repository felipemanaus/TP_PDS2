#include "../include/Reversi.hpp"

using namespace std;

Reversi::Reversi() : jogo() {
    tabuleiro.resize(linhas);
    for (int i=0; i<linhas; i++){
        tabuleiro[i].resize(colunas, ' ');
    }
    tabuleiro[3][3] = 'W';
    tabuleiro[4][4] = tabuleiro[3][3];
    tabuleiro[3][4] = 'B';
    tabuleiro[4][3] = tabuleiro[3][4];
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
    int linha, coluna;
    for (linha = 0; linha < 8; ++linha){
        for (coluna = 0; coluna < 8; ++coluna){
            if (tabuleiro[linha][coluna] == ' ')
                break;
        }
        if (coluna < 8)
            break;
    }
    if (linha == 8 && coluna == 8)
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


void Reversi::contagem_pontos () {
    int cont_b = 0;
    int cont_w = 0;

    for (int linha = 0; linha <= 7; ++linha){
        for (int coluna = 0; coluna <= 7; ++coluna) {
            if (tabuleiro[linha][coluna] == 'B')
                ++cont_b;
            else if (tabuleiro[linha][coluna] == 'W')
                ++cont_w;
        }
    }
    cout << endl << "B: " << cont_b << " pontos" << endl << "W: " << cont_w << " pontos" << endl;
}

bool Reversi::confere_vertical(int linha, int coluna, char cor_jogando) {
    if (tabuleiro[linha][coluna] == ' ') {

        //confere vertical para cima
            if (linha >= 2) {
                if (tabuleiro[linha - 1][coluna] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int x = linha - 2; x >= 0; --x) {
                        if (tabuleiro[x][coluna] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][coluna] == cor_jogando)
                            return true;
                        if (tabuleiro[x][coluna] == ' ')
                            break;
                    }
                }
            }
            //confere vertical para baixo
            if (linha <= 5) {
                if (tabuleiro[linha + 1][coluna] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int x = linha + 2; x <= 7; ++x) {
                        if (tabuleiro[x][coluna] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][coluna] == cor_jogando)
                            return true;
                        if (tabuleiro[x][coluna] == ' ')
                            break;
                    }
                }
            }
    }
    return false;
}



bool Reversi::confere_horizontal(int linha, int coluna, char cor_jogando) {
    if (tabuleiro[linha][coluna] == ' ') {

        //confere horizontal para a esquerda
            if (coluna >= 2) {
                if (tabuleiro[linha][coluna - 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int y = coluna - 2; y >= 0; --y){
                        if (tabuleiro[linha][y] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[linha][y] == cor_jogando)
                            return true;
                        if (tabuleiro[linha][y] == ' ')
                            break;
                    }
                }
            }
            //confere horizontal para a direita
            if (coluna <= 5) {
                if (tabuleiro[linha][coluna + 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int y = coluna + 2; y <= 7; ++y){
                        if (tabuleiro[linha][y] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[linha][y] == cor_jogando)
                            return true;
                        if (tabuleiro[linha][y] == ' ')
                            break;
                    }
                }
            } 
    }
    return false;
}

bool Reversi::confere_diagonal(int linha, int coluna, char cor_jogando) {
    if (tabuleiro[linha][coluna] == ' ') {

        //confere diagonal a noroeste
            if (linha >= 2 && coluna >= 2) {
                if (tabuleiro[linha - 1][coluna - 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int x = linha - 2, y = coluna - 2; x >= 0 && y >= 0; --x, --y) {
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
            if (linha >= 2 && coluna <= 5) {
                if (tabuleiro[linha - 1][coluna + 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int x = linha - 2, y = coluna + 2; x >= 0 && y <= 7; --x, ++y) {
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
            if (linha <= 5 && coluna >= 2) {
                if (tabuleiro[linha + 1][coluna - 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int x = linha + 2, y = coluna - 2; x <= 7 && y >= 0; ++x, --y) {
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
            if (linha <= 5 && coluna <= 5) {
                if (tabuleiro[linha + 1][coluna + 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int x = linha + 2, y = coluna + 2; x <= 7 && y <= 7; ++x, ++y) {
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
bool Reversi::e_valido(int linha, int coluna, char cor_jogando) {
    if (confere_vertical(linha, coluna, cor_jogando))
        return true;
    if (confere_horizontal(linha, coluna, cor_jogando))
        return true;
    if (confere_diagonal(linha, coluna, cor_jogando))
        return true;
    return false;
}

void Reversi::jogadas_possiveis (char cor_jogando) {
    jogadas_possiveis_linha.clear();
    jogadas_possiveis_coluna.clear();

    for (int linha = 0; linha < 8; ++linha) {
        for (int coluna = 0; coluna < 8; ++coluna){
            if (e_valido(linha, coluna, cor_jogando)){
                jogadas_possiveis_linha.push_back(linha);
                jogadas_possiveis_coluna.push_back(coluna);
            }
        }
    }
}


void Reversi::imprime_jogadas_possiveis () {
    for (int x = 0; x < static_cast<int>(jogadas_possiveis_linha.size()) && 
        x < static_cast<int>(jogadas_possiveis_coluna.size()); ++x)
            cout << "(" << jogadas_possiveis_linha[x] << ", " << jogadas_possiveis_coluna[x] << ")" << endl;
}


void Reversi::marca_as_jogadas_possiveis_no_tabuleiro () {
    for (int x = 0; x < static_cast<int>(jogadas_possiveis_linha.size()) && 
        x < static_cast<int>(jogadas_possiveis_coluna.size()); ++x)
            tabuleiro[jogadas_possiveis_linha[x]][jogadas_possiveis_coluna[x]] = '*';
}


void Reversi::desmarca_as_jogadas_possiveis_do_tabuleiro () {
    for (int x = 0; x < static_cast<int>(jogadas_possiveis_linha.size()) && 
        x < static_cast<int>(jogadas_possiveis_coluna.size()); ++x)
            tabuleiro[jogadas_possiveis_linha[x]][jogadas_possiveis_coluna[x]] = ' ';
}


vector<vector<char>> Reversi::inversao_da_cor_vertical(int linha, int coluna, char cor_jogando) {
    int x;
            //altera a cor na vertical para cima
            if (linha >= 2) {
                if (tabuleiro[linha - 1][coluna] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (x = linha - 2; x >= 0; --x) {
                        if (tabuleiro[x][coluna] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][coluna] == cor_jogando) {
                            for (int k = linha - 1; k > x; --k)
                                tabuleiro[k][coluna] = cor_jogando;
                            break;
                        }
                        if (tabuleiro[x][coluna] == ' ')
                            break;
                    }
                }
            }
        
            //altera a cor na vertical para baixo
            if (linha <= 5) {
                if (tabuleiro[linha + 1][coluna] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (x = linha + 2; x <= 7; ++x) {
                        if (tabuleiro[x][coluna] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][coluna] == cor_jogando) {
                            for (int k = linha + 1; k < x; ++k)
                                tabuleiro[k][coluna] = cor_jogando;
                            break;
                        }
                        if (tabuleiro[x][coluna] == ' ')
                            break;
                    }
                }
            }
    return tabuleiro;
}

vector<vector<char>> Reversi::inversao_da_cor_horizontal(int linha, int coluna, char cor_jogando) {
    int y;
      //altera a cor na horizontal para a esquerda  
        if (coluna >= 2) {
            
            if (tabuleiro[linha][coluna - 1] == encontrar_complemento_da_cor(cor_jogando)) {
                for (y = coluna - 2; y >= 0; --y) {
                    if (tabuleiro[linha][y] == encontrar_complemento_da_cor(cor_jogando))
                        continue;
                    if (tabuleiro[linha][y] == cor_jogando) {
                        for (int k = coluna - 1; k > y; --k)
                            tabuleiro[linha][k] = cor_jogando;
                        break;
                    }
                    if (tabuleiro[linha][y] == ' ')
                        break;
                }
            }
            
        }
        
        //altera a cor na horizontal para a direita
        if (coluna <= 5) {
            if (tabuleiro[linha][coluna + 1] == encontrar_complemento_da_cor(cor_jogando)) {
                for (y = coluna + 2; y <= 7; ++y) {
                    if (tabuleiro[linha][y] == encontrar_complemento_da_cor(cor_jogando))
                        continue;
                    if (tabuleiro[linha][y] == cor_jogando) {
                        for (int k = coluna + 1; k < y; ++k)
                            tabuleiro[linha][k] = cor_jogando;
                        break;
                    }
                    if (tabuleiro[linha][y] == ' ')
                        break;
                }
            }
        }
    return tabuleiro;
}

vector<vector<char>> Reversi::inversao_da_cor_diagonal(int linha, int coluna, char cor_jogando) {
    int x, y;
        //altera a cor na diagonal a noroeste
            if (linha >= 2 && coluna >= 2) {
                if (tabuleiro[linha - 1][coluna - 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (x = linha - 2, y = coluna - 2; x >= 0 && y >= 0; --x, --y) {
                        if (tabuleiro[x][y] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][y] == cor_jogando) {
                            for (int k = linha - 1, l = coluna - 1; k > x && l > y; --k, --l)
                                tabuleiro[k][l] = cor_jogando;
                            break;
                        }
                        if (tabuleiro[x][y] == ' ')
                            break;
                    }                
                }
            }

            //altera a cor na diagonal a nordeste
            if (linha >= 2 && coluna <= 5) {
                if (tabuleiro[linha - 1][coluna + 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (x = linha - 2, y = coluna + 2; x >= 0 && y <= 7; --x, ++y) {
                        if (tabuleiro[x][y] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][y] == cor_jogando) {
                            for (int k = linha - 1, l = coluna + 1; k > x && l < y; --k, ++l)
                                tabuleiro[k][l] = cor_jogando;
                            break;
                        }
                        if (tabuleiro[x][y] == ' ')
                            break;
                    }
                }
            }

            //altera a cor na diagonal a sudoeste
            if (linha <= 5 && coluna >= 2) {
                if (tabuleiro[linha + 1][coluna - 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (x = linha + 2, y = coluna - 2; x <= 7 && y >= 0; ++x, --y) {
                        if (tabuleiro[x][y] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][y] == cor_jogando) {
                            for (int k = linha + 1, l = coluna - 1; k < x && l > y; ++k, --l)
                                tabuleiro[k][l] = cor_jogando;
                            break;
                        }
                        if (tabuleiro[x][y] == ' ')
                            break;
                    }
                }
            }

            //altera a cor na diagonal a sudeste
            if (linha <= 5 && coluna <= 5) {
                if (tabuleiro[linha + 1][coluna + 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (x = linha + 2, y = coluna + 2; x <= 7 && y <= 7; ++x, ++y) {
                        if (tabuleiro[x][y] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[x][y] == cor_jogando) {
                            for (int k = linha + 1, l = coluna + 1; k < x && l < y; ++k, ++l)
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



char Reversi::verificar_vitoria() {
    int cont_b = 0;
    int cont_w = 0;

    for (int linha = 0; linha <= 7; ++linha){
        for (int coluna = 0; coluna <= 7; ++coluna) {
            if (tabuleiro[linha][coluna] == 'B')
                ++cont_b;
            else if (tabuleiro[linha][coluna] == 'W')
                ++cont_w;
        }
    }

    if(cont_w > cont_b) {
        cout << endl << endl << endl << "FIM DA PARTIDA" << endl << endl;
        cout << "W VENCEU";
        return 'W';
    }
    else {
        if(cont_w < cont_b) {
            cout << endl << endl << endl << "FIM DA PARTIDA" << endl << endl;
            cout << "B VENCEU";
            return 'B';
        }
        else {
            cout << endl << endl << endl << "FIM DA PARTIDA" << endl << endl;
            cout << "EMPATE";
            return 'D';
        }
    }
}



char Reversi::jogar () {
    system("cls");
    cout << "B: BLACK" << endl << "W: WHITE" << endl;
    cor_inicial = 'W';
    cout << endl << "A cor " << cor_inicial << " comeca jogando" << endl;
    jogadas_possiveis (cor_inicial);
    marca_as_jogadas_possiveis_no_tabuleiro ();
    imprimir_tabuleiro();
    desmarca_as_jogadas_possiveis_do_tabuleiro ();
    contagem_pontos();
    cout << endl << "Jogadas possiveis para " << cor_inicial << " (*):" << endl;
    imprime_jogadas_possiveis ();
    cout << endl << endl;
    int linha, coluna, i;

    cout << endl << "Digite sua jogada:" << endl;
    cout << "<linha> <coluna>" << endl;

    while (cin >> linha >> coluna) {
        if (linha < 0 || linha > 7 || coluna < 0 || coluna > 7) {
            cout << endl << endl << endl << "ERRO: jogada invalida" << endl << endl;
            cout << endl << "Digite uma jogada valida:" << endl;
            cout << "<linha> <coluna>" << endl;
            continue;
        }

        for (i = 0; i < static_cast<int>(jogadas_possiveis_linha.size()) && 
            i < static_cast<int>(jogadas_possiveis_coluna.size()); ++i) {
                if (linha == jogadas_possiveis_linha[i] && coluna == jogadas_possiveis_coluna[i]) {
                    tabuleiro[linha][coluna] = cor_inicial;
                    inversao_da_cor_vertical(linha, coluna, cor_inicial);
                    inversao_da_cor_horizontal(linha, coluna, cor_inicial);
                    inversao_da_cor_diagonal(linha, coluna, cor_inicial);
                    break;
                }
        }

        if (i == static_cast<int>(jogadas_possiveis_linha.size()) || 
            i == static_cast<int>(jogadas_possiveis_coluna.size())) {
                cout << endl << endl << endl << "ERRO: jogada invalida" << endl << endl;
                cout << endl << "Digite uma jogada valida:" << endl;
                cout << "<linha> <coluna>" << endl;
                continue;
        }

        jogadas_possiveis(encontrar_complemento_da_cor(cor_inicial));
        marca_as_jogadas_possiveis_no_tabuleiro ();
        system("cls");
        imprimir_tabuleiro();
        desmarca_as_jogadas_possiveis_do_tabuleiro ();
        contagem_pontos();

        if (verificar_tabuleiro_cheio()) return verificar_vitoria();

        cout << endl << "Jogadas possiveis para " << encontrar_complemento_da_cor(cor_inicial) << " (*):" << endl;
        imprime_jogadas_possiveis ();
        cout << endl;

        if (jogadas_possiveis_linha.empty() && jogadas_possiveis_coluna.empty()) {
            cout << "PASS" << endl;
            jogadas_possiveis(cor_inicial);
            marca_as_jogadas_possiveis_no_tabuleiro ();
            cout << endl << endl;
            imprimir_tabuleiro();
            desmarca_as_jogadas_possiveis_do_tabuleiro ();
            contagem_pontos();
            cout << endl << "Jogadas possiveis para " << cor_inicial << " (*):" << endl;
            imprime_jogadas_possiveis ();
            cout << endl;
            if (jogadas_possiveis_linha.empty() && jogadas_possiveis_coluna.empty()) {
                cout << "PASS";
                return verificar_vitoria();
            } else {
                cout << endl << "Digite sua jogada:" << endl;
                cout << "<linha> <coluna>" << endl;
                continue;
            }
        }

        cout << endl << "Digite sua jogada:" << endl;
        cout << "<linha> <coluna>" << endl;

        while (cin >> linha >> coluna) {
            if (linha < 0 || linha > 7 || coluna < 0 || coluna > 7) {
                cout << endl << endl << endl << "ERRO: jogada invalida" << endl << endl;
                cout << endl << "Digite uma jogada valida:" << endl;
                cout << "<linha> <coluna>" << endl;
                continue;
            }

            for (i = 0; i < static_cast<int>(jogadas_possiveis_linha.size()) && 
                i < static_cast<int>(jogadas_possiveis_coluna.size()); ++i) {
                    if (linha == jogadas_possiveis_linha[i] && coluna == jogadas_possiveis_coluna[i]) {
                        tabuleiro[linha][coluna] = encontrar_complemento_da_cor(cor_inicial);
                        inversao_da_cor_vertical(linha, coluna, encontrar_complemento_da_cor(cor_inicial));
                        inversao_da_cor_horizontal(linha, coluna, encontrar_complemento_da_cor(cor_inicial));
                        inversao_da_cor_diagonal(linha, coluna, encontrar_complemento_da_cor(cor_inicial));
                        break;
                    }
            }

            if (i == static_cast<int>(jogadas_possiveis_linha.size()) || 
                i == static_cast<int>(jogadas_possiveis_coluna.size())) {
                    cout << endl << endl << endl << "ERRO: jogada invalida" << endl << endl;
                    cout << endl << "Digite uma jogada valida:" << endl;
                    cout << "<linha> <coluna>" << endl;
                    continue;
            }

            jogadas_possiveis(cor_inicial);
            marca_as_jogadas_possiveis_no_tabuleiro ();
            system("cls");
            imprimir_tabuleiro();
            desmarca_as_jogadas_possiveis_do_tabuleiro ();
            contagem_pontos();

            if (verificar_tabuleiro_cheio()) return verificar_vitoria();

            cout << endl << "Jogadas possiveis para " << cor_inicial << " (*):" << endl;
            imprime_jogadas_possiveis ();
            cout << endl;

            if (jogadas_possiveis_linha.empty() && jogadas_possiveis_coluna.empty()) {
                cout << "PASS" << endl;
                jogadas_possiveis(encontrar_complemento_da_cor(cor_inicial));
                marca_as_jogadas_possiveis_no_tabuleiro ();
                cout << endl << endl;
                imprimir_tabuleiro();
                desmarca_as_jogadas_possiveis_do_tabuleiro ();
                contagem_pontos();
                cout << endl << "Jogadas possiveis para " << encontrar_complemento_da_cor(cor_inicial) << " (*):" << endl;
                imprime_jogadas_possiveis ();
                cout << endl;
                if (jogadas_possiveis_linha.empty() && jogadas_possiveis_coluna.empty()) {
                    cout << "PASS";
                    return verificar_vitoria();
                } else {
                    cout << endl << "Digite sua jogada:" << endl;
                    cout << "<linha> <coluna>" << endl;
                    continue;
                }
            } else {
                cout << endl << "Digite sua jogada:" << endl;
                cout << "<linha> <coluna>" << endl;
                break;
            }
        }
    }

    return verificar_vitoria();
}