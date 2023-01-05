#include "funcoes.h"

int main(){
	int opcao;
	int q_alunos = 0;
    aluno *alunos=calloc(q_alunos,sizeof(aluno));
	char nomearquivo[100];
	do {
		printf("\t\tMENU\n");
		printf("[1] Importar registros de um arquivo\n");
		printf("[2] Cadastrar novo registro\n");
		printf("[3] Editar registro\n");
		printf("[4] Excluir registro\n");
		printf("[5] Buscar registro\n");
		printf("[6] Ordenar registros\n");
		printf("[7] Agrupar registros\n");
		printf("[8] Exportar registros\n");
		printf("[9] Printar todos os registros\n");
		//printf("[10] Printar todos para retornar input\n");
		printf("[0] Sair\n");
		printf("Digite o numero da operacao desejada: ");

		scanf("%d%*c", &opcao);
		printf("Opcao escolhida: %d\n", opcao);

		switch (opcao){
			case 1:
				FILE *arq;
				printf("Digite o path do arquivo: ");
				scanf("%100[^\n]%*c",nomearquivo);
				arq = fopen(nomearquivo, "rb");

				if (arq == NULL){
					printf("Erro de leitura do arquivo [%s]\n",nomearquivo);
					exit(1);
				}

				fread(&q_alunos, sizeof(int), 1, arq);
				printf("abrindo o arquivo(%d)\n");
				alunos = (aluno*)calloc(q_alunos,sizeof(aluno));
				if(alunos==NULL){printf("falha em inicializar na importacao\n");break;}
				printf("tudo adicionado :)\n");
				fread(alunos, sizeof(aluno), q_alunos, arq);
				
				printf("Arquivo lido com sucesso (%d)\n",q_alunos);
				//printaAllAlunos(alunos,q_alunos);
				fclose(arq);

				break;
			case 2:
			// cadastrar novo registro
            	alunos = CadastrarManualmente(alunos,&q_alunos);
            	printf("Pessoa cadastrada com sucesso\n");
				break;
			case 3:
			// editar registro
				editar_registro(alunos);
				break;
			case 4:
				excluir(alunos,q_alunos);
			// excluir registro
				break;
			case 5:
				busca(alunos,q_alunos);
			//buscar registro
				busca(alunos,q_alunos);
				break;
			case 6:
			// ordenar registro
				printf("Digite o tipo de ordenacao:\n");
				printf("	[0]- ordenar por nome\n");
				printf("	[1]- ordenar por data\n");
				printf("	[2]- ordenar por grupo\n");
				int opt;scanf("%d",&opt);
				BubbleSort(alunos,q_alunos,opt);
				break;
			case 7:
			// agrupar registros
				printf("Digite o limiar de agrupamento: ");float l;scanf("%f",&l);
				CriarGrupos(alunos,q_alunos,l);
				break;
			case 8:
				FILE *arq_final;
				printf("Digite o path do arquivo: ");
				scanf("%100[^\n]%*c",nomearquivo);
				arq_final = fopen(nomearquivo, "wb");

				if (arq_final == NULL){
					printf("Erro de leitura do arquivo final [%s]\n",nomearquivo);
					exit(1);
				}

				fwrite(&q_alunos, sizeof(int), 1, arq_final);
				fwrite(alunos, sizeof(aluno), q_alunos, arq_final);

				printf("Arquivo salvo com sucesso (%d)\n",q_alunos);

				fclose(arq_final);

				break;
			case 9:
				//printar todos os cadastros
				printaAllAlunos(alunos,q_alunos);
				//printaAluno(alunos,0);
				break;
			case 0:
				printf("Volte sempre!\n");
				free(alunos);
				exit(1);
			default:
				printf("Numero invalido. Tente novamente\n");
				break;
		}
	}while(opcao != 0);
	return 0;
}
