# TP_PDS2
Trabalho Prático de Programação e Desenvolvimento de Software 2 - Jogos de Tabuleiro

Visão Geral
    O sistema desenvolvido tem como objetivo gerenciar tanto jogadores quanto jogos de tabuleiro, incluindo funcionalidades específicas para cadastro e remoção de jogadores, além de gerenciamento e execução de dois jogos de tabuleiro populares: Lig4 e Reversi. A aplicação está estruturada em diferentes classes e módulos, cada um com responsabilidades bem definidas para garantir um código organizado e fácil de manter.

Estrutura e Funcionamento
    Cadastro: A classe cadastro é responsável pelo gerenciamento dos jogadores no sistema.

    Jogador: A classe jogador representa um jogador no sistema, armazenando informações essenciais.

    Jogo: A classe jogo é a classe base para todos os jogos de tabuleiro implementados. Ela define a estrutura básica do tabuleiro e oferece métodos fundamentais.

    Lig4: A classe herdeira Lig4 é uma implementação específica do jogo "Lig 4", um jogo em que os jogadores tentam formar uma linha de quatro peças no tabuleiro.

    Reversi: A classe herdeira Reversi implementa o jogo "Reversi", no qual os jogadores tentam capturar peças do adversário e virar elas para a sua cor.

Principais Funcionalidades
    Cadastro de Jogadores: O sistema permite a adição de novos jogadores, com verificação de apelidos únicos.

    Remoção de Jogadores: Jogadores podem ser removidos, com atualização imediata dos dados.

    Listagem de Jogadores: Apresenta uma lista completa de jogadores e suas estatísticas.

Gerenciamento de Jogos:
    Lig4: Jogo com tabuleiro de 8x8 onde os jogadores alternam movimentos para formar uma linha de quatro peças.

    Reversi: Jogo com tabuleiro de 8x8 onde os jogadores capturam e viram peças adversárias para ganhar pontos.

Dificuldades Encontradas
    Gerenciamento de Exceções: Garantir que todos os erros possíveis fossem tratados adequadamente foi um desafio. Isso incluiu operações de leitura e escrita em arquivos, onde a robustez do tratamento de exceções foi crucial para manter o programa estável.

    Validação de Jogadas: Implementar a lógica para validação e verificação de vitórias nos jogos de tabuleiro exigiu uma atenção cuidadosa aos detalhes para assegurar que as regras fossem aplicadas corretamente.

    Persistência de Dados: Manter a sincronização dos dados dos jogadores com o arquivo dados.txt e assegurar que todas as alterações fossem corretamente salvas e carregadas foi uma tarefa complexa.

    O grupo enfrentou várias dificuldades ao longo da realização do trabalho. Inicialmente, demoramos a entender como funcionavam os sistemas do git e do github, já que nunca havíamos utilizado-os. Além disso, enfrentamos dificuldades ao tentar bibliotecas e ferramentas diferentes como o doxygen e o doctest. Outro fator que dificultou a realização do trabalho foi o fato de alguns dos integrantes viajarem no periodo no qual estavam marcadas as ferias no início do ano, dificultando a realização conjunta durante alguns dias. 


Considerações finais:
    Todos cremos que o trabalho acrescentou muito na nossa formação, pois foi o primeiro projeto de maior porte de todos os integrantes do grupo. O trabalho precisou de uma organização maior, tanto na questão de planejamento quanto nos próprios arquivos de código, que utilizaram das classes e suas ferramentas. A organização para trabalhar em gupo também foi enriquecedora no geral. 
   
