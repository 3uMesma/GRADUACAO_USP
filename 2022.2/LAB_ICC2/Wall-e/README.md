# Onde está Wall-e?
Este trabalho tem por objetivo avaliar algoritmos de busca (pesquisa). Para isso, você deve receber um conjunto de k (0 < k ≤ 106 ) valores inteiros. 
Após a definição do valor de k, a entrada consiste em k números inteiros, que compõem o conjunto de valores “válidos”. A seguir, a entrada contém um 
número inteiro q (0 < q ≤ 106 ), que representa o número de consultas a serem feitas. Cada uma das próximas q linhas contém um inteiro representando 
número a ser buscado dentre os k valores lidos anteriormente. Caso esse número seja encontrado, sua saída deve conter uma única linha com a palavra 
“Encontrou”. Caso contrário, seu programa deve imprimir “Nao encontrou”.

O trabalho completo deve conter duas implementações e um relatório. As versões deverão corresponder à busca sequencial e à busca binária. Para evitar
que a ordenação represente um gargalo no tempo de execução, deixe o bubble sort para a próxima entrega. Use a função qsort, apresentada em aula.

## Análise de complexidade
Para reduzir um pouco o tempo de execução, fiz a função sequencial por meio de uma função recursiva. Mesmo assim, o tempo de execução entre o método 
de busca binária e o método de busca sequencial são extremamente discrepantes. Isso porque o algoritmo de busca linear é um algoritmo O(n), enquanto 
o de busca linear é O(log2 n), onde n é o tamanho do vetor. Vale salientar, que no pior dos casos, a busca sequencial vai ter que percorrer todos os
elementos da lista, enquanto a busca binária seria bem mais rápida nesse ponto.
