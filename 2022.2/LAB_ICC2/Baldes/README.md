# Baldes

Novamente, não há história. É bucketsort! Este trabalho pede “apenas” que uma sequência de N elementos com ponto flutuante (0 < N < 106). Além disso, seu
programa deve receber um valor M (0 < M < 100), indicando o máximo que cada elementos pode receber (o mínimo sempre será 0), e um inteiro B (0 < B < 25),
indicando quantos buckets você deve usar. Para isso, a primeira linha contém os valores N, M e B, nessa ordem. Na próxima linha, você deve ler os N valores com
ponto flutuante. A sua saída deve conter uma sequência ordenada desses N números. O trabalho completo deve conter duas implementações. As versões deverão corresponder 
ao bucketsort e ao merge ou quicksort. 

## Análise de Complexidade
- Bucket Sort:
  - Pior Caso: O(n²)
  - Caso Médio: O(n)
  - Melhor Caso: O(n)
- Merge Sort:
  - Todos os casos: O(n*log n)
