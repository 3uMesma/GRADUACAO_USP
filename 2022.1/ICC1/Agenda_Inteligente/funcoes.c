#include "funcoes.h"

//Função que adiciona dinamicamente os usuarios e já adiciona no tamanho dela
aluno *AdicionarAluno(aluno *alunos,int *qalunos){
    (*qalunos)++;
    alunos = (aluno*)realloc(alunos,(*qalunos)*sizeof(aluno));
    if(alunos==NULL){printf("falha em adicionar aluno [%d]",*qalunos);exit(1);}
    return alunos;
}

//Imprime o cadastro no index idx
int printaAluno(aluno *alunos,int idx){
	if(alunos[idx].grupo==-2){return 1;}//Retorna 1 se o aluno nao existir
    printf("\nIDX: %d\n",idx);
    printf("Nome: %s\n",alunos[idx].nome);
    printf("Nascimento: %02d/%02d/%d\n",alunos[idx].nascimento.dia,alunos[idx].nascimento.mes,alunos[idx].nascimento.ano);
    printf("Cidade: %s\n",alunos[idx].cidade);
    printf("UF: %s\n",alunos[idx].UF);
    for(i=0;i<Qpreferencia;i++){
        printf("Gosta %.2f de %s\n",alunos[idx].gostos[i],gostosNomes[i]);
    }
	printf("Pertence ao grupo: ");
	if(alunos[idx].grupo==-1){
		printf("[nenhum]\n");
	}else{
		printf("%d\n",alunos[idx].grupo);
	}
	return 0;
}

//Imprime todos os usuário
void printaAllAlunos(aluno *alunos,int qalunos){
    for(a=0;a<qalunos;a++){
        printaAluno(alunos,a);
    }
}

//Adiciona um cadastro manualmente
aluno *CadastrarManualmente(aluno *alunos,int *qalunos){
    alunos = AdicionarAluno(alunos,qalunos);
    printf("Nome: ");scanf("%100[^\n]%*c",alunos[(*qalunos)-1].nome);
    printf("Nascimento [dia/mes/ano]: ");scanf("%d/%d/%d%*c",&alunos[(*qalunos)-1].nascimento.dia,&alunos[(*qalunos)-1].nascimento.mes,&alunos[(*qalunos)-1].nascimento.ano);
    printf("Cidade: ");scanf("%100[^\n]%*c",alunos[(*qalunos)-1].cidade);
    printf("UF: ");scanf("%3[^\n]%*c",alunos[(*qalunos)-1].UF);
    for(i=0;i<Qpreferencia;i++){
        printf("O quanto gosta de %s: ",gostosNomes[i]);scanf("%f%*c",&alunos[(*qalunos)-1].gostos[i]);
    }
    alunos[(*qalunos)-1].grupo=-1;
    return alunos;
}

// funcao para determinar se o usuario nao digitou um ID inexistente e evitar um segmentation fault
void id_valido(int id, int qalunos){
	if (id >= qalunos || id < 0){
		printf("ID invalido\n");
	}
	else{
		printf("ID escolhido: %d\n", id);
	}
}

