/**
 * @file Lig4.cpp
 * @brief Implementação das funções da classe `Lig4`, que modela o jogo Lig4, onde dois jogadores competem para alinhar quatro peças em um tabuleiro.
 */

#include "../include/Lig4.hpp"

/**
 * @brief Construtor da classe `Lig4`.
 * 
 * Inicializa o jogo Lig4 com dois jogadores.
 * 
 * @param p1 Primeiro jogador.
 * @param p2 Segundo jogador.
 */
Lig4::Lig4(jogador p1, jogador p2) : jogo() {
    jogadores = {p1, p2};
}

/**
 * @brief Imprime o tabuleiro do jogo Lig4 na tela.
 * 
 * Exibe o tabuleiro com os índices das colunas e o estado atual de cada célula.
 */
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

/**
 * @brief Verifica se uma jogada em uma coluna é válida.
 * 
 * Uma jogada é considerada válida se a coluna não estiver cheia e estiver dentro dos limites do tabuleiro.
 * 
 * @param coluna Coluna a ser verificada.
 * @return true se a jogada for válida, false caso contrário.
 * 
 * @throw std::out_of_range Se a coluna estiver fora dos limites permitidos.
 */
bool Lig4::jogada_valida(int coluna) {
    if(coluna < 0 || coluna >= colunas) {
        throw std::out_of_range("Coluna inválida.");
    }
    // Checa se a coluna está cheia
    return this->tabuleiro[0][coluna] == 0;
}

/**
 * @brief Verifica se o tabuleiro está completamente preenchido.
 * 
 * Itera por todas as posições do tabuleiro para determinar se não há mais espaços vazios.
 * 
 * @return true se o tabuleiro estiver cheio, false caso contrário.
 */
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

/**
 * @brief Controla o fluxo principal do jogo, alternando entre os jogadores até que haja um vencedor ou o tabuleiro esteja cheio.
 * 
 * @return O índice do jogador vencedor ou 0 em caso de empate.
 */
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

/**
 * @brief Verifica se há uma condição de vitória na vertical.
 * 
 * Verifica se há quatro peças consecutivas na mesma coluna.
 * 
 * @param linha_aux Linha da última jogada.
 * @param coluna_aux Coluna da última jogada.
 * @return true se houver uma vitória na vertical, false caso contrário.
 * 
 * @throw std::out_of_range Se a posição estiver fora dos limites do tabuleiro.
 */
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

/**
 * @brief Verifica se há uma condição de vitória na horizontal.
 * 
 * Verifica se há quatro peças consecutivas na mesma linha.
 * 
 * @param linha_aux Linha da última jogada.
 * @param coluna_aux Coluna da última jogada.
 * @return true se houver uma vitória na horizontal, false caso contrário.
 * 
 * @throw std::out_of_range Se a posição estiver fora dos limites do tabuleiro.
 */
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

/**
 * @brief Verifica se há uma condição de vitória nas diagonais.
 * 
 * Verifica se há quatro peças consecutivas em qualquer uma das duas diagonais possíveis.
 * 
 * @param linha_aux Linha da última jogada.
 * @param coluna_aux Coluna da última jogada.
 * @return true se houver uma vitória na diagonal, false caso contrário.
 * 
 * @throw std::out_of_range Se a posição estiver fora dos limites do tabuleiro.
 */
bool Lig4::verificar_diagonal(int linha_aux, int coluna_aux) {
    if(linha_aux < 0 || linha_aux >= linhas || coluna_aux < 0 || coluna_aux >= colunas) {
        throw std::out_of_range("Posição inválida para verificação diagonal.");
    }

    int posicao = tabuleiro[linha_aux][coluna_aux];
    int contador = 0;

    // Verificação da diagonal principal (canto superior esquerdo ao canto inferior direito)
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

    // Verificação da diagonal secundária (canto inferior esquerdo ao canto superior direito)
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

/**
 * @brief Verifica se há uma condição de vitória em qualquer direção.
 * 
 * Combina as verificações vertical, horizontal e diagonal para determinar se há um vencedor.
 * 
 * @param linha_aux Linha da última jogada.
 * @param coluna_aux Coluna da última jogada.
 * @return true se houver uma vitória em qualquer direção, false caso contrário.
 */
bool Lig4::verificar_vitoria(int linha_aux, int coluna_aux) {
    return verificar_vertical(linha_aux, coluna_aux) ||
           verificar_horizontal(linha_aux, coluna_aux) ||
           verificar_diagonal(linha_aux, coluna_aux);
}
