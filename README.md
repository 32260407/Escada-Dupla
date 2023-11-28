# Escada-Dupla
## Integrantes
Rodrigo Mileo Lourenço Gil TIA: 32245920

Enrico Najjar Galdeano TIA: 32260407

## Instruções
instalar git e gcc

Clonar o repositório : `https://github.com/32260407/Escada-Dupla.git`

Compilar o arquivo : `gcc main.c -o main`

Executar o arquivo criado : `./main`

## Explicação do codigo


  No código, a função se inicia na main, com a declaração das variáveis para os
diretórios, uma para o nome dos arquivos a serem lidos, um ponteiro para visitar
os arquivos do diretório e uma variável para o tamanho do arquivo que será usada
durante a leitura do mesmo. Os diretórios input e output são abertos com a
função opendir, há uma checkagem para ver se foi possível abrir os diretórios.
Após isso, declara-se um ponteiro duplo para ser a matriz, um inteiro para ser o
numero de pessoas e uma string caminho que será o caminho do diretório.
Percorrem-se os arquivos um por um, com suas primeiras linhas atribuidas a
variável de número de pessoas, e o resto de seu conteúdo é colocado na matriz
criada de acordo com o tamanho da quantidade de pessoas (numero da primeira
linha do arquivo), variáveis que são mandadas como parámetros para a função
calculaTempo, que retorna o tempo, comparado com o resultado do arquivo output
correspondente.

  A função calculaTempo é a parte mais importante do programa, nela, inicia-se
com a declaração de três variáveis importantes, direcao, fila e tempo. Direcao e
fila são usadas como booleanas, pois só podem assumir dois estados. Para a fila,
foi decidido usar uma booleana devido ao fato de que: sempre que existe uma
fila, ela só será esvaziada quando o último passageiro da direção atual sair da
escada rolante, e, dado que todos os passageiros podem entrar ao mesmo tempo, o
tempo em que os passageiros que estavam na fila sairão depende somente do tempo
de saída do último passageiro, como será mostrado a seguir. Além disso, não é
necessário guardar nenhuma informação ou quantidade de passageiros na fila,
visto que eles sempre almeijam ir para o destino oposto e o seu tempo de chegada
não importa.


  Para encontrar os resultados corretos em todos os casos, categorizamos padrões
do funcionamento do sistema e, a partir deles, criamos as condições usadas no
laço que le cada linha do conteúdo do arquivo. Para valores de chegada MAIORES
que o tempo atual, ou seja, para passageiros que chegam após o tempo em que o
último passageiro saiu, existem alguns casos:

  Caso não exista uma fila, a direção da escada rolante é a direcao do passageiro e o tempo será o tempo de chegada do passageiro atual +10, sendo que não há mais pessoas na escada rolante nesse momento; 
  
  Caso haja fila e o tempo de chegada do passageiro atual seja MENOR que o tempo que os passageiros da fila levam para completar seu trajeto (tempo atual somado a 10), verificamos se a direção do passageiro coincide com a direcao da fila:
  
        - Se coincidir , a direção troca(pois agora a fila irá utilizar a escada), esvaziamos a fila, e o tempo é o tempo de chegada do passageiro atual + 10(o passageiro atual é o ultimo a entrar e irá na mesma direcao que a fila)
        
        - Se não coincidir, a direção troca, o tempo é somado a 10(pois os passageiros na fila agora irão para a escada) e o passageiro atual é adicionado na fila.
        
  Caso haja fila e o tempo de chegada do passageiro atual seja MAIOR que o tempo que os passageiros da fila levam para completar seu trajeto (tempo atual somado a 10), significa já houve tempo para a fila atravessar (esvaziou), o destino é o do passageiro atual e o tempo agora é o tempo de chegada do passageiro atual + 10;


TEMPO DE CHEGADA MENOR QUE O TEMPO ATUAL

  Caso o tempo de chegada seja MENOR que o tempo e a direcao do passageiro atual ser a mesma da escada, o tempo se torna o tempo de chegada do passageiro + 10
  
  Caso o tempo de chegada seja MENOR que o tempo  e a direcao do passageiro atual ser diferente da escada, o passageiro entra na fila;



## Prints
![image](https://github.com/32260407/Escada-Dupla/assets/142501084/a74582e6-4cd1-4551-82c1-b82da4d5024b)

![image](https://github.com/32260407/Escada-Dupla/assets/142501084/dcb24ae2-d278-4541-80b6-9e1cfcfd65bb)

![image](https://github.com/32260407/Escada-Dupla/assets/142501084/4b267f34-623d-4b96-a8bd-419b73b21a06)

![image](https://github.com/32260407/Escada-Dupla/assets/142501084/8bc7a0f3-147e-4167-a637-5174dc669b40)

![image](https://github.com/32260407/Escada-Dupla/assets/142501084/8635f21f-c03f-4b71-8acf-2c05d3c833cf)

![image](https://github.com/32260407/Escada-Dupla/assets/142501084/2824945c-cf34-4b5c-a0c8-50166ab08a51)






