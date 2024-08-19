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

        void imprimir_tabuleiro () override;
        bool verificar_tabuleiro_cheio () override;
        char encontrar_complemento_da_cor(char);
        void contagem_pontos ();
        bool confere_vertical (int, int, char);
        bool confere_horizontal (int, int, char);
        bool confere_diagonal (int, int, char);
        bool e_valido (int, int, char);
        void jogadas_possiveis (char);
        void imprime_jogadas_possiveis ();
        void marca_as_jogadas_possiveis_no_tabuleiro ();
        void desmarca_as_jogadas_possiveis_do_tabuleiro ();
        vector<vector<char>> inversao_da_cor_vertical (int, int, char);
        vector<vector<char>> inversao_da_cor_horizontal (int, int, char);
        vector<vector<char>> inversao_da_cor_diagonal (int, int, char);
        char verificar_vitoria ();
        char jogar ();
};

#endif