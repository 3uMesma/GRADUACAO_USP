#include "cadastro.h"

// objetivo: transformar uma string em unsigned int
unsigned int criptografar(char *senha, int tam_senha){
	unsigned int high = 1;
	unsigned int low = 0;

	// para cada caractere da senha:
	for (int i = 0; i < tam_senha; i++){
		low = (low + senha[i]) % 65521;
		high = (high + low) % 65521;
	}

	// para concatenar dois unisgned ints:
	unsigned int resultado = high * pow(2, 16);
	resultado += high;

	return resultado;
}

// objetivo: adicionar a string na struct
void string_struct(char *N_USP, ALUNO *aluno){
	for (int i = 0; i < TAM_NUSP; i++){
		aluno -> NUSP[i] = N_USP[i];
	}
}

// objetivo: cadastrar cada aluno:
ALUNO *cadastrar_aluno(char *N_USP){
	ALUNO *novo_aluno = (ALUNO*) malloc(sizeof(ALUNO));
	char senha[40];
	novo_aluno -> NUSP = (char *) malloc(TAM_NUSP * sizeof(char));
	string_struct(N_USP, novo_aluno);
	scanf(" %s", senha);
	int tam_senha = strlen(senha);
	unsigned int senha_crip = criptografar(senha, tam_senha);
	novo_aluno -> senha = senha_crip;
	for (int i = 0; i < TAM_NOTAS; i++){
		scanf(" %lf", &novo_aluno -> notas[i]);
	}
	novo_aluno -> proximo = NULL;
	return novo_aluno;
}

// objetivo: cadastar parte do aluno
ALUNO *cadastrar_parte_aluno(char *N_USP, char *senha){
	ALUNO *novo_aluno = (ALUNO*) malloc(sizeof(ALUNO));
	novo_aluno -> NUSP = (char *) malloc(TAM_NUSP * sizeof(char));
	string_struct(N_USP, novo_aluno);
	int tam_senha = strlen(senha);
	unsigned int senha_crip = criptografar(senha, tam_senha);
	novo_aluno -> senha = senha_crip;
	novo_aluno -> proximo = NULL;
	return novo_aluno;
}

// objetivo: converter uma string para int
int str_to_int(char *NUSP){
	int numero = 0;
	for (int i = 0; i < TAM_NUSP; i++){
		int digito = NUSP[i] - '0';
		numero += digito * pow(10, TAM_NUSP - i - 1);
	}

	return numero;
}

// objetivo: imprimir a struct direitinho
void imprimir_aluno(ALUNO *aluno){
	printf("NUSP: %s\n", aluno -> NUSP);
	printf("Senha encriptografada: %u\n", aluno -> senha);
	printf("Notas: ");
	for (int i = 0; i < TAM_NOTAS; i++){
		printf("%.1lf ", aluno -> notas[i]);
	}
	printf("\n");
}

// objetivo: comparar structs
bool comparar_alunos(ALUNO *aluno1, ALUNO *aluno2){
	// comparando o NUSP:
	int NUSP_igual = 0;
	if (strcmp(aluno1 -> NUSP, aluno2 -> NUSP) == 0)NUSP_igual = 1;

	// comparando a senha:
	int senha_igual = 0;
	if (aluno1 -> senha == aluno2 -> senha)senha_igual = 1;

	// não precisa comparar as notas, pois o problemático é o NUSP e a senha

	if (NUSP_igual == 1 && senha_igual == 1){
		return true;
	} else{
		return false;
	}
}

// objetivo: printar as notas
void printar_notas(ALUNO *aluno){
	printf("Notas: ");
	for (int i = 0; i < 2; i++){
		printf("P%d=%.1lf, ", i + 1, aluno -> notas[i]);
	}
	printf("T1=%.1lf, ", aluno -> notas[2]);
	printf("T2=%.1lf ", aluno -> notas[3]);
	printf("\n");
}