/*Uma loja de automóveis mantém os carros à venda sob a forma de um vetor de structs contendo as seguintes informações, para cada veículo: placa, modelo, marca, cor, quilometragem, ano modelo/fabricação (deve ser um struct), valor e tipo (usado ou 0 km, conforme o valor do campo quilometragem).

Pede-se a declaração de uma variável que represente o estoque de veículos da loja, incluindo todas as declarações de tipos que possam ser necessárias. Além disso, implementar as seguintes funções: 

I. Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2 (inclusive), com valor não superior a x reais;
II. Reajustar os valores de todos os carros 0 km, considerando um aumento de 2.5%;
III. Retirar do estoque um determinado veículo, dada a sua placa.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int anofab, anomod;
}anoVeiculo;

typedef struct{
  char placa[7], modelo[10], marca[10], cor[10];
  float quilometragem, valor;
  anoVeiculo anoV;
  int tipo;
}TVeiculo;

void preencheCarro (TVeiculo estoque[], int qt){
  int i;
  for (i=0; i<qt; i++){
    printf("Digite a placa do carro (até 7 dígitos):\n");
    scanf(" %[^\n]", estoque[i].placa);
    fflush(stdin);
    printf("Digite o modelo da carro:\n");
    scanf(" %[^\n]", estoque[i].modelo);
    printf("Digite a marca do carro:\n");
    scanf(" %[^\n]", estoque[i].marca);
    printf("Digite a cor do carro:\n");
    scanf(" %[^\n]", estoque[i].cor);
    printf("Digite a quilometragem do carro:\n");
    scanf("%f", &estoque[i].quilometragem);
    printf("Digite o ano de fabricação e o ano do modelo no seguinte formato aaaa aaaa:\n");
    scanf("%d %d", &estoque[i].anoV.anofab, &estoque[i].anoV.anomod);
    printf("Digite o valor do carro:\n");
    scanf("%f", &estoque[i].valor);
    printf("\n======================================\n");
    if (estoque[i].quilometragem==0){
      estoque[i].tipo=0; //zero km
    }
    else {
      estoque[i].tipo=1; //usado
    }
  }
  
}

void exibeCarro (TVeiculo estoque[], int qt){
  char m[10];
  int a1, a2, i;
  float x;
  printf("Digite o modelo do carro que deseja exibir:\n");
  scanf(" %[^\n]", m);
  printf("Digite entre quais anos de fabricação deseja exibir no formado aaaa aaaa\n");
  scanf("%d %d", &a1, &a2);
  printf("Digite até quanto deseja pagar:\n");
  scanf("%f", &x);
  for (i=0; i<qt; i++){
    if ( strcmp(estoque[i].modelo,m)==0 && (estoque[i].anoV.anofab>=a1) &&  (estoque[i].anoV.anofab<=a2) && (estoque[i].valor<=x)){
      printf("Os carros disponíveis são: %s\n", estoque[i].placa);
    }
    else{
      printf("Não existem carros com as preferencias desejadas.");
    }
  }
}

void reajustaValor (TVeiculo estoque[], int qt){
  int i;
  for (i=0; i<qt; i++){
    if (estoque[i].tipo==0){
      estoque[i].valor=estoque[i].valor*1.025;
      printf("O novo valor do %s é de R$ %.2f\n", estoque[i].placa, estoque[i].valor);
    }
    else{
      printf("\nNão há carros 0km no estoque para ajustar valores.");
    }
  }
}

void removeCarro (TVeiculo estoque[], int qt){
  char placa[7];
  int i, j;
  printf("Qual a placa do veículo que deseja remover?\n");
  scanf(" %[^\n]", placa);
  for (i=0; i<qt; i++){
    j=i;
    if (strcmp(estoque[i].placa,placa)==0){
      while (j<=(qt-1)){
        estoque[j]=estoque[j+1];
        j++;
      }
    }
    else{
      printf("Não existe veículo da placa referenciada.\n");
    }
  }
}

int main(void) {
  int qt, execute;
  printf("Digite quantos carros deseja cadastrar:");
  scanf("%d", &qt);
  TVeiculo estoque[qt];
  preencheCarro(estoque, qt);
  while (execute!=0){
    printf("Digite o que deseja fazer:\n 1 - Efetuar busca \n 2 - Reajustar valores\n 3 - Exclui veículo\n");
    scanf("%d", &execute);
    if (execute==1){
      exibeCarro(estoque, qt);
    }
    else{
      if (execute==2){
        reajustaValor(estoque, qt);
      }
      else{
        removeCarro (estoque, qt);
      }
    }
    printf("Digite o que deseja fazer:\n 1 - Efetuar busca \n 2 - Reajustar valores\n 3 - Exclui veículo\n");
    scanf("%d", &execute);
  }
  
  return 0;
}