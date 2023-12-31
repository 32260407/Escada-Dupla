// Rodrigo Mileo Lourenço Gil TIA: 32245920
// Enrico Najjar Galdeano TIA: 32260407

#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculaTempo(int **matriz, int n) {

  bool direcao = matriz[0][1];
  bool fila = false;
  int tempo = matriz[0][0] + 10;
  for (int i = 1; i < n; i++) {//percorre matriz
    if (matriz[i][0] > tempo) 
    {// chegada MAIOR que tempo atual
      if (fila) 
      {//se houver fila
        if (tempo + 10 > matriz[i][0]) 
        {//se tempo de chegada for MENOR que o tempo da fila completar seu trajeto.
          if (direcao != matriz[i][1]) 
          {//se a direcao do passageiro coincidir com a direcao da fila
            tempo = matriz[i][0];
            fila = false;
          }
          direcao = !direcao;
          tempo += 10; // 40 chegada, tempo atual 15 -> 25
        } 
        else
        {//se tempo de chegada for MAIOR que o tempo da fila completar seu trajeto
          fila = false;
          direcao = matriz[i][1];
          tempo = matriz[i][0] + 10;
        }
      }
      else 
      { // nao tem fila
        direcao = matriz[i][1];
        tempo = matriz[i][0] + 10;
      }
    } else 
    {//chegada MENOR que tempo atual
      if (matriz[i][1] == direcao)
      {//se a direcao do passageiro for igual a da escada
        tempo = matriz[i][0] + 10;
      } 
      else 
      { // se for direcao contraria
        fila = true;
      }
    }
  }

  if (fila) 
  {// esvazia fila
    tempo += 10;
  }
  return tempo;
}

int main(void) {
  DIR *diretorio;
  DIR *diretorio2;
  struct dirent *ponteiroDir;
  char *nome;
  off_t tamanho;
  diretorio = opendir("input");
  diretorio2 = opendir("output");
  if (diretorio == NULL) {
    printf("Erro ao abrir o diretorio dos inputs\n");
    return 1;
  }
  if (diretorio2 == NULL) {
    printf("Erro ao abrir o diretorio dos outputs\n");
    return 1;
  }

  int **matriz;
  int num_pessoas;
  char caminho[100];
  while ((ponteiroDir = readdir(diretorio)) != NULL) {
    nome = ponteiroDir->d_name;
    sprintf(caminho, "input/%s", nome);
    FILE *arquivo = fopen(caminho, "r");

    if (arquivo == NULL) {
      continue;
    }
    if (nome[0] == '.') {
      continue;
    }
    printf("Arquivo Atual: %s\n", nome);
    tamanho = ftell(arquivo);

    fscanf(arquivo, "%d", &num_pessoas);

    // Cria matriz para guardar os tempos de chegada e as direcoes.
    matriz = (int **)malloc(num_pessoas * sizeof(int *));
    if (matriz == NULL) {
      printf("Erro na alocação de memória.\n");
      return 1;
    }
    for (int i = 0; i < num_pessoas; i++) {
      matriz[i] = (int *)malloc(2 * sizeof(int));
      if (matriz[i] == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
      }
    }
    // le o arquivo e guarda cada linha na matriz.
    for (int i = 0; i < num_pessoas; i++) {
      fscanf(arquivo, "%d %d", &matriz[i][0], &matriz[i][1]);
    }
    // calcula o tempo total(calculaTempo)
    int tempo = calculaTempo(matriz, num_pessoas);

    // abre o arquivo do mesmo nome na pasta output e guarda seu conteudo na
    // variavel resposta
    sprintf(caminho, "output/%s", nome);
    FILE *resultado = fopen(caminho, "r");
    int resposta;
    fscanf(resultado, "%d", &resposta);
    if (resultado == NULL) {
      printf("Não foi possível abrir o arquivo output/%s\n", nome);
      continue;
    }
    // printa a resposta encontrada pelo programa e a resposta no arquivo
    // output.
    printf("Resposta encontrada: %d\nResposta esperada: %d\n", tempo, resposta);
    if (resposta == tempo) {
      printf("Respostas coincidem.\n");
    } else {
      printf("Erro.\n");
    }
    // libera espaco alocado para a proxima iteracao.
    if (matriz != NULL) {
      for (int i = 0; i < num_pessoas; i++) {
        free(matriz[i]);
      }
      free(matriz);
    }
    printf("\n");
    fclose(arquivo);
  }
  closedir(diretorio);
  closedir(diretorio2);
  return 0;
}
