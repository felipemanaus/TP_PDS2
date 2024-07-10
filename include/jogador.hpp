#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>

using namespace std;
class jogador {
private:
  string nome;
  string apelido;
  int quantidade_vitorias;
  int quantidade_derrotas;

public:
  int jogada; //sera 1 ou 2
  jogador(string, string, int);
  void aumenta_vitorias();
  void aumenta_derrotas();
  string get_apelido() const;
};
#endif