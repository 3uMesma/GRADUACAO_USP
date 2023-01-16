# Catalogando Vinhos
Ricardo sempre foi um grande amante de vinhos, então logo após terminar a escola, iniciou sua graduação em química no IQSC. Durante todo
esse período, participou de uma pesquisa para catalogar as características químicas de mais de 500 vinhos e organizou-as em um único arquivo csv.
Com o fim da catalogação, Ricardo percebeu que não tinha estabelecido nenhum critério de organização dos vinhos catalogados. Dessa forma, se
tornava muito lento o trabalho de verificar a existência de determinado valor para uma característica ou quantos vinhos possuíam o mesmo valor da
característica buscada.

Com medo de perder todo seu intenso trabalho, Ricardo foi até o ICMC buscar ajuda de seus estimados estudantes para possibilitar esta tarefa tão
crucial.

## Objetivo
Desenvolva um programa em C que leia todos os dados de um arquivo csv e possa realizar busca e contagem dos vinhos com o valor da característica
escolhida quantas vezes forem desejadas.

## Entrada
A entrada que seu programa irá ler será organizada da seguinte forma:
- Nome do arquivo csv;
- Número de buscas sobre o arquivo;
- Nome (string) e valor (double) da característica selecionada (n vezes, de acordo com o número de buscas).
  - As características que podem ser selecionadas são: ID, acido_citrico, acucar_residual, densidade, PH , alcool.

## Saída
Para cada busca, todas as características do primeiro vinho (no vetor ordenado) que possui os parâmetros buscados e a
quantidade de vinhos que também possuem o mesmo valor buscado.

## Observações
- Para guardar as características de cada vinho na memória utilizei vetor de struct
- A busca pelos vinhos foi realizada a partir da busca binaria
- A ordenação do vetor de struct foi realizada pelo método merge Sort
- Como qualquer característica (ID, acido_citrico, acucar_residual, densidade, PH , alcool) pode ser escolhida para a ordenação, e a 
ordenação ocorre a cada busca, generalizei criando uma característica extra na struct, chamada aux. Sua função é ser uma cópia da característica que
se deseja ordenar, servindo de parametro para o método Merge Sort
