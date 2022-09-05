/*Implementar uma função que, dado um vetor de reais, troque o 1º e o 2º elementos, em seguida o 3º e o 4º elementos e assim sucessivamente, até se chegar ao final do vetor.*/
#include <stdio.h>
#define TAM 6 

int trocaelementos (int v[]){
  int i;
  int vc[TAM];
  for (i=0; i<TAM/2; i++){ //Como os valores de i estão sendo multiplicados dentro do for por 2, para que i não ultrapasse o tamanho do vetor, TAM precisa ser apenas metade.
    vc[i*2]=v[i*2+1]; //Aqui com i valendo 0, o vetor vc na posição 0*2 será igual ao vetor v na posição 0*2+1, e assim por diante;
    vc[i*2+1]=v[i*2];
  }
  return vc[];
}

int main(void) {
  int v[TAM]={2, 1, 4, 3, 6, 5};
  trocaelementos(v);
  return 0;
}