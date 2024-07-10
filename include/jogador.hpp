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
  jogador(string nome , string apelido);
  void aumenta_vitorias();
  void aumenta_derrotas();
  string get_apelido() const;
};



#endif