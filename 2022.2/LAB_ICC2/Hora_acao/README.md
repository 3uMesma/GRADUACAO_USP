# Hora de Ação
Jaques e Fino são dois caras que não estudaram direito, pois estão sempre muito ocupados imaginando que têm que salvar uma tal de Terra de Uuu. Nas horas
vagas, eles competem em um jogo que chamaram de jogo das gomas. O jogo consiste em, dada uma sequência de gomas com diferentes tamanhos, Jaques e
Fino se alternam trocando gomas consecutivas que estão em posições invertidas. Mais especificamente, uma goma A está “invertida” com uma goma B se ela
aparece antes que B na sequência, mas é maior que a goma B. Em outras palavras, se a sequência está organizada de tal forma que nenhuma goma seja maior 
que sua vizinha da direita, então não há inversões. Ainda, só é possível trocar duas gomas de posição se elas estão em posições consecutivas na sequência.
O jogo sempre começa com Jaques. Ganha aquele que fizer a última troca, deixando a sequência sem qualquer par de gomas invertidas.

Escreva um programa que, dada uma sequência de tamanhos de goma, imprima se o ganhador do jogo será Fino ou Jaques. Para isso, siga os formatos de 
entrada e saída padrão descritos a seguir.

## Entrada
A entrada contém vários casos de teste. Os dados de cada caso de teste estão numa única linha, e são inteiros separados por um espaço em branco. Cada
linha contém um inteiro N (2 ≤ N ≤ 105), seguido da sequência inicial P = (X1, X2, ...,XN) de N inteiros distintos, onde 1 ≤ Xi ≤ N para 1 ≤ i ≤ N. 
O final da entrada é indicado por uma linha que contém apenas o número zero.

## Saída
Para cada caso de teste da entrada seu programa deve imprimir uma única linha, com o nome do vencedor, igual a Jaques ou Fino, sem espaços em branco.

## Análise de Complexidade
Como solução do exercício, desenvolvi duas formas de ordenação, usando o algoritmo Bubble Sort e outra usando o Merge Sort. Em comparação com a outra, 
a versão usando o Bubble é a mais complexa, com complexidade O(n²). Enquanto que a versão usando o Merge possui complexidade  O(n log(n)). É interessante
comentar que essa diferença de eficiência entre os dois acontece pois o Bubble Sort é um algoritmo iterativo, com um for  dentro de outro for, enquanto 
que o Merge é um algoritmo recursivo que utiliza o método dividir para conquistar.  Vale salientar que o pior caso usando o Bubble Sort é quando o vetor 
está ordenado em ordem decrescente, já que, nessa situação, o número de comparações e trocas é igual a n(n - 1). Já para o Merge Sort, independentemente 
se for o melhor ou o pior caso, a complexidade será sempre a mesma.  Essa diferença de complexidade entre as duas, pode não parecer tanto em casos 
de teste pequenos, mas se considerado vetores de tamanho considerável, temos uma grande diferença.
