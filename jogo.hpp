#ifndef JOGO_HPP
#define JOGO_HPP

#include <vector>


using namespace std;

class jogo {
public:
    jogo (int linhas, int colunas);
    virtual ~jogo() = default;

    virtual void realizar_jogada(int linha, int coluna, int jogador) = 0;
    virtual bool jogada_valida(int linha, int coluna) const = 0;
    virtual void imprimir_tabuleiro() const = 0;
    virtual bool verificar_vitoria(int jogador) const = 0;


protected:
    int linhas;
    int colunas;
    vector<vector<int>> tabuleiro;

};

#endif 











































#endif JOGO_HPP