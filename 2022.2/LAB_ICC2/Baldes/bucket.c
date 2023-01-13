#include <iomanip> // pra q serve isso?
#include <iostream>
using namespace std;

typedef struct no NO;
struct no {
  double info;
  NO *proximo;
};

// objetivo: encontrar a posição de um elemento no balde
int pos_balde(int valor, int max_elementos) {
  return valor / max_elementos;
}

// objetivo: ordenar cada balde
NO *InsertionSort(NO *lista) {
  NO *k, *no_lista;
  if (lista == 0 || lista->proximo == 0) {
    return lista;
  }

  no_lista = lista;
  k = lista->proximo;
  no_lista->proximo = 0;
  while (k != 0) {
    NO *p;
    if (no_lista->info > k->info) {
      NO *aux;
      aux = k;
      k = k->proximo;
      aux->proximo = no_lista;
      no_lista = aux;
      continue;
    }

    for (p = no_lista; p->proximo != 0; p = p->proximo) {
      if (p->proximo->info > k->info)
        break;
    }

    if (p->proximo != 0) {
      NO *aux;
      aux = k;
      k = k->proximo;
      aux->proximo = p->proximo;
      p->proximo = aux;
      continue;
    } else {
      p->proximo = k;
      k = k->proximo;
      p->proximo->proximo = 0;
      continue;
    }
  }
  return no_lista;
}

// objetivo: realizar a ordenação
void BucketSort(double *vetor, int n_baldes, int n_vetor, int max_elementos) {
  int i, j;
  NO **baldes;

  // Criando os baldes:
  baldes = (NO **)malloc(sizeof(NO *) * n_baldes);

  // Inicializando cada balde como vazio
  for (i = 0; i < n_baldes; i++) {
    baldes[i] = NULL;
  }

  // Enchendo os baldes
  for (i = 0; i < n_vetor; i++) {
    NO *atual;
    int pos = pos_balde(vetor[i], max_elementos);
    atual = (NO *)malloc(sizeof(NO));
    atual->info = vetor[i];
    atual->proximo = baldes[pos];
    baldes[pos] = atual;
  }

  // Ordenando cada balde
  for (i = 0; i < n_baldes; i++) {
    baldes[i] = InsertionSort(baldes[i]);
  }

  // Colocar os emenetos ordenados em um único vetor
  for (j = 0, i = 0; i < n_baldes; ++i) {
    NO *no;
    no = baldes[i];
    while (no) {
      vetor[j++] = no->info;
      no = no->proximo;
    }
  }

  // LIberando os ponteiros
  for (i = 0; i < n_baldes; i++) {
    NO *no;
    no = baldes[i];
    while (no) {
      NO *aux;
      aux = no;
      no = no->proximo;
      free(aux);
    }
  }
  free(baldes);
  return;
}

// objetivo: imprimir tudo
void print(double *vetor, int n_elements) {
  int i;
  for (i = 0; i < n_elements; i++) {
    printf("%.2lf ", vetor[i]);
  }
  cout << endl;
}

// FUNÇÃO PRINCIPAL
int main(void) {
  // lendo a inicializando as informações iniciais
  int n_elementos, n_baldes, max_elementos;
  double *vetor;
  cin  >> n_elementos;
  cin  >> n_baldes;
  cin  >> max_elementos;
  vetor = (double*) malloc(n_elementos * sizeof(double));

  // adicionando cada elemento ao vetor
  for (int i = 0; i < n_elementos; i++){
    cin >> vetor[i];
  }

  // fazendo a ordenação e imprimindo
  BucketSort(vetor, n_baldes, n_elementos, max_elementos);
  print(vetor, n_elementos);
}
