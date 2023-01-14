# Login
## Objetivo
Desenvolva um programa em C capaz de:
- Cadastrar alunos através de seu Número USP (NUSP) e senha
- Tentativas de cadastrar um NUSP mais de uma vez devem
imprimir um erro e serem ignoradas pelo sistema.
- Realizar o login
- Se efetuado com sucesso deve imprimir as notas atuais do aluno
- Se houver erro, imprimir o tipo de erro (NUSP não cadastrado ou
senha incorreta)

## Entrada
Número de alunos a serem cadastrados (int)
- Alunos para o cadastro
  - NUSP (string), senha (string), notas (4 doubles). Uma por linha
- Número de tentativas de login (int)
- Logins
  - NUSP (string) e senha (string). Uma por linha
  
## Saída
Durante o cadastro:
- “Cadastro efetuado com sucesso”
- “NUSP ja cadastrado”
Durante os logins:
- “Notas: P1=%.1lf, P2=%.1lf, T1=%.1lf, T2=%.1lf”
- “NUSP invalido”
- “Senha incorreta para o NUSP digitado”

## Detalhes:
1. Os alunos deverão ser cadastrados numa Hash Table, onde a chave será o NUSP em questão.
a. O tratamento de colisões deverá ser resolvido através do encadeamento utilizando uma Linked List.
b. Outros detalhes da implementação da Hash Table ficam a cargo do aluno.
2. O armazenamento e checagem de senhas deverá ser protegido pelo mesmo algoritmo de hashing.
3. É obrigatória a utilização do seguinte algoritmo de hashing para uma entrada char *S qualquer:
a. Criar dois unsigned ints de 16 bits (high = 0, low = 1)
b. Para cada caracter de S
i. low = (low + S[i]) mod 65521
ii. high = (high + low) mod 65521
c. Retornar um unsigned int de 32 bits, sendo que os 16 bits mais significativos
correspondem a high e os 16 bits menos significativos correspondem a low

## Observações
- Para o trabalho, foi escolhido uma hash table de tamanho 10;
- Escolhi tamanho 10 pois assim o primeiro bit determinaria em que indice do vetor o elemto estaria, faciltando a busca e a inserção;
- Casa índdice do Hash possui uma lista ordenada simplesmente encadeada;
- A ordenação já ocorre no ato da inserção;
