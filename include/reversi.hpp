#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "./jogo.hpp"
#include "./jogador.hpp"

class Reversi : public jogo {
    private:
        vector<vector<char>> tabuleiro;
        char cor_inicial;
        vector<int> jogadas_possiveis_linha;
        vector<int> jogadas_possiveis_coluna;

    public:
        vector<jogador> jogadores;
        Reversi();

        vector<vector<char>> get_tabuleiro();
        void set_tabuleiro (int, int, char);
        char get_cor_inicial();
        vector<int> get_jogadas_possiveis_linha();
        vector<int> get_jogadas_possiveis_coluna();
        void imprimir_tabuleiro() override;
        bool verificar_tabuleiro_cheio () override;
        char encontrar_complemento_da_cor(char);
        void contagem_pontos ();
        bool confere_vertical(int, int, char);
        bool confere_horizontal(int, int, char);
        bool confere_diagonal(int, int, char);
        bool e_valido(int, int, char);
        void jogadas_possiveis (char);
        vector<vector<char>> inversao_da_cor_vertical(int, int, char);
        vector<vector<char>> inversao_da_cor_horizontal(int, int, char);
        vector<vector<char>> inversao_da_cor_diagonal(int, int, char);
        char verificar_vitoria();
        char jogar();
};

#endif