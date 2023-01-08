# Pokedex
Está acabando o semestre, e você não vê a hora de dar um fim aos estudos e voltar à sua jornada para se tornar um mestre Pokémon!
Mas antes, o professor Carvalho acaba de te passar uma missão para ajudá-lo!

Você deverá criar a estrutura de uma Pokedéx para ajudá-lo a estudar os Pokémons!
Cada Pokémon terá:
- Nome (máximo de 50 caracteres)
- Tipo primário(máximo de 20 caracteres)
- Tipo secundário(máximo de 20 caracteres)
- Uma lista de atributos (ou status)
- Uma lista de 4 ataques possíveis

É claro que como um bom treinador você sabe que será mais fácil que os atributos e os ataques do Pokémon estejam em estruturas próprias, sendo que os atributos 
contém 6 inteiros:
- HP
- Ataque
- Defesa
- Ataque Especial
- Defesa Especial
- Velocidade

E cada ataque possui os seguintes atributos:
- Nome (Máximo de 20 caracteres)
- Poder base (inteiro)
- Acurácia (float)
- Classe (char: 'p' para físico, 's' para especial)

## Funções
- Cadastrar um novo Pokémon (sem seus ataques):
  - Nome do Pokémon
  - Tipo primário
  - Tipo secundário
  - HP
  - Ataque
  - Defesa
  - Ataque especial
  - Defesa especial
  - Velocidade

- Adcionar um ataque à lista de 1 Pokémon específico:
  - Índice do Pokémon no vetor
  - Índice do ataque no vetor de ataques do Pokémon (de 0 a 3)
  - Nome do ataque
  - Poder base do ataque
  - Acurácia do ataque
  - Classe do ataque

-  Imprimir os dados de um Pokémon adicionado
-  Imprimir os dados de um ataque específico de dado Pokémon
