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
