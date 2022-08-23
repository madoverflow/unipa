#include <stdio.h>

void main(){
 unsigned int n,i=0;
 printf("Inserisci il numero\n");
 scanf("%d",&n);
 while(i<=n){
  printf(" %d ",i);
  i+=2;
 }
}