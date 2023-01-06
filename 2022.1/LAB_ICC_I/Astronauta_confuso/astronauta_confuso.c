#include <stdio.h>

int main(void) {
  int lado, distancia_total, distancia_atual = 1, aux = 0;
  int x = 0, y = 0;
  scanf("%d %d", &lado, &distancia_total);

  if (lado * lado < distancia_total){
    printf("O astronauta ja saiu em missao ha %d chamadas.\n", distancia_total - lado * lado);
  }
  else {
  while(distancia_atual < distancia_total){
    for (int i = aux + x; i < lado - 1; i++){
      if (distancia_atual >= distancia_total){break;}
      x++;
      distancia_atual++;
    }
    while (y < x){
      if (distancia_atual >= distancia_total){break;}
      y++;
      distancia_atual++;
    }
    while (x > aux){
      if (distancia_atual >= distancia_total){break;}
      x--;
      distancia_atual++;
    }
    while (y > x + 1){
      if (distancia_atual >= distancia_total){break;}
      y--;
      distancia_atual++;
    }
    aux++;
  }
    printf("O astronauta esta na posicao: %d %d\n", y, x);
  if (lado * lado == distancia_total){
    printf("Preste atencao, astronauta, chegou a sua vez!\n");
  }
  else{
    printf("Ainda faltam %d chamadas para a sua vez!\n", lado * lado - distancia_total);
  }
}

  return 0;
}
