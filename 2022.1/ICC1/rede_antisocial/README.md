# Rede Antisocial
## Entrada
Nesta rede, os dados de entrada estão disponíveis em um arquivo texto com a seguinte estrutura:

![entrada](https://user-images.githubusercontent.com/100383925/210899727-5e13fac3-eac5-4550-8161-d4c6660c61ff.jpg)

## Funções
- Imprimir as relações de inimizades para todas as pessoas que tenham o sobrenome em comum
- Converter inimizades para um dado ID informado pelo usuário
- Identificar possíveis amigos de um ID informado
- Ordenar as pessoas conforme o sobrenome, em ordem decrescente

## Complexidade das funções
- Alocar nomes: O(n)
- Alocar inimizades: O(n)
- Imprimir relações de inimizade: O(n²)
- Trocar inimizade: O(7)
- Possíveis amigos: O(n²)
- Ordenar sobrenome: O(n²)

## Observações
- A regra de conversão é: se o primeiro nome do meu inimigo possui pelo menos dois caracteres em comum com meu primeiro nome (em qualquer ordem), então não é mais inimigo
- A regra para gerar amigos é: o inimigo do meu inimigo é meu amigo, desde que não seja meu inimigo
- O método de ordenação é o BubbleSort
