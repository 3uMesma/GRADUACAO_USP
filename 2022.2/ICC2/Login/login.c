#include "login.h"

// objetivo: calcular a posição do item no hash map
int hashcode(int chave){
	return chave % TAM_HASH;
}

// objetivo: criar a estrutura do hash map
HASH *criar_hash(){
	// alocando espaço para o hash:
	HASH *hash_map = (HASH*) malloc(TAM_HASH * sizeof(HASH));

	// criando uma lista para cada posição do hash
	for (int i = 0; i < TAM_HASH; i++){
		hash_map[i].data = cria_lista();
	}

	return hash_map;
}

// objetivo: função de cadastrar no hash map
void cadastrar(HASH *hash_map, char *N_USP){
	// criando a struct para o aluno:
	ALUNO *aluno_novo = cadastrar_aluno(N_USP);
	//imprimir_aluno(aluno_novo);
	
	// encontrando a posição do aluno no hash map:
	// para isso vamos ter que transformar o NUSP em int:
	int N_USP_convertido = str_to_int(N_USP);
	int posicao = hashcode(N_USP_convertido);

	// lidando com colisões no hash map:
	if (esta_na_lista_NUSP(hash_map[posicao].data, aluno_novo) == true){
		printf("NUSP ja cadastrado\n");
		free(aluno_novo);
		return;
	}
	else{ // nesse caso o aluno pode ser cadastrado normalmente
		insere(hash_map[posicao].data, aluno_novo);
		printf("Cadastro efetuado com sucesso\n");
	}
}

// objetivo: fazer o login
void login(HASH *hash_map, char *tentativa_NUSP, char *tentativa_senha){
	// criando um aluno auxiliar para chamar as outras funções:
	ALUNO *aluno_aux = cadastrar_parte_aluno(tentativa_NUSP, tentativa_senha);

	// encontrando em que posição do hash map esse NUSP estaria:
	int NUSP_convertido = str_to_int(tentativa_NUSP);
	int posicao = hashcode(NUSP_convertido);

	// fazendo a busa nessa posição:
	// 3 casos, NUSP não existe, senha errada, usuario encontrado
	ALUNO *aluno_encontrado = esta_na_lista_aluno(hash_map[posicao].data, aluno_aux);
	if (aluno_encontrado != NULL){ // caso o NUSP e a senha estejam certos
		printar_notas(aluno_encontrado);
	}
	else if(esta_na_lista_NUSP(hash_map[posicao].data, aluno_aux) == false){ // caso o NUSP não tenha sido cadastrado
		printf("NUSP invalido\n");
	}
	else{ // a senha digitada foi errada:
		printf("Senha incorreta para o NUSP digitado\n");
	}
}

// objetivo: imprimir hash table
void imprimir_hash(HASH *hash_map){
	for (int i = 0; i < 10; i++){
		imprimir(hash_map[i].data);
	}
}