#include <stdio.h>

int main(void) {
  long long int x1, y1, largura1, altura1;
  long long int x2, y2, largura2, altura2;

  scanf("%lld %lld %lld %lld", &x1, &y1, &largura1, &altura1);
  scanf("%lld %lld %lld %lld", &x2, &y2, &largura2, &altura2);

  long long int maior_x, maior_y, maior_l, maior_a;
  long long int menor_x, menor_y, menor_l, menor_a;

  long long int x_final, y_final, l_final, a_final;

  // definindo o maior ret e o menor
  if (x2 >= x1){
    maior_x = x2;
    maior_y = y2;
    maior_l = largura2;
    maior_a = altura2;
    menor_x = x1;
    menor_y = y1;
    menor_l = largura1;
    menor_a = altura1;
  }
  else{
    maior_x = x1;
    maior_y = y1;
    maior_l = largura1;
    maior_a = altura1;
    menor_x = x2;
    menor_y = y2;
    menor_l = largura2;
    menor_a = altura2;
  }

  // começando pelo mais "fácil", caso eles não se toquem
  if (maior_y + maior_a < menor_y || menor_y + menor_a < maior_y || menor_x + menor_l < maior_x){
    printf("MISS\n");
    return 0;
  }
    // caso se toquem
  else{
    // pegando a largura da intersecção
    // coloquei fora os ifs pq ele fica o msm, assim como o x final
    x_final = maior_x;
    if (maior_l < menor_l - (maior_x - menor_x)){
      l_final = maior_l;
    }
    else {
      l_final = menor_l - (maior_x - menor_x);
    }

    if (menor_y < maior_y){
      y_final = maior_y;
      // repetindo o processo pra altura
      if (maior_a < menor_a - (maior_y - menor_y)){
      a_final = maior_a;
    }
    else{
      a_final = menor_a - (maior_y - menor_y);
    }
    }

    else{
      y_final = menor_y;
      // repetindo o processo pra altura
      if (menor_a < maior_a - (menor_y - maior_y)){
      a_final = menor_a;
    }
    else{
      a_final = maior_a - (menor_y - maior_y);
    }
    }
  }

  printf("HIT: %lld %lld %lld %lld\n", x_final, y_final, l_final, a_final);
return 0;
}