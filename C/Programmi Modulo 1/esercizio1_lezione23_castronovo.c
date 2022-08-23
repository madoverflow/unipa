#include <stdio.h>

void main(){
 unsigned int n,i=0;
 printf("Inserisci il numero\n");
 scanf("%d",&n);
 while(n>=(1<<i))
  i++;
 if(n)
  printf("Il numero di bit necessari e': %d",i);
 else
  printf("Il numero di bit necessari e': 1");
}