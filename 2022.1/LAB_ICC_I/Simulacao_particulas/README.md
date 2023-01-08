# Simulação de Partículas

Matilda é uma desenvolvedora de jogos muito habilidosa, e recentemente iniciou o maior de seus projetos: a criação de um motor de jogos. Uma ideia ambiciosa, 
certamente, mas muito possível com seus talentos de programação. Os jogos favoritos de Matilda são jogos com cenários destrutivos e cheios de interações dinâmicas 
com o mundo. Para isso ela percebe que precisará implementar alguns sistemas independetes: um módulo de renderização que mostra coisas na tela, e outro de física 
que seja capaz de calcular as interações entre os diferentes objetos.

Apesar de sua empolgação, Matilda nunca realmente fez um motor de jogos com as próprias mãos e resolve começar pequeno. Talvez ela possa aprender algo a partir dali 
e expandir cada vez mais até chegar no nível que ela quer. Foi assim que ela pediu a sua ajuda para implementar essa primeira versão. Essa versão, consiste de um 
sistema no qual todos os objetos são conjuntos de partículas. Existem 4 tipos diferentes de partículas e elas interagem entre si para formar um ambiente dinâmico.

O motor de jogos consiste de um loop que itera por frames. Um frame é uma representação visual do estado do jogo naquele momento e é essa representação que deve ser
impressa na tela. Depois de imprimir o frame, o estado do jogo deve ser atualizado de acordo com as regras da física desse mundo (descritas abaixo).

Faça um programa em C que rode uma simulação com as regras descritas abaixo. Para isso, uma matriz de 32 linhas e 64 colunas deve ser criada, onde cada elemento é do 
tipo char. A cada frame essa matriz deve ser imprimida na tela, isso é, cada linha imprimida como uma string e ao final dela um caractere '\n' para indicar o final da 
linha. Após isso, uma função de aplicar física será executada. Essa função atualizará a matriz para ser impressa no próximo frame.

Cada caractere dessa matriz representará uma partícula que possui como posição o seu índice na matriz. Por exemplo, a partícula na posição (10, 20) é representada pelo 
caractere em mat[20][10] (repare que usamos mat[y][x]), onde mat é a matriz mencionada.

## Entrada
Na entrada padrão serão fornecidos alguns valores. Na primeira linha será fornecido o número de frames que sua simulação deve calcular e imprimir. As linhas subsequentes
seguirão o seguinte formato: <frame>: <x> <y> <char>. Onde <frame> é o frame no qual o caractere <char> deve ser posto na posição (<x>, <y>)da matriz. Tanto <x> quanto
<y> são números inteiros. Os valores na posição <frame> são sempre crescentes.
  
## Partículas
Existem 4 tipos de partículas representadas por caracteres: Areia (#), Água (~), Cimento (@) e Ar (<espaço>). Cada uma dessas partículas possui um comportamento diferente
que poderá mudar sua posição na matriz na hora de aplicar a física.
- Cimento: Ela nunca se move. Uma vez que ela for posicionada na matriz, ela nunca sairá daquela posição
- Ar: também não faz nada. Entretanto, ela pode ser movida de lugar por outras partículas como veremos abaixo
- Areia: sofre os efeitos da gravidade e deve seguir a algumas regras na hora de aplicar a física. Algumas posições adjacentes a essa partícula serão verificadas 
  e, se essa posição estiver sendo preenchida por água ou ar, a areia troca de lugar com essa partícula adjacente. Isso é como dizer que a areia é mais pesada que 
  água e ar. As posições adjacentes a serem verificadas em ordem são:

  1. Posição imediatamente abaixo.
  2. Posição à esquerda abaixo.
  3. Posição à direita abaixo.
  
  
  

