# Operações sobre Conjuntos
Para desenvolver a lógica do conjunto foram utilizadas árvores, pois as operações de busca, inserir e outras podem ser realizadas mais facilmente com 
uma complexidade linear, O(log(n)). Outrossim, cada nó da nossa árvore possui como informação uma outra struct item, que contém o número desejado. 
Escolhemos usar uma struct pois assim poderíamos generalizar mais facilmente para outros tipos de informação como char, float e assim por diante. 

## Funções
- Criar um conjunto
- Apagar um conjunto
- Inserir um elemento em um conjunto
- Remover um elemento de um conjunto
- Imprimir os elementos/itens armazenados no TAD
- Pertence (um elemento está presente ou não no conjunto)
- União
- Intersecção

## Análise de Complexidade
Nesse projeto, desenvolvemos algumas funções para poder realizar operações nos conjuntos, dentre elas operações básicas, para podermos manipular a 
árvore e as específicas, que são as operações sobre conjuntos em si, segue abaixo a complexidade de cada uma delas, em notação Big Oh. Usamos a 
constante “a” para operações aritméticas e “c” para comparações, sendo que as duas possuem o mesmo peso:

1. Operações básicas:
- Criar conjunto: 
  - **Recorrência:** 3a
  - **Complexidade:** O(3)
  - **Tipo:** constante
- Apagar conjunto:
	  - **Recorrência:** c + a
  - **Complexidade:** O(2)
  - **Tipo:** constante
- Inserir um elemento no conjunto:
	- **Recorrência:** 5log(n) + 14
  - **Complexidade:** O(log(n))
  - **Tipo:** logarítmica
- Remover um elemento do conjunto:
  - **Recorrência:** 5log(n) + 21
	- **Complexidade:** O(log(n))
	- **Tipo:** logarítmica
- Imprimir o conjunto:
  - **Recorrência:** 4c
  - **Complexidade:** O(4)
  - **Tipo:** constante

2. Operações Específicas:
- Buscar elemento no conjunto:
  	- **Recorrência:** log(n) * 4c = 4log(n)
	- **Complexidade:** O(log(n))
	- **Tipo:** logarítmica
- União entre dois conjuntos:
	- **Recorrência:** nlog(n) + 2
	- **Complexidade:** O(n*log(n))
- Intersecção de dois conjuntos:
	- **Recorrência:** nlog(n) + 2
  - **Complexidade:** O(n*log(n))