//Edita um registro já cadastrado
void editar_registro(aluno *alunos){
	int id;
	printf("Digite o ID que deseja alterar: ");
	scanf("%d%*c", &id);
	if(alunos[id].grupo==-2){printf("Seu burro, digita um ID valido da proxima vez :[ o index que voce digitou foi excluido\n");return 1;}

	printaAluno(alunos, id);

	int opcao_edicao;

	do{
	printf("\tMENU PARA EDICAO\n");
	printf("[1] Nome\n");
	printf("[2] Nascimento\n");
	printf("[3] Cidade\n");
	printf("[4] UF\n");
	printf("[5] Gostos\n");
	printf("[0] Sair\n"); 
	printf("Digite a opcao que deseja alterar: ");
	scanf("%d%*c", &opcao_edicao);

	switch(opcao_edicao){
		case 1:
			printf("Digite o novo nome: ");scanf("%100[^\n]%*c",alunos[id].nome);
			break;
		case 2:
			printf("Digite a nova data de nascimento [dia/mes/ano]: ");scanf("%d/%d/%d%*c",&alunos[id].nascimento.dia,&alunos[id].nascimento.mes,&alunos[id].nascimento.ano);
			break;
		case 3:
		// muda a cidade
			printf("Digite a nova cidade de nascimento: ");
			scanf("%100[^\n]%*c",alunos[id].cidade);
			break;
		case 4:
		// muda a UF
			printf("Digite a nova UF: ");scanf("%3[^\n]%*c",alunos[id].UF);
			break;
		case 5:
		// muda o gosto
			char gosto[10];
			printf("Gostos disponiveis:\n");
			for(i=0;i<Qpreferencia;i++){
				printf("-%s\n",gostosNomes[i]);
			}
			printf("Digite o nome do gosto a ser mudado: ");scanf("%s",gosto);
			int idxmudar=-1;
			for(i=0;i<Qpreferencia;i++){
				if(strcmp(gostosNomes[i],gosto)==0){idxmudar=i;break;}
			}
			if(idxmudar==-1){printf("ID inexistente\n");break;}
			scanf("%f%*c",&alunos[id].gostos[idxmudar]);
		case 0:
			printf("O processo de edicao foi encerrado. Todas as alteracoes foram salvas\n");
			printf("Perfil do(a) %s apos as alteracoes: \n", alunos[id].nome);
			printaAluno(alunos, id);
			return 0;
		default:
			printf("Numero invalido. Digite novamente\n");
	}
	}while(opcao_edicao != 0);

}

//Caso a data1 seja posterior a data2, retorna 1
int compareData(data data1,data data2){
	int dias1 = data1.ano*365 + data1.mes*30 + data1.dia;
	int dias2 = data2.ano*365 + data2.mes*30 + data2.dia;
	if(dias1==dias2){
		return 0;
	}else if(dias1>dias2){
		return 1;
	}else{
		return 0;
	}
}

//Função que ordena um array por bubble sort, podendo variar o tipo de comparação pelo opt
void BubbleSort(aluno *alunos,int qalunos,int opt){
    int ciclo=1;aluno copy;int compare;
	while(ciclo){//ciclo bubblesort
        ciclo=0;
        for(i=0;i<qalunos-1;i++){
			compare=0;
            if(opt==0){//ordena por nome
				compare = !(strcmp(alunos[i].nome,alunos[i+1].nome)<0);
			}else if(opt==1){//ordena por data
				compare = compareData(alunos[i].nascimento,alunos[i+1].nascimento);
			}else if(opt==2){//ordena por grupo
				compare = alunos[i].grupo>alunos[i+1].grupo;
			}
			if(compare){//troca se o primeiro for maior
                copy = alunos[i];
                alunos[i] = alunos[i+1];
                alunos[i+1] = copy;
                ciclo=1;
            }
        }
    }
}



