# Problema do Caixeiro Viajante
**Grupo:** Amanda Kasat, Lucas Omati(lucasomati@usp.br), Miguel Prates(miguel.prates@usp.br)

Nos últimos 50 anos, o Problema do Caixeiro Viajante (PCV) é um dos problemas mais estudados em otimização combinatória, representando, até hoje, 
um dos grandes desafios da Pesquisa Operacional. Isso porque, não só a questão do desempenho computacional tem atraído o interesse pelo PCV, como 
também  o fato de inúmeros problemas reais serem modelados como problemas do tipo caixeiro viajante ou suas variantes.

O PCV pode ser definido como o problema de encontrar o caminho de menor distância ou custo que passa por um conjunto de cidades, sendo que cada cidade
apenas pode ser visitada uma vez. Desse modo, o PVC consiste em basicamente encontrar a rota mais eficiente que: parte da cidade de origem, passe por 
todas as demais cidades uma única vez e retorne à cidade origem ao final do percurso.Esta rota também é conhecida como ciclo fechado Hamiltoniano, em 
homenagem ao seu criador, William Rowan Hamilton.

## Desenvolvimento do Código
Existem três TADs que auxiliam no funcionamento do programa. O primeiro, chamado DMconfig, possui a função de operar uma matriz capaz de criar uma 
estrutura de dados (DM_MATRIX) que guarda as dimensões da matriz e os dados dentro dela no formato de ITEM, que no caso, deixamos como float. Essa 
estrutura DM é utilizada para criar o “mapa” das cidades, possuindo, portanto, apenas as funções Get, Set, Free e uma para gerar caminhos aleatórios
através da Força Bruta, ou seja, usando Permutação. 

O próximo TAD é chamado de Connector, responsável por criar nós e linhas que conectam todas as cidades entre si. Dentro deste TAD, existe a estrutura 
NODE que guarda um id e um array dinâmico de ponteiros de LINEs. Esse array é  um outro tipo de struct que guarda a distância definida pelo tipo ITEM 
(definido na DM_MATRIX) e um ponteiro para um NODE. 

Além dessas duas, existe a estrutura principal do TAD, chamada WEB, que é responsável por guardar todos os NODEs, sua quantidade, um nó que marca a 
posição atual do navegador e outro que marca o seu ponto de partida. No início da função main é chamado a função web_create para criar todos os NODEs 
a partir de várias chamadas da função node_create_connection, criando uma ponte entre o primeiro nó e o segundo.

Depois de inicializada, a WEB está pronta para utilizar métodos como o web_trymove, que movimenta o navegador para uma linha “i” a partir do seu NODE 
atual, e o web_trypath, que faz uma combinação de caminhos pelo qual o navegador deve se movimentar, ambos responsáveis por toda a parte de navegação. 
Vale lembrar que, por padrão, esses métodos retornam “false” caso uma linha tenha uma distância ITEM<0, pois nesse caso, o caminho não existiria.

Por fim, existe o “Pathfinder”, um TAD que possui uma struct “WALKER” que guarda a combinação atual, a melhor combinação, a distância atual e a melhor 
distância. Essa struct, usada juntamente com um WEB, pode rodar o método principal do programa que é o walker_run, que utiliza um heap permutation para 
gerar todas as combinações de um array que inicialmente começa com um padrão crescente.

A main.c utiliza o Pathfinder.h para criar uma estrutura DM_MATRIX, inicializando todos os elementos como -1, para após isso setar as distâncias a
partir das informações do arquivo lido. Após isso, a partir das funções explicadas anteriormente, é criado um “mapa”, que por sua vez é utilizado 
para criar uma *WEB que depois é usado para rodar em conjunto com um *WALKER.

## Análise de Complexidade
Começando pela análise do arquivo “Connector.c”. A função node_free possui complexidade O(n), pois trata-se da exclusão de uma linha, da matriz, ou
seja um array. Já para a criação da matriz, ou seja, o nó, a complexidade é O(n), mas para o estabelecimento das conexões o custo é O(n²), pois há 
um for dentro de outro for. Outra função com custo O(n²) é a função web_showconnections. Já a função web_findnodebyid, por usar busca sequencial, 
tem custo médio de O(n/2), mas no pior caso tem custo O(n) e no melhor caso tem custo O(1). Por último, a função web_trypath possui custo O(n) pois 
possui um único for.

Em seguida, analisando o arquivo “Pathfinder.c”. As funções walker_setbest e walker_printpath possuem custo O(n). Já a função heapPermutation é a 
função com maior custo no programa, pois ele calcula todas as permutações possíveis do nosso problema, por isso seu custo é O(n!), vale salientar 
que essa função é utilizada também na função walker_run, sendo assim, as duas possuem a  mesma complexidade. Já a função walker_getpreset tem 
complexidade O(n³), pois no pior caso o while dentro do for pode ir até n², embora isso possa acontecer apenas uma vez. A função de imprimir tem custo 
O(n) pois depende da quantidade de cidades do problema. 

Já o arquivo “DMconfig.c”, possui apenas duas funções significantes para a nossa análise, a matrixconfig_create e a matrixconfig_print, e ambas possuem 
complexidade O(n²).
Por último, o arquivo principal, o “main.c”, possui apenas uma função relevante para a análise do tempo, que é a de criação do mapa, que possui custo 
O(n). Vale salientar  que nem todas as funções dos quatro arquivos analisados foram citadas, pois algumas tem custo insignificante para a análise 
assintótica. Portanto, segue o gráfico do tempo de execução em função do número de cidades, obtido através do procedimento descrito no próximo tópico 
usando o geogebra classic. 

Dessa forma, podemos concluir que a função com maior influência no tempo de execução do código é a função heapPermutation com custo O(n!), complexidade 
que é comum ao se usar força bruta para resolver o problema, afinal força bruta é o método menos efetivo de solução na grande maioria dos problemas. 
Sendo assim, é comum, ao tentar resolver o Problema do Caixeiro Viajante, usar outros métodos, como algoritmos genéticos ou outros algoritmos.

