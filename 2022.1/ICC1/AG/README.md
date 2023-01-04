# Algoritmo Genético Simplificado
Algoritmos Genéticos (AG) são técnicas de procura e otimização baseado em mecanismos de seleção natural. Eles permitem a abordagem de problemas complexos
sobre os quais existe pouca informação, isso porque os AG não trabalham diretamente com o domínio do problema, mas com representações dos seus elementos. 
A ideia do nosso programa é resolver algum programa matemático que permita avaliar o quão próximo o indivíduo está da solução, para isso escolhi uma equação de quinto grau que possui a seguinte forme geral:

**ax⁵+bx⁴+cx³+dx²+ex+f = 0**

A qualidade da solução indica o quão próximo o indivíduo está de ser uma raiz da equação.

### Entrada do programa
- Tamanho da população;
- Taxa de Mutação;
- Número máximo de gerações;
- Constantes(a, b, ..., f) da equação;

### Complexidade das funções principais
**Criar o vetor inicial aleatório:** O(n)  <br />
**Calcular fitness:** O(n)  <br />
**Ordenar vetor:** O(n²)(.) e O(n * log(n))(..)  (...) <br />
**Gerar filhos:** O(n) <br />

(.) -> pior caso <br />
(..) -> melhor caso <br />
(...) -> a probabilidade do pior caso ocorrer é menor que 1/n, pois o resultado da mediana pode nem sequer ser um elemento do vetor <br />


### Observações relevantes
- Foi utilizada uma struct pra guardar a informação do número em si e seu fitness
- A população do Ag é composta apenas por números inteiros, sejam eles negativos ou positivos
- O fitness foi calculado a partir do resultado da equação, substituindo x por o indivíduo em questão, logo, qaunto menor o fotness, mais próximo aquele número está do resultado
- Para saber os melhores candidatos foi utilizando o método de ranking, cuja ordenação foi feita através do quick sort mediana de três
- Para criar a proxima geração, mantive metade do vetor original, composta pelos melhores pais e a outra metade completei com sesu filhos
- Na hora de criar o filho, os pais eram escolhidos aleatoriamente desde que fizessem parte da melhor parte do vetor
- Para o crossing over, aleatoriamente foi pegando um gene do pai e um gene da mãe e colocando no gene do filho
- Para a mutação, percorri os bits do filho e caso fosse ocorrer mutação, eu trocava esse bit
