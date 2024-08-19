#include "../include/Reversi.hpp"
#include <stdexcept> // Para std::out_of_range e std::invalid_argument

Reversi::Reversi() : jogo() {
    try {
        tabuleiro.resize(linhas);
        for (int i = 0; i < linhas; i++) {
            tabuleiro[i].resize(colunas, ' ');
        }
        tabuleiro[3][3] = 'W';
        tabuleiro[4][4] = tabuleiro[3][3];
        tabuleiro[3][4] = 'B';
        tabuleiro[4][3] = tabuleiro[3][4];
    } catch (const std::exception &e) {
        std::cerr << "Erro ao inicializar o tabuleiro: " << e.what() << std::endl;
        throw;
    }
}

void Reversi::imprimir_tabuleiro() {
    try {
        cout << endl << endl;
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
    } catch (const std::exception &e) {
        std::cerr << "Erro ao imprimir o tabuleiro: " << e.what() << std::endl;
        throw;
    }
}

bool Reversi::verificar_tabuleiro_cheio() {
    try {
        int linha, coluna;
        for (linha = 0; linha < 8; ++linha) {
            for (coluna = 0; coluna < 8; ++coluna) {
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
    } catch (const std::exception &e) {
        std::cerr << "Erro ao verificar se o tabuleiro está cheio: " << e.what() << std::endl;
        throw;
    }
}

char Reversi::encontrar_complemento_da_cor(char cor_jogando) {
    try {
        if ('B' == cor_jogando)
            return 'W';
        else if ('W' == cor_jogando)
            return 'B';
        else
            throw std::invalid_argument("Cor inválida");
    } catch (const std::exception &e) {
        std::cerr << "Erro ao encontrar o complemento da cor: " << e.what() << std::endl;
        throw;
    }
}

void Reversi::contagem_pontos() {
    try {
        int cont_b = 0;
        int cont_w = 0;

        for (int linha = 0; linha <= 7; ++linha) {
            for (int coluna = 0; coluna <= 7; ++coluna) {
                if (tabuleiro[linha][coluna] == 'B')
                    ++cont_b;
                else if (tabuleiro[linha][coluna] == 'W')
                    ++cont_w;
            }
        }
        cout << endl << "B: " << cont_b << " pontos" << endl << "W: " << cont_w << " pontos" << endl;
    } catch (const std::exception &e) {
        std::cerr << "Erro ao contar os pontos: " << e.what() << std::endl;
        throw;
    }
}

bool Reversi::confere_vertical(int linha, int coluna, char cor_jogando) {
    try {
        if (tabuleiro[linha][coluna] == ' ') {
            // confere vertical para cima
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
            // confere vertical para baixo
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
    } catch (const std::exception &e) {
        std::cerr << "Erro ao conferir vertical: " << e.what() << std::endl;
        throw;
    }
    return false;
}

bool Reversi::confere_horizontal(int linha, int coluna, char cor_jogando) {
    try {
        if (tabuleiro[linha][coluna] == ' ') {
            // confere horizontal para a esquerda
            if (coluna >= 2) {
                if (tabuleiro[linha][coluna - 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int y = coluna - 2; y >= 0; --y) {
                        if (tabuleiro[linha][y] == encontrar_complemento_da_cor(cor_jogando))
                            continue;
                        if (tabuleiro[linha][y] == cor_jogando)
                            return true;
                        if (tabuleiro[linha][y] == ' ')
                            break;
                    }
                }
            }
            // confere horizontal para a direita
            if (coluna <= 5) {
                if (tabuleiro[linha][coluna + 1] == encontrar_complemento_da_cor(cor_jogando)) {
                    for (int y = coluna + 2; y <= 7; ++y) {
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
    } catch (const std::exception &e) {
        std::cerr << "Erro ao conferir horizontal: " << e.what() << std::endl;
        throw;
    }
    return false;
}

bool Reversi::confere_diagonal(int linha, int coluna, char cor_jogando) {
    try {
        if (tabuleiro[linha][coluna] == ' ') {
            // confere diagonal a noroeste
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
            // confere diagonal a nordeste
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
            // confere diagonal a sudoeste
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
            // confere diagonal a sudeste
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
    } catch (const std::exception &e) {
        std::cerr << "Erro ao conferir diagonal: " << e.what() << std::endl;
        throw;
    }
    return false;
}

bool Reversi::e_valido(int linha, int coluna, char cor_jogando) {
    try {
        if (confere_vertical(linha, coluna, cor_jogando))
            return true;
        if (confere_horizontal(linha, coluna, cor_jogando))
            return true;
        if (confere_diagonal(linha, coluna, cor_jogando))
            return true;
        return false;
    } catch (const std::exception &e) {
        std::cerr << "Erro ao verificar validade da jogada: " << e.what() << std::endl;
        throw;
    }
}

void Reversi::jogadas_possiveis(char cor_jogando) {
    try {
        jogadas_possiveis_linha.clear();
        jogadas_possiveis_coluna.clear();

        for (int linha = 0; linha < 8; ++linha) {
            for (int coluna = 0; coluna < 8; ++coluna) {
                if (e_valido(linha, coluna, cor_jogando)) {
                    jogadas_possiveis_linha.push_back(linha);
                    jogadas_possiveis_coluna.push_back(coluna);
                }
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Erro ao determinar jogadas possíveis: " << e.what() << std::endl;
        throw;
    }
}

void Reversi::imprime_jogadas_possiveis() {
    try {
        for (int x = 0; x < static_cast<int>(jogadas_possiveis_linha.size()) && 
             x < static_cast<int>(jogadas_possiveis_coluna.size()); ++x)
            cout << "(" << jogadas_possiveis_linha[x] << ", " << jogadas_possiveis_coluna[x] << ")" << endl;
    } catch (const std::exception &e) {
        std::cerr << "Erro ao imprimir jogadas possíveis: " << e.what() << std::endl;
        throw;
    }
}

void Reversi::marca_as_jogadas_possiveis_no_tabuleiro() {
    try {
        for (int x = 0; x < static_cast<int>(jogadas_possiveis_linha.size()) && 
             x < static_cast<int>(jogadas_possiveis_coluna.size()); ++x)
            tabuleiro[jogadas_possiveis_linha[x]][jogadas_possiveis_coluna[x]] = '*';
    } catch (const std::exception &e) {
        std::cerr << "Erro ao marcar jogadas possíveis no tabuleiro: " << e.what() << std::endl;
        throw;
    }
}

void Reversi::desmarca_as_jogadas_possiveis_do_tabuleiro() {
    try {
        for (int x = 0; x < static_cast<int>(jogadas_possiveis_linha.size()) && 
             x < static_cast<int>(jogadas_possiveis_coluna.size()); ++x)
            tabuleiro[jogadas_possiveis_linha[x]][jogadas_possiveis_coluna[x]] = ' ';
    } catch (const std::exception &e) {
        std::cerr << "Erro ao desmarcar jogadas possíveis no tabuleiro: " << e.what() << std::endl;
        throw;
    }
}

vector<vector<char>> Reversi::inversao_da_cor_vertical(int linha, int coluna, char cor_jogando) {
    try {
        int x;
        // altera a cor na vertical para cima
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
        // altera a cor na vertical para baixo
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
    } catch (const std::exception &e) {
        std::cerr << "Erro ao inverter cor na vertical: " << e.what() << std::endl;
        throw;
    }
    return tabuleiro;
}

vector<vector<char>> Reversi::inversao_da_cor_horizontal(int linha, int coluna, char cor_jogando) {
    try {
        int y;
        // altera a cor na horizontal para a esquerda
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
        // altera a cor na horizontal para a direita
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
    } catch (const std::exception &e) {
        std::cerr << "Erro ao inverter cor na horizontal: " << e.what() << std::endl;
        throw;
    }
    return tabuleiro;
}

vector<vector<char>> Reversi::inversao_da_cor_diagonal(int linha, int coluna, char cor_jogando) {
    try {
        int x, y;
        // altera a cor na diagonal a noroeste
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
        // altera a cor na diagonal a nordeste
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
        // altera a cor na diagonal a sudoeste
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
        // altera a cor na diagonal a sudeste
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
    } catch (const std::exception &e) {
        std::cerr << "Erro ao inverter cor na diagonal: " << e.what() << std::endl;
        throw;
    }
    return tabuleiro;
}

char Reversi::verificar_vitoria() {
    try {
        int cont_b = 0;
        int cont_w = 0;

        for (int linha = 0; linha <= 7; ++linha) {
            for (int coluna = 0; coluna <= 7; ++coluna) {
                if (tabuleiro[linha][coluna] == 'B')
                    ++cont_b;
                else if (tabuleiro[linha][coluna] == 'W')
                    ++cont_w;
            }
        }

        if (cont_w > cont_b) {
            cout << endl << endl << endl << "FIM DA PARTIDA" << endl << endl;
            cout << "W VENCEU";
            return 'W';
        } else {
            if (cont_w < cont_b) {
                cout << endl << endl << endl << "FIM DA PARTIDA" << endl << endl;
                cout << "B VENCEU";
                return 'B';
            } else {
                cout << endl << endl << endl << "FIM DA PARTIDA" << endl << endl;
                cout << "EMPATE";
                return 'D';
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Erro ao verificar vitória: " << e.what() << std::endl;
        throw;
    }
}

char Reversi::jogar() {
    try {
        system("cls");
        cout << "B: BLACK" << endl << "W: WHITE" << endl;
        cor_inicial = 'W';
        cout << endl << "A cor " << cor_inicial << " comeca jogando" << endl;
        jogadas_possiveis(cor_inicial);
        marca_as_jogadas_possiveis_no_tabuleiro();
        imprimir_tabuleiro();
        desmarca_as_jogadas_possiveis_do_tabuleiro();
        contagem_pontos();
        cout << endl << "Jogadas possiveis para " << cor_inicial << " (*):" << endl;
        imprime_jogadas_possiveis();
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
            marca_as_jogadas_possiveis_no_tabuleiro();
            system("cls");
            imprimir_tabuleiro();
            desmarca_as_jogadas_possiveis_do_tabuleiro();
            contagem_pontos();

            if (verificar_tabuleiro_cheio()) return verificar_vitoria();

            cout << endl << "Jogadas possiveis para " << encontrar_complemento_da_cor(cor_inicial) << " (*):" << endl;
            imprime_jogadas_possiveis();
            cout << endl;

            if (jogadas_possiveis_linha.empty() && jogadas_possiveis_coluna.empty()) {
                cout << "PASS" << endl;
                jogadas_possiveis(cor_inicial);
                marca_as_jogadas_possiveis_no_tabuleiro();
                cout << endl << endl;
                imprimir_tabuleiro();
                desmarca_as_jogadas_possiveis_do_tabuleiro();
                contagem_pontos();
                cout << endl << "Jogadas possiveis para " << cor_inicial << " (*):" << endl;
                imprime_jogadas_possiveis();
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
                marca_as_jogadas_possiveis_no_tabuleiro();
                system("cls");
                imprimir_tabuleiro();
                desmarca_as_jogadas_possiveis_do_tabuleiro();
                contagem_pontos();

                if (verificar_tabuleiro_cheio()) return verificar_vitoria();

                cout << endl << "Jogadas possiveis para " << cor_inicial << " (*):" << endl;
                imprime_jogadas_possiveis();
                cout << endl;

                if (jogadas_possiveis_linha.empty() && jogadas_possiveis_coluna.empty()) {
                    cout << "PASS" << endl;
                    jogadas_possiveis(encontrar_complemento_da_cor(cor_inicial));
                    marca_as_jogadas_possiveis_no_tabuleiro();
                    cout << endl << endl;
                    imprimir_tabuleiro();
                    desmarca_as_jogadas_possiveis_do_tabuleiro();
                    contagem_pontos();
                    cout << endl << "Jogadas possiveis para " << encontrar_complemento_da_cor(cor_inicial) << " (*):" << endl;
                    imprime_jogadas_possiveis();
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
    } catch (const std::exception &e) {
        std::cerr << "Erro durante a execução do jogo: " << e.what() << std::endl;
        throw;
    }
}
