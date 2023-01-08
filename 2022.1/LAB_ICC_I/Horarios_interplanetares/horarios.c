#include <stdio.h>
#include <string.h>

int main(void) {
  char planeta[8];
  long long unsigned int segundos;
  long long unsigned int dias, horas, minutos, parametro;

  scanf("%llu %s", &segundos, planeta);

  // caso seja a terra
  if (planeta[0] == 'T'){
    parametro = 86400;
  }
  
  // caso seja venus
  if (planeta[0] == 'V'){
    parametro = 20995200;
  }

  // caso seja mercurio
  if (planeta[0] == 'M'){
    parametro = 5068800;
  }

  // caso seja jupiter
  if (planeta[0] == 'J'){
    parametro = 35760;
  }

  printf("%llu segundos no planeta %s equivalem a:\n", segundos, planeta);
  dias = segundos/parametro;
  horas = (segundos - (dias * parametro))/3600;
  minutos = (segundos - dias * parametro - horas * 3600)/60;
  segundos = segundos - dias * parametro - horas * 3600 - minutos * 60;
  printf("%llu dias, %llu horas, %llu minutos e %llu segundos\n", dias, horas, minutos, segundos);
  return 0;
}
