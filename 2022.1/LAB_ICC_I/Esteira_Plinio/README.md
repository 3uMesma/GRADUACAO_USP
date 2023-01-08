#  A Esteira de Plínio

Plínio é um robô de manutenção que foi encarregado da tarefa de verificar o correto funcionamento das esteiras de uma fábrica. Seu trabalho é viajar em cima
das esteiras verificando se elas estão indo para os devidos lugares. Existem alguns tipos de erros que podem ocorrer na esteira. A esteira pode terminar antes 
de chegar em seu destino, caso no qual Plínio deve alertar **Falha na esteira**, ou uma esteira pode se conectar em si mesma, criando um loop infinito. Nesse caso,
Plínio deverá alertar **Loop infinito** . Caso a esteira chegue em seu devido destino, o robô diz **Ok**.

 Escreva um programa que leia como entrada a disposição das esteiras da fábrica e verifique se essa esteira contém loops infinitos, possui falha, ou está correta. 
 Imprima na saída padrão a mensagem de o robô diz. A fábrica é representada por uma matriz de 32 x 64 caracteres, ou seja, 32 linhas e 64 colunas e é como uma imagem
 de cima da fábrica. Cada caractere da matriz representa uma parte de uma esteira:
 
| Caractere     | Função        |
| ------------- | ------------- |
| > | Esteira que vai para a direita |
| < | Esteira que vai para a esquerda |
| ^ | Esteira que vai para cima |
| v | Esteira que vai para baixo |
| # | Junção |
| [ | Começo de esteira |
| ] | Fim de esteira |
|  |  Espaço em branco |

Por exemplo, considere a seguinte fábrica:
![esteira](https://user-images.githubusercontent.com/100383925/211207800-36906ba0-d4aa-407b-b533-da929e14f338.jpg)

O robô dever deixar uma marca pelos lugares que passar, substituindo o caractere naquele lugar da matriz por um '.' Fazendo isso, se o robô encontrar um '.' em seu caminho, sabe que já passou por ali antes e, portanto, há um loop! Há apenas uma exceção. Quando Plínio vê um '#' ele não substitui por '.' pois sabe que pode passar duas vezes pela mesma junção.

## Entrada
O programa receberá como entrada 32 linhas, cada uma com 64 caracteres mais um para o '\n' que indica o final da linha.

**Atenção:** Cada linha possui caracteres espaçados. Esses caracteres nas colunas de índice ímpar não devem ser considerados.

## Saída
A saída deve ser a mensagem de Plínio numa linha e em seguida uma impressão da matriz com as marcações feitas pelo robô.

## Observações
- O caractere imediatamente à direita do começo sempre será uma esteira
- Se o robô chegar no caractere final, sempre será pela direita
