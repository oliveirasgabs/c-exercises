/*Considere a existência de um vetor no qual cada posição pode armazenar o nome do aluno, as notas de AV1 e AV2, sua média e a situação (aprovado, reprovado ou em AVF). Pede-se:

-A declaração do vetor, assim como de todos os tipos de dados necessários, caso existam;

-Uma função que leia os dados de todos os alunos da turma;

-Uma função que calcule a média de cada aluno (e a armazene no vetor), assim como a sua situação;

-Uma função que, dado um número inteiro (1-aprovado;2-reprovado;3-em AVF), exiba todos os alunos que estão nesta situação.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 2

typedef struct{
  char nome[30];
  float av1, av2, media;
  int situacao;
}TAluno; //Aqui criamos um tipo de estrutura que guarda todos os dados acima.

void preencheAlunos (TAluno aluno[]){
  int i;
  for (i=0; i<TAM; i++){
    printf("Digite o nome do aluno:\n");
    scanf(" %[^\n]", aluno[i].nome);
    printf("Digite a nota da AV1:\n");
    scanf("%f", &aluno[i].av1);
    printf("Digite a nota da AV2:\n");
    scanf("%f", &aluno[i].av2);
  }
}

void calculaMedia (TAluno aluno[]){
  int i;
  for (i=0;i<TAM;i++){
    aluno[i].media = ((aluno[i].av1)+(aluno[i].av2))/2;
    if (aluno[i].media>=6){
      aluno[i].situacao=1;
    }
    else {
      if (aluno[i].media>=4){
        aluno[i].situacao=3;
      }
      else {
        aluno[i].situacao=2;
      }
    }
  }
}


void verificaSituacao (TAluno aluno[], int situacao){
  int i;
  for (i=0;i<TAM;i++){
    if (aluno[i].situacao==situacao){
      printf("\nNome: %s", aluno[i].nome);
    }
  }
}


int main(void) {
  TAluno aluno[TAM];
  int situacao;
  preencheAlunos (aluno);
  calculaMedia (aluno);
  printf("Digite a situação que deseja exibir: 1-Aprovado, 2-Reprovado, 3-AVF\n");
  scanf("%d", &situacao);
  verificaSituacao (aluno, situacao);
  return 0;
}