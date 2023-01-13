# Ordens

Byron é pai de uma menina de quatro anos de idade, AABK (nome completo omitido de acordo com o Estatuto da Criança e do Adolescente). AABK, ao brincar
com seu pai, decidiu estabelecer uma ordem muito específica para enfileirar seus brinquedos. Primeiro, AABK quer ordenar por cores, considerando a ordem
alfabética entre os nomes das cores. Por exemplo, os brinquedos amarelos devem vir antes dos brinquedos rosa. Dentre os brinquedos de mesma cor, ele quer os
brinquedos de menor comprimento apareçam antes. Por fim, caso haja empate nos dois primeiros critérios, ela quer que o brinquedo que ela mais goste esteja
localizado antes dos que ela gosta menos.

O problema maior dessa brincadeira é o fato de que Byron não entende nada de ordenação e nunca ouviu falar sobre “algoritmos”. O negócio dele é poesia.
Sua missão é ajudar nosso amigo poeta a organizar os brinquedos de sua filha na ordem que ela tanto gostaria. O trabalho completo deve conter quatro implementações: 
bubble sort, insertion sort, merge sort e quick sort.

## Entrada
Você receberá um valor n (0 < n ≤ 106), correspondente ao número de brinquedos de AABK (sim, ela tem muitos brinquedos, mas o pai dela é um lorde de
tão rico). A seguir, são apresentadas n triplas (c, l, g), representando a cor, o comprimento e a nota que AABK dá para cada brinquedo. Especificamente, c ∊
(‘amarelo’, ‘azul’, ‘verde’, ‘vermelho’, ‘rosa’, ‘branco’, ‘preto’), l ∊ R (0 < l ≤ 103) e g ∊ R (0 < g ≤ 10).

## Saída
o índice do brinquedo (ordem em que foi apresentado na entrada, iniciando-se com 0) após a ordenação. Cada índice deve apresentar um “;” ao final. No fim da linha, 
imprima um “\n”.

## Análise Complexidade
- Bubble Sort:
  - Pior caso: O(n²)
  - Caso médio: O(n²)
  - Melhor caso: O(n)

- Insertion Sort:
  - Pior caso: O(n²)
  - Caso médio: O(n²)
  - Melhor caso: O(n)

- Merge Sort:
  - Todos os casos: O(n*log n)
 
- Quick Sort:
  - Pior caso: O(n²)
  - Caso médio: O(n*log n)
  - Melhor caso: O(n*log n)
