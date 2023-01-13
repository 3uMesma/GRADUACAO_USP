# Boa Sorte

Dessa vez, não há história. Este trabalho pede “apenas” que uma sequência de N valores (0 < N < 109). Para isso, primeiro deve ser lido o valor N e, na próxima
linha, ler N valores inteiros. A sua saída deve conter uma sequência ordenada desses números.

O trabalho completo deve conter três implementações do quicksort e um relatório. As versões deverão corresponder ao algoritmo mais simples (pivô no início
ou fim, sem trocas) e duas alterações que tendem a evitar o pior caso (como escolha aleatória do pivô, embaralhamento ou mediana de três).

## Análise complexidade
A primeira implementação do quicksort é a implementação mais simples, basicamente eu estabeleci o pivô como o último elemento e fiz a partição através do método de Lomuto. O pior caso desse tipo de ordenação é quando o pivô divide a lista em duas outras desbalanceadas, ou seja, uma sublista com tamanho 0 e outra com tamanho n-1. Isso acontece, no nosso caso, quando a lista está inversamente ordenada, pois o pivô será o menor elemento da lista. Já o melhor caso acontece quando a partição gera duas sublistas de tamanho n/2 e (n-1)/2. Dessa forma, a complexidade do pior caso é O(n²) e no melhor caso ou caso médio é O(n * log(n)).

A outra forma escolhida para implementar o quicksort foi usando um pivot aleatório. Isso porque ao escolher um pivot aleatoriamente a probabilidade dele ser o menor, ou seja, dele ser o pior caso, é de 1/n. Desse meno, a compleixdade no caso médio, no pior caso e no melhor caso continuam as mesmas, mas a probabilidade de escolhermos o pior caso é muito pequena em comparação com o quicksort padrão. Nessa particição eu escolhi o primeiro elemento como pivot.

Por fim, a última implementação do quick sort foi usando um pivot a partir da mediana de três. Dentre os outros métodos citados, esse foi o mais rápido e sua implementação consistiu em calcular a mediana, a partir do primeiro valor do vetor, o valor do meio e o valor final, trocar-la com o elemento da última posição do vetor e então executar o algoritmo normalmente. A complexidade dele continua sendo a mesma do quicksort para o melhor, o pior e o caso médio. Entretanto, a probebilidade do pior caso ocorrer é ainda menor que 1/n, pois o resultado da mediana pode nem sequer ser um elemento do vetor. 
