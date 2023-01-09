# Caixeiro Viajante com Algortimo Genético
** Grupo: Amanda Kasat(kasatamanda@gmail.com), Lucas Omati(lucasomati@usp.br), Miguel Prates(miguel.prates@usp.br)

Nossa ideia de solução mai eficiente para o PVC consiste em usar o algoritmo Monte Carlo (entitulado no projeto de walker_run2). Seu funcionamento é 
basicamente o seguinte (considerendo q_walkers = 50, q_shuffles = 20 e q_cidades = 12):

O método cria 50 walkers e começa a rodar um ciclo que vai de 0 até 11 (qcidades-1). A cada ciclo (contado por D), ele forma um preset (array formado 
por uma combinação fixa no começo, dada pelo melhor caminho já formado, e o restante que o completa). Ex: se o caminho está sendo formado em 
[2,4,-1,-1,-1 …] o preset será [2,4,0,1,3,5…].

Inicia um ciclo de 0 até “q_walkers” (contador w). Para cada walker, este é resetado e seu path_atual é copiado para ser igual ao preset. Depois, inicia
um ciclo que vai de 0 a q_shuffles (0 a 20 no caso) e a cada rodada, ele mistura o path atual (mistura apenas os números que não foram dados pelo preset).
Exemplo:
Se o preset era: [2,4,0,1,3,5,6,7 …], ele forma combinações como:
 [2,4,1,3,6,7,8,9…], [2,4,0,5,3,7,6…], [2,4,5,8,11,10,3,6…]
 
A cada combinação diferente, o walker tenta andar por essa combinação (seta a distancia, reseta a web, caso seja melhor salva etc). Logo, após esse ciclo,
fica salvo no walker a melhor combinação do ciclo. Dessa melhor combinação, o index de um vetor de ITEM soma seu valor atual com o index 0 do melhor 
caminho achado. Ex: se o melhor caminho achado for [2,4,5,3,1,0…] que dá uma distância “dist” o vetor de ITEM recebe: vet[2] += dist

Depois de rodar todos os walkers de um ciclo D, ele verifica qual é index de menor valor. Esse menor valor, é colocado como preset do próximo movimento.
Como resultado final, a ideia do programa é fazer com que os walkers acham uma boa solução aleatoriamente, verificar qual é a melhor probabilidade dela 
ser a melhor, depois setar ela nos walkers como um fixo e rodar eles de novo, fazendo isso até que se chegue em um vetor “bom” que passa por todas as 
cidades. O de força bruta, demorou cerca de 7.29 segundos para concluir de 12 cidades (caso de teste 3), obtendo do melhor caminho (igual ao runcodes: 
9 3 7 12 4 6 8 10 11 1 2 5 9), uma distância de 761. Já esse novo algoritmo, com uma configuração que roda 500 walkers ao mesmo tempo e cada um faz 20 
tentativas, demorou 0.04 segundos e obteve uma distância de 776 (caminho: 9 5 2 1 11 10 4 6 8 12 7 3 9 ). Observe que, ao colocar os dois algoritmos 
lado a lado, o novo algoritmo (com a configuração de 500/20) só demora o mesmo tempo que o de força bruta quando o número de cidades passa de 130:
