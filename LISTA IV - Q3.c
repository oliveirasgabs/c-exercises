/*Desenvolver uma função que, dada uma string s, crie uma substring que inicie na posição p de s e contenha n caracteres.
Observações: 
se p e/ou n forem inválidos, a substring será vazia; 
ii) se s não possuir n caracteres além de p, a substring a ser criada começará em p e terminará no final de s.*/

#include <stdio.h>
#include <string.h>

void criaString (char s[], int p , int n){
  int i;
  char sb[n+1];
  if (p < 0 || n < 0 || p > strlen(s)){
    sb[0] = '\0';
  }
  else{
    for(i = 0; i < n && s[p] != '\0' ; i++, p++){
      sb[i]=s[p];
      //printf("%s\n", sb);
    }
    sb[i]= '\0';
  }
  printf("Sua nova string é: %s\n", sb);
}

int main() {
  char s[] = "Faculdade";
  int p = 2;
  int n = 5;


  printf("A sua string é: %s\n", s);
  criaString(s, p, n);

  return 0;
}