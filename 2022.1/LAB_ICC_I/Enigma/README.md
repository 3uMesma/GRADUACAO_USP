# O Enigma
Dr. Henry Walton é um grande pesquisador e arqueólogo. Sabendo de um naufrágio perdido que ocorreu durante a Segunda Guerra Mundial, ele se interessa muito e 
vai pessoalmente até o local onde os rumores indicavam. Chegando lá, Henry se encontra com uma caverna cheia d'água e, dentro dela um submarino que carregava 
as antigas cores alemãs.

O dr. consegue entrar dentro do submarino através de um rombo no casco e lá ele encontra, cheia de água, uma máquina enigma utilizada para criptografar e 
descriptografar mensagens durante a Segunda Guerra. Ao lado da máquina, inúmeros papeis contendo sequências de letras sem sentido algum.

Henry consegue voltar a superfície com a máquina e os papéis que, ele descobrira. Eles continham mensagens criptografadas. Entretanto, a máquina enigma estava 
severamente avariada e não poderia ser utilizada para decifrar as mensagens escondidas. Além disso, essa máquina parecia mais antiga e funcionava de uma forma 
diferente às outras enigmas encontradas durante a guerra. Apesar disso, a máquina ainda entregava as configurações necessárias para decifrar os códigos.

É então que o dr. pede a você que construa um programa capaz de decifrar as mensagens codificadas e descobrir o segredo a muito esquecido. Afinal, o que fazia 
um submarino perdido dentro daquela caverna, o que eles poderiam ter planejado?

A máquina consiste em três rotores em sequência. Cada rotor é basicamente uma engrenagem e, para cada lado da engrenagem, existem 26 conexões. Toda conexão em 
um lado da engrenagem conecta a uma outra correspondente do outro lado e não há duas conexões que se juntem. Ou seja, ao conectar cada uma das 26 conexões a um 
teclado, as conexões do outro lado do rotor serão alguma versão embaralhada das conexões que o teclado envia.

A forma como a máquina funciona é simples. Suponhamos que haja apenas um rotor. Conectamos um teclado a um dos lados do rotor e lâmpadas no outro. Cada lâmpada 
possui um rótulo que indica uma letra. Quando pressionamos uma letra no teclado, uma conexão se fecha que passa pelo rotor e chega a uma lâmpada correspondente.
Como as conexões do rotor são embaralhadas, a lâmpada que acende não é a mesma tecla pressionada. Na verdade, ela representa a versão codificada da letra que foi 
apertada. Depois de uma tecla pressionada, o rotor gira uma posição e as conexões elétricas com o teclado e lâmpada mudam. Como existem 26 conexões, também existem
26 posições que o rotor pode assumir.

Com 3 rotores a situação é a mesma, mas temos 3 rotores conectados em série. Assim, o sinal que sai do teclado vai para o rotor 1, que vai para o 2 e por fim para o 
3, embaralhando cada vez mais a letra. Entretanto, há uma diferença: o segundo rotor só gira uma posição quando o primeiro deu uma volta completa (andou 26 posições), 
e o terceiro só gira quando o segundo deu uma volta completa. Como se fossem os ponteiros de um relógio.

Por sorte, não é necessário construir fisicamente essa máquina, já que seria lento e custoso. Podemos, ao invés disso, simular ela!

Cada rotor pode ser representado por um vetor, onde o índice é a conexão no lado do teclado e o valor naquele índice representa aconexão com a lâmpada. Imagine o 
seguinte vetor:
