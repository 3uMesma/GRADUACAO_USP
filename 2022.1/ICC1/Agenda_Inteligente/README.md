# Agenda Inteligente
**Trabalho feito juntamente com o Miguel Prates(miguel.prates@usp.br)**

A ideia do projeto é desenvolver uma agenda que permite inserir, editar, excluir e buscar os registros cadastrados. Os registros são armazenados 
em memória secundária via arquivos binários. A agenda é inteligente, de forma que consegue agrupar os registros conforme as seguintes características:

- Nome completo
- Data de nascimento
- Cidade
- Estado
- Preferências
- Grupo

## Funcionalidades
- Importar registros de um arquivo
- Cadastrar novo registro
- Editar registro
- Excluir registro
- Buscar registro
  - Pelo nome
  - Pela data de nascimento
  - Pelo grupo
- Ordenar registros
  - Pelo nome
  - Pela data de nascimento
  - Pelo grupo
- Agrupar registros
- Exportar registros de um arquivo

## Processo de agrupamento
O algoritmo usado foi o algoritmo de Leader, seu passo a passo é o seguinte:
1. Escolha um registro para ser o primeiro grupo
2. Selecione o próximo registro P
3. Encontre a menor distância D entre P e os representantes dos grupos existentes
4. Se D for menor do que um limiar T, então P participará do grupo mais próximo. Caso contrário, um novo grupo é criado e P será o representante
5. Volte ao passo 2 e repita até que todos os registros estejam agrupados

## Complexidade das Funções
- Importar registros de um arquivo: O(n)
- Cadastrar novo registro: O(10)
- Editar registro: O(10)
- Excluir registro: (1)
- Buscar registro: O(n)
- Ordenar registros: O(n²)(.)
- Agrupar registros: O(n)
- Exportar registros de um arquivo: O(n)

(.) -> foi usado o método BubbleSort

## Observações
- Escolhemos três tipos de hobbies: jogar RPG, jogar FPS e jogar cartas
- Quando o usuario não existe, atribuimos o grupo dele ao -2
