#include "../include/Lig4.hpp"
#include <stdexcept>

Lig4::Lig4(jogador p1, jogador p2) : jogo() {
    jogadores = {p1, p2};
}

void Lig4::imprimir_tabuleiro() {
    // Imprime índice das colunas
    cout << "      "; 
    for(int j = 0; j < colunas; j++) {
        cout << j << "   ";
    }
    cout << endl;

    cout << "      "; 
    for(int j = 0; j < colunas; j++) {
        cout << "__" << "  ";
    }
    cout << endl;

    // Imprime linhas
    for(int i = 0; i < linhas; i++) {
        cout << i << "    |";
        for(int j = 0; j < colunas; j++) {
            cout << tabuleiro[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

bool Lig4::jogada_valida(int coluna) {
    if(coluna < 0 || coluna >= colunas) {
        throw std::out_of_range("Coluna inválida.");
    }
    // Checa se a coluna está cheia
    return this->tabuleiro[0][coluna] == 0;
}

bool Lig4::verificar_tabuleiro_cheio() {
    int contador_de_posicoes_ocupadas = 0;
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            if(tabuleiro[i][j] != 0) {
                contador_de_posicoes_ocupadas++;
            }
        }
    }
    return contador_de_posicoes_ocupadas == colunas * linhas;
}

int Lig4::jogar() {
    int i;
    try {
        while(true) {
            bool venceu = false;
            for(int j = 1; j <= 2; j++) {
                system("cls");
                this->imprimir_tabuleiro();
                bool tabuleiro_cheio = this->verificar_tabuleiro_cheio();
                if(tabuleiro_cheio) {
                    cout << "O jogo acabou empatado" << endl;
                    return 0;
                }

                i = j;
                int coluna_desejada, linha_aux = 7;
                cout << "Digite a coluna de sua jogada jogador " << i << endl;
                cin >> coluna_desejada;

                try {
                    while(!jogada_valida(coluna_desejada)) {
                        cout << "Coluna já ocupada ou inválida, escolha outra jogador " << i << endl;
                        cin >> coluna_desejada;
                    }
                } catch(const std::exception& e) {
                    cout << "Erro: " << e.what() << endl;
                    continue;
                }

                while(this->tabuleiro[linha_aux][coluna_desejada] != 0) {
                    linha_aux--;
                }

                this->tabuleiro[linha_aux][coluna_desejada] = i;
                bool ganhou = this->verificar_vitoria(linha_aux, coluna_desejada);

                if(ganhou) {
                    system("cls");    
                    this->imprimir_tabuleiro();
                    cout << "Jogador " << i << " venceu!!!" << endl << endl;
                    venceu = true;
                    cout << "Digite EP para encerrar partida." << endl;
                    string entrada;
                    cin >> entrada;
                    while(entrada != "EP") {
                        cin >> entrada;
                    }
                    break;
                }
            }

            if(venceu) {
                break;
            }
        }
    } catch(const std::exception& e) {
        cout << "Erro durante o jogo: " << e.what() << endl;
    }
    return i;
}

bool Lig4::verificar_vertical(int linha_aux, int coluna_aux) {
    if(linha_aux < 0 || linha_aux >= linhas || coluna_aux < 0 || coluna_aux >= colunas) {
        throw std::out_of_range("Posição inválida para verificação vertical.");
    }

    int jogada = this->tabuleiro[linha_aux][coluna_aux];
    int contador = 1;
    int i_cima = linha_aux;
    int i_baixo = linha_aux;

    while(contador < 4) {
        if(i_cima > 0 && this->tabuleiro[i_cima - 1][coluna_aux] == jogada) {
            contador++;
            i_cima--;
        } else {
            break;
        }
    }
            
    while(contador < 4) {
        if(i_baixo < 7 && this->tabuleiro[i_baixo + 1][coluna_aux] == jogada) {
            contador++;
            i_baixo++;
        } else {
            break;
        }
    }
    return contador == 4;
}

bool Lig4::verificar_horizontal(int linha_aux, int coluna_aux) {
    if(linha_aux < 0 || linha_aux >= linhas || coluna_aux < 0 || coluna_aux >= colunas) {
        throw std::out_of_range("Posição inválida para verificação horizontal.");
    }

    int jogada = this->tabuleiro[linha_aux][coluna_aux];
    int contador = 1;
    int j_esquerda = coluna_aux;
    int j_direita = coluna_aux;

    while(contador < 4) {
        if(j_esquerda > 0 && this->tabuleiro[linha_aux][j_esquerda - 1] == jogada) {
            contador++;
            j_esquerda--;
        } else {
            break;
        }
    }
            
    while(contador < 4) {
        if(j_direita < 7 && this->tabuleiro[linha_aux][j_direita + 1] == jogada) {
            contador++;
            j_direita++;
        } else {
            break;
        }
    }
    return contador == 4;
}

bool Lig4::verificar_diagonal(int linha_aux, int coluna_aux) {
    if(linha_aux < 0 || linha_aux >= linhas || coluna_aux < 0 || coluna_aux >= colunas) {
        throw std::out_of_range("Posição inválida para verificação diagonal.");
    }

    int posicao = tabuleiro[linha_aux][coluna_aux];
    int contador = 0;

    for(int i = -3; i < 4; i++) {
        int x = linha_aux + i;
        int y = coluna_aux + i;
        if(x >= 0 && x < linhas && y >= 0 && y < colunas && tabuleiro[x][y] == posicao) {
            contador++;
            if(contador == 4) {
                return true;
            }
        } else {
            contador = 0;
        }
    }

    contador = 0;
    for(int j = -3; j < 4; j++) {
        int x = linha_aux + j;
        int y = coluna_aux - j;
        if(x >= 0 && x < linhas && y >= 0 && y < colunas && tabuleiro[x][y] == posicao) {
            contador++;
            if(contador == 4) {
                return true;
            }
        } else {
            contador = 0;
        }
    }
    return false;
}

bool Lig4::verificar_vitoria(int linha_aux, int coluna_aux) {
    return verificar_vertical(linha_aux, coluna_aux) ||
           verificar_horizontal(linha_aux, coluna_aux) ||
           verificar_diagonal(linha_aux, coluna_aux);
}