#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char nome_ataque[20];
  int poder;
  float acuracia;
  char classe;
}ataques_t;

typedef struct {
  int HP;
  int ataque;
  int defesa;
  int ataque_especial;
  int defesa_especial;
  int velocidade;
}status;

typedef struct {
  char nome[50];
  char tipo_primario[20];
  char tipo_secundario[20];
  status atributos;
  ataques_t ataques[3];
}pokemons_t;

int main(void) {
  int qtt_pokemons = 1;
  pokemons_t *pokemons = (pokemons_t*) malloc (qtt_pokemons * sizeof(pokemons_t));

  int operacao;
  do{
    scanf("%d%*c", &operacao);
    int indice_pokemon, indice_ataque;
    switch(operacao){
      case 1:
      // ler um pokemon novo
        scanf("%50[^\n]%*c", pokemons[qtt_pokemons - 1].nome);
        scanf("%20[^\n]%*c", pokemons[qtt_pokemons - 1].tipo_primario);  
        scanf("%20[^\n]%*c", pokemons[qtt_pokemons - 1].tipo_secundario);
        scanf("%d%*c", &pokemons[qtt_pokemons - 1].atributos.HP);
        scanf("%d%*c", &pokemons[qtt_pokemons - 1].atributos.ataque);
        scanf("%d%*c", &pokemons[qtt_pokemons - 1].atributos.defesa);
        scanf("%d%*c", &pokemons[qtt_pokemons - 1].atributos.ataque_especial);
        scanf("%d%*c", &pokemons[qtt_pokemons - 1].atributos.defesa_especial);
        scanf("%d%*c", &pokemons[qtt_pokemons - 1].atributos.velocidade);
      
        qtt_pokemons++;
        pokemons = (pokemons_t*) realloc (pokemons, qtt_pokemons * sizeof(pokemons_t));
        break;

        case 2:
          // ler um ataque novo
          scanf("%d%*c", &indice_pokemon);
          scanf("%d%*c", &indice_ataque);
          scanf("%20[^\n]%*c", pokemons[indice_pokemon].ataques[indice_ataque].nome_ataque);
          scanf("%d%*c", &pokemons[indice_pokemon].ataques[indice_ataque].poder);
          scanf("%f%*c", &pokemons[indice_pokemon].ataques[indice_ataque].acuracia);
          scanf("%c%*c", &pokemons[indice_pokemon].ataques[indice_ataque].classe);
          break;

        case 3:
        // imprimir um pokemon
          scanf("%d%*c", &indice_pokemon);
          printf("Nome do Pokemon: %s\n", pokemons[indice_pokemon].nome);
          printf("Tipo primario: %s\n",  pokemons[indice_pokemon].tipo_primario);
          printf("Tipo secundario: %s\n", pokemons[indice_pokemon].tipo_secundario);
          printf("Status:\n");
          printf("\tHP: %d\n", pokemons[indice_pokemon].atributos.HP);
          printf("\tAtaque: %d\n", pokemons[indice_pokemon].atributos.ataque);
          printf("\tDefesa: %d\n", pokemons[indice_pokemon].atributos.defesa);
          printf("\tAtaque Especial: %d\n", pokemons[indice_pokemon].atributos.ataque_especial);
          printf("\tDefesa Especial: %d\n", pokemons[indice_pokemon].atributos.defesa_especial);
          printf("\tVelocidade: %d\n", pokemons[indice_pokemon].atributos.velocidade);
          printf("\n");
          break;

        case 4:
        // imprimir ataque
          scanf("%d%*c", &indice_pokemon);
          scanf("%d%*c", &indice_ataque);
          printf("Nome do Ataque: %s\n", pokemons[indice_pokemon].ataques[indice_ataque].nome_ataque);
          printf("Poder base: %d\n", pokemons[indice_pokemon].ataques[indice_ataque].poder);
          printf("Acuracia: %f\n", pokemons[indice_pokemon].ataques[indice_ataque].acuracia);
          printf("Classe: %c\n\n", pokemons[indice_pokemon].ataques[indice_ataque].classe);
          break;

        case 0:
          // parar o programa
          return 0;
      
  }
  }while(operacao != 0);

      free(pokemons);
  
  return 0;
}
