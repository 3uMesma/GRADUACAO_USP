# Astronauta Confuso
Em 2050 uma nave espacial partiu a fim de colonizar um novo sistema planetário há poucos anos-luz do planeta Terra, atalhando por um buraco de minhoca. 
Chegando lá, a tripulação observou alguns fenômenos um tanto curiosos. Caso mais de um astronauta saísse da nave em missão simultaneamente, apenas um retornava com vida.
Portanto, foi criado um sistema para controle de missões em que apenas um astronauta era escalado em uma missão por vez, de maneira sequencial ao ingressar em uma fila de espera.

Embora todos fossem muito inteligentes, atalhar por este buraco de minhoca alterou de alguma forma a percepção espacial dos tripulantes. 
Ninguém mais conseguia interpretar sua posição na fila de espera a partir de apenas um número sequencial [1...L], onde L é o número de lugares na fila. 
Todos precisavam de uma representação numérica de 2 números.

Por este motivo, o time de engenheiros projetou a câmara de saída da nave espacial em um formato matricial, mas com formato de pirâmide para preservar a aerodinâmica da nave. 
Ou seja, assim a fila poderia ser representada em duas dimensões. A ideia desta equipe de engenheiros foi estruturar o formato da fila seguindo uma organização parecida com uma espiral,
as posições sendo definidas por posição = [0...N-1][0...N-1]. Embora fosse um formato um tanto peculiar, a câmara oferecia uma visão 360 do universo, a qual até que agradava bastante aos tripulantes.

A orientação do deslocamento da fila será similar a uma espiral, caminhando da posição (0, 0) até o final da linha, baixando até o final, voltando à esquerda e retornando ao início, conforme a ilustração a seguir:

![astrounata](https://user-images.githubusercontent.com/100383925/210920140-4fdd48c5-7493-42ee-89c9-930e5fb3977c.jpg)

## Entrada
Dois parâmetros relativos ao projeto da câmara espacial e à posição de um astronauta qualquer na fila de espera. O primeiro parâmetro é a quantidade de 
lugares a serem projetados na câmara de saída da nave espacial pelos engenheiros responsáveis. Leia N e calcule o número de lugares L da seguinte forma: 
L = N * N. O segundo parâmetro é um número P que representa a quantidade posições na fila que já foram deslocadas pelo astronauta atual.

## Saída
- Caso o número de pessoas seja maior que o total de lugares na fila, ou seja P > L, imprime **"O astronauta ja saiu em missao ha %d chamadas.\n"**
- Caso seja a vez do astronauta imprime **"O astronauta esta na posicao: %d %d\nPreste atencao, astronauta, chegou a sua vez!\n"**
- Caso contrário, imprime na tela a posição do astronauta na fila, seguido pelo número de deslocamentos necessários até que chegue a sua vez de sair em
missão da seguinte forma: **"O astronauta esta na posicao: %d %d\nAinda faltam %d chamadas para a sua vez!\n"**
