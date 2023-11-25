//Rodrigo Mileo Lourenço Gil TIA: 32245920
//Enrico Najjar Galdeano TIA: 32260407

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int calculaTempo(int matriz[][2], int n) {
  bool direcao = matriz[0][1];
  bool fila = false;
  int tempo = matriz[0][0] + 10;

  for(int i = 1; i < n; i++) {
    //a fila vai ficar falsa quando t + 10 (10 de esperar a fila) ser menor que o tempo de chegada. //40 chegada, tempo atual 15 -> 25 // nesse caso a gente sabe que a fila acabou qnd a gente tá vendo essa linha pq 40 é maior que 15 + 10 (25)
    if(matriz[i][0] > tempo) { //chegada maior que tempo atual
      if (fila) { 
        if (tempo + 10 > matriz[i][0])
        {
          direcao = !direcao;
          tempo += 10; //40 chegada, tempo atual 15 -> 25
        }
        else
        {
          fila = false;
          direcao = matriz[i][1];
          tempo = matriz[i][0] + 10;
        }
      }
      else { //nao tem fila
        tempo = matriz[i][0] + 10;
      }
    }
    else { //chegada menor que tempo atual
      if(matriz[i][1] ==  direcao){
        tempo = matriz[i][0] + 10;
      }
      else{ // se for direcao contraria
        fila = true;
      }
    }
      

  }

  if (fila) { tempo += 10; }
  //esvazia fila 
  return tempo;
}



int main(void) {
  int num_pessoas;
  printf("Digite o número de pessoas:\n");
  scanf("%d", &num_pessoas);
  if (num_pessoas < 1 || num_pessoas > 10000) {
    printf("Quantidade de pessoas fora dos parametros (1 <= n <= 10000)");
    return 0;
  }

  printf("Digite o tempo de chegada e a direção:\n");
  int matriz[num_pessoas][2];
  for(int i = 0; i < num_pessoas; i++){
    scanf("%d %d", &matriz[i][0], &matriz[i][1]);
    if (matriz[i][0] < 1 || matriz[i][0] > 100000) {
      printf("Tempo de chegada fora dos parametros (1 <= ti <= 100000)");
      return 0;
    }
    if (matriz[i][1] < 0 || matriz[i][1] > 1) {
      printf("Direção fora dos parametros (0 <= di <= 1)");
      return 0;
    }
  }

  int tempo = calculaTempo(matriz, num_pessoas);
  printf("O momento da última saída foi: %d\n", tempo);

  return 0;
}
