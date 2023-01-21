# include "ab.h"

int main(){
	// leitura de dados
	int qtd_alunos, qtd_notas;
	printf("Digite a quantidade de alunos a serem cadastrados: ");
	scanf("%d", &qtd_alunos);
	printf("Digite a quantidade de provas realizadas: ");
	scanf("%d", &qtd_notas);

	ALUNO *alunos;
	alunos = cadastrar_alunos(qtd_alunos, qtd_notas);
	imprimir_alunos(alunos, qtd_alunos, qtd_notas);

	// realizando a ordenação:
	heapSort(alunos, qtd_alunos, qtd_notas);
	imprimir_alunos(alunos, qtd_alunos, qtd_notas);
}