# Hitbox
O objetivo do programa é receber da entrada padrão informações relativas a dois retângulos e informar na saída se esses retângulos se intersectam. 
Se eles se intersectarem, imprimir o retângulo da área de intersecção.

![area](https://user-images.githubusercontent.com/100383925/210907964-f024376b-c097-4f35-b351-fe37998d8ca2.jpg)

## Entrada
O programa recebe de entrada a informação de dois triângulos. O formato da entrada são duas linhas, cada uma com os dados de um dos retângulos. 
Em cada linha, quatro números estarão dispostos separados por espaço: [x] [y] [largura] [altura]

## Saída
Caso os retângulos não se toquem imprima **MISS**, caso eles se toquem ou até se atravessem, imprima **HIT: [x] [y] [largura] [altura]**, 
onde os valores [x] [y] [largura] [altura] descrevem o retângulo de intersecção entre os dois retângulos fornecidos

## Observações
Para qualquer retângulo usaremos o ponto (x, y) para representar o vértice superior esquerdo do retângulo. Além disso, nesse sistema de coordenadas 
os valores de x crescem para a direita enquanto os valores de y crescem para baixo. Ou seja, se tivermos os pontos O = (0, 0) e A = (10, 10), 
A se encontra em baixo e a direita do ponto O. A largura é simplesmente a extensão do retângulo do eixo x e a altura a extensão do retângulo no eixo y

Se os dois retângulos se tocam mas a área da intersecção é 0, isso ainda conta como um HIT. Ou seja, é possível que na saída largura e/ou altura sejam 0.
