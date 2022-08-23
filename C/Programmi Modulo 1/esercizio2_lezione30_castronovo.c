#include <stdio.h>
void diagonale(unsigned int m);

void main(){
 unsigned int n;
 printf("Inserisci il numero intero n (positivo)\n");
 scanf("%d",&n);
 diagonale(n);
}

void diagonale(unsigned int m){
 unsigned int comodo,i;
 for(i=1;i<=m;i++){
  comodo=i;
  for(i=0;i<comodo-1;i++)
  	printf("-");
  i=comodo;
  printf("%d\n",i);
 }
}