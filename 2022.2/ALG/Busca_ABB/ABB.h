#ifndef _ARVORE_BINARIA_DE_BUSCA_H
  #define _ARVORE_BINARIA_DE_BUSCA_H

  #include  "item.h"

  typedef struct abb ABB;
 
  ABB *abb_criar (void); 
  bool abb_inserir (ABB *T, ITEM *item);
  void abb_imprimir (ABB *T);
  void abb_apagar (ABB **T);
  bool abb_remover(ABB *T, int chave);  
  ITEM *abb_busca(ABB *T, int chave);
  bool abb_vazia(ABB *T);
  
#endif