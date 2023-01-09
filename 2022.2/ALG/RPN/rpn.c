#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "item.h"

float rpn(char *sequencia) {
  // criando uma stack auxiliar:
  PILHA *stack_aux = pilha_criar();
  
  // como n sabemos o tamanho da sequencia, vamos usar um while até a string acabar
  int i = 0;
  // Na tabela ASCII: 47 = 0, 57 = 9, 43 = "+", 45 = "-", 42 = "*" e 47 = "/"
  while (sequencia[i] >= '0' || (sequencia[i] == 43 || sequencia[i] == 45 || sequencia[i] == 42 || sequencia[i] == 47)){
    //printf("Elemento %d da sequencia: %c\n", i, sequencia[i]);
    // se for um numero, adicionar na stack
    if (sequencia[i] >= '0'){
      // usando a funcao atof pra isso virar um float
      float n = sequencia[i] - '0';
      ITEM *elemento = item_criar(n);
      //printf("Numero empilhado: ");
      //item_imprimir(elemento);
      pilha_empilhar(stack_aux, elemento);   
    }
    // se for um simbolo de operacao, realizar a operacao:
    else {
      float operacao;
      ITEM *resultado;
      // pegando os dois ultimos numeros
      ITEM *num1 = pilha_topo(stack_aux);
      ITEM *lixo1 = pilha_desempilhar(stack_aux);
      ITEM *num2 = pilha_topo(stack_aux);
      ITEM *lixo2 = pilha_desempilhar(stack_aux);
      // transformando o item em float
      float numero1 = item_get_chave(num1);
      float numero2 = item_get_chave(num2);

      // SOMA
      if (sequencia[i] == 43){
        operacao = numero1 + numero2;
        resultado = item_criar(operacao);
      }
      // SUBTRACAO
      else if (sequencia[i] == 45){
        operacao = numero2 - numero1;
        resultado = item_criar(operacao);
      }
      // MULTIPLICACAO
      else if (sequencia[i] == 42){
        operacao = numero1 * numero2;
        resultado = item_criar(operacao);
      }
      // DIVISAO
      else{
        operacao = numero2 / numero1;
        resultado = item_criar(operacao);
      }
      // empilahndo o resultado
      pilha_empilhar(stack_aux, resultado);
    }
    i++;
  }
  ITEM *ultimo = pilha_topo(stack_aux);
  float resultado_final = item_get_chave(ultimo);
  return resultado_final;
}