//Função de buscar um usuário
void busca(aluno *alunos, int q_alunos){
	int opcao_busca;
	do{
		printf("\tMENU BUSCA\n");
		printf("[-1] Sair do menu de busca\n");
		printf("[1] Nome ou parte do nome\n");
		printf("[2] Data de nascimento\n");
		printf("[3] Grupo da pessoa\n");
		printf("Digite o numero do tipo de busca que deseja realizar: ");

		scanf("%d%*c", &opcao_busca);

		switch (opcao_busca){
			case 1:
				printf("nome buscado: ");
				char nome_buscado[100];
				scanf("%100[^\n]%*c", nome_buscado);
				for (int i = 0; i < q_alunos; i++){
					if(alunos[i].grupo==-2){continue;}
					char *busca = strstr(alunos[i].nome, nome_buscado);
					if (busca != NULL){
						printaAluno(alunos, i);
						printf("\n");
					}
				}
				break; 
			case 2:
				printf("data buscada: ");
				int dia_busca, mes_busca, ano_busca;
				scanf("%d/%d/%d%*c", &dia_busca, &mes_busca, &ano_busca);
				for (int i = 0; i < q_alunos; i++){
					if(alunos[i].grupo==-2){continue;}
					if (alunos[i].nascimento.dia == dia_busca && alunos[i].nascimento.mes == mes_busca && alunos[i].nascimento.ano == ano_busca){
						printaAluno(alunos, i);
						printf("\n");
					}
				}
				break;
			case 3:
				printf("grupo buscado: ");
				int grupo_busca;
				scanf("%d%*c", &grupo_busca);
				for (int i = 0; i < q_alunos; i++){
					if(alunos[i].grupo==-2){continue;}
					if (grupo_busca == alunos[i].grupo){
						printaAluno(alunos, i);
						printf("\n");
					}
				}
				break;
			case -1:
				printf("Processo de busca encerrado\n");
				return 0;
			default:
				printf("Numero invalido. Tente novamente\n");
		}
	}while(opcao_busca !=-1 );
}

// funcao para excluir alguem, os dados da pessoa nao somem, mas ela nao sera mais impressa nas funcoes
void excluir(aluno *alunos, int qalunos){
	printf("Digite o ID da pessoa que deseja excluir\n");
	int ID;
	scanf("%d%*c", &ID);
	if(alunos[ID].grupo==-2){return 1;}//Se ele já tiver sido excluido, retorna 1

	do{
		id_valido(ID, qalunos);
	}while (ID < 0 || ID >= qalunos);

	alunos[ID].grupo = -2;
}

//Calcula a distancia euclidiana com base nos dois alunos
float EuclideanDistance(aluno Al1, aluno Al2){
	float sum=0;
	for(i=0;i<Qpreferencia;i++){
		sum += pow(Al1.gostos[i]-Al2.gostos[i],2);
	}
	return sum;
}

//Função para mesclar os grupos com base em um limiar
void CriarGrupos(aluno *alunos,int qalunos,float limiar){
	printf("1111\n");
	alunos[0].grupo=0;
	int grupoccontador=0;
	int *idxRep = malloc(1*sizeof(int));int qidxrep=1;
	
	idxRep[0]=0;float distancia;float menordist;
	printf("aaaa\n");
	for(a=1;a<qalunos;a++){
		if(alunos[a].grupo==-2){continue;}
		int idxmenordist = 0;
		menordist = EuclideanDistance(alunos[idxRep[0]],alunos[a]);
		for(r=0;r<qidxrep;r++){
			distancia = EuclideanDistance(alunos[idxRep[r]],alunos[a]);
			printf("   -- distancia entre %s (representante do grupo %d) e %s: %f\n",alunos[idxRep[r]].nome,alunos[idxRep[r]].grupo
																					,alunos[a].nome,distancia);
			if(distancia<menordist){
				idxmenordist = r;
				menordist=distancia;
			}
		}
		printf("    ----:: menor distancia: %f\n",menordist);
		//printf("menor distancia de %s: %f\n\n",alunos[idxRep[idxmenordist]].nome,distancia);
		if(menordist<limiar){
			alunos[a].grupo=alunos[idxRep[idxmenordist]].grupo;
			printf("%s agora faz parte do grupo %d\n",alunos[a].nome,alunos[idxRep[idxmenordist]].grupo);
		}else{
			alunos[a].grupo = ++grupoccontador;
			qidxrep++;idxRep = realloc(idxRep,qidxrep*sizeof(int));if(idxRep==NULL){printf("Erro em realocar indices de grupos");exit(1);}
			idxRep[qidxrep-1]=a;
			printf("%s fundou um novo grupo! (%d)\n",alunos[a].nome,alunos[a].grupo);
		}
		printf("\n");

	}
}
