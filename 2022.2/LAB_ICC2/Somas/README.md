# Somas
Encontrar, a partir de um conjunto de elementos, um par que cumpra uma restrição específica é um problema muito comum em diversas áreas da
computação. Neste trabalho, você deve resolver o problema conhecido como 2-sum. Nele, você recebe um grande conjunto A de inteiros e algumas consultas.
Cada consulta consiste em um número inteiro k de forma que a resposta ao problema será positiva se houver quaisquer dois elementos distintos de A cuja soma seja k.

O trabalho completo deve conter três implementações. As versões deverão corresponder a diferentes versões de busca pelos complementares. Uma delas deve utilizar 
uma busca linear. Para a segunda, você pode escolher uma busca em lista ordenar (precisa ordenar antes) ou utilizar uma árvore binária de busca. Fica a seu critério, 
desde que explicite qual foi utilizada em seu relatório. Por fim, a implementação que deve ser apresentada no run.codes
deve utilizar uma hash table. Lembre-se de comparar essas implementações no relatório.

## Entrada
A entrada é iniciada por uma linha contendo um inteiro N (0 < N < 109), representando o número de elementos do conjunto A. Na linha seguinte, são
fornecidos os N valores inteiros distintos pertencentes a A. Após isso, se dá início às consultas, sendo que a primeira linha contém um inteiro M (0 < M < 106),
representando o número de consultas a serem feitas. A cada uma das próximas M linhas, há um inteiro k, para o qual deve ser encontrada a soma de par.

## Saída
Para cada uma das consultas, seu programa deverá imprimir ‘S’ caso seja possível encontrar a 2-sum de valor k no vetor A fornecidos na entrada. Caso
contrário, deve-se imprimir ‘N’.

## Análise Complexidade
- Busca Linear: O(n)
- Busca Ordenada: O(n)
- Busca Hash Table: O(1), praticamente independente do número de chaves armazenadas na tabela
