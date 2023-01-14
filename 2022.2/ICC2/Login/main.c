// ******* TRABALHO 3 DE ICC2 *********
// NOME: AMANDA KASAT BALTOR
// NUSP: 13727210

#include "login.h"

int main(){
	// PRIMEIRA PARTE: CADASTRO
	int n_alunos;
	scanf(" %d", &n_alunos);

	// criando o hash map:
	HASH *hash_map = criar_hash();

	// cadastrando cada aluno:
	for (int i = 0; i < n_alunos; i++){
		char *NUSP;
		NUSP = (char*) malloc(TAM_NUSP * sizeof(char));
		scanf(" %s", NUSP);
		cadastrar(hash_map, NUSP);
	}

	// SEGUNDA PARTE: LOGIN
	int n_logins;
	scanf("%d", &n_logins);

	// processo de login:

	for (int i = 0; i < n_logins; i++){
		char *NUSP;
		NUSP = (char*) malloc(TAM_NUSP * sizeof(char));
		char *senha;
		senha = (char*) malloc(40 * sizeof(char));
		scanf("%s", NUSP);
		scanf("%s", senha);

		login(hash_map, NUSP, senha);
	}
	return 0;
}