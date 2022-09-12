/*Faça uma função que, dada uma matriz M8×5 de reais, gere a matriz Mt, sua transposta.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void transposta (int a[8][5] , int at[5][8]){
  int i, j;
  for (i=0; i<8; i++){
    for (j=0; j<5; j++){
      at[j][i] = a[i][j];
    }
  }
}

int main(void) {
  int matriz[8][5], matrizt[5][8];
  int i,j;
  srand(time(NULL));
  for (i=0;i<8;i++){
    for (j=0; j<5; j++){
      matriz[i][j]=rand()%10;
    }
  }
  transposta (matriz, matrizt);
  return 0;
}