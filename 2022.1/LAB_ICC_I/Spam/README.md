# Detecção de Spam
A Corporação Guarda-chuva possui muitos funcionários que precisam trocar muitos emails diariamente. Entretanto, recentemente houve uma chuva de emails spam 
vindos de lojas persistentes e recentemente de vários lugares do mundo. Esse dilúvio de spam está atrapalhando o funcionamento da empresa e, por conta disso, 
eles resolveram implementar a seguinte estratégia:

Eles vão por uma semana coletar as palavras mais frequentes desses emails de spam e, a partir disso, criar uma lista de "palavras proibidas", se um email possui 
duas ou mais dessas palavras, ele é automaticamente descartado como spam. Caso contrário, ele será enviado para a inbox de um dos funcionários da empresa.

Além disso, a outra regra da empresa é que emails com linhas de mais de 76 caracteres não são confortáveis de serem lidos e, por conta disso, também devem ser 
descartados como spam.

Ao final da semana de coletar dados, os analistas chegam nas 12 palavras mais comuns em emails spam: "gratuito", "atencao", "urgente", "imediato", "zoombie", 
"oferta", "dinheiro", "renda", "fundo", "limitado", "ajuda" e "SOS"

Com essa lista de palavras eles contratam a você para desenvolver um programa que leia da entrada padrão um email e imprima "Spam" caso seja classificado como spam,
ou "Inbox" caso contrário.

## Observações
- Seu programa deverá identificar se aquela linha de email que foi lida contém alguma das palavras listadas dentro dela em qualquer posição. 
Ou seja, a linha "dinheiros gratuitos" possui duas das palavras listadas.
- Para os propósitos desse exercícios, considere diferenças em capitalização das palavras como palavras diferentes. Então a linha "Consmeticos 
- Gratuitos" não contém nenhuma palavra da lista.
