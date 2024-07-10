#ifndef LIG4_HPP
#define LIG4_HPP

#include "jogo.hpp"


class lig4 : public jogo{
public:
    lig4();
    ~lig4() override;

     void realizar_jogada(int linha, int coluna, int jogador) override;
     bool jogada_valida(int linha, int coluna) const override;
     void imprimir_tabuleiro()  const override;
     bool verificar_vitoria(int jogador) const override;

private:
    bool vitoria_horizontal (int jogador) const;
    bool vitoria_vertical (int jogador) const;
    bool vitoria_diagonal (int jogador) const;

};

#endif