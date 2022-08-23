#include <stdio.h>

void main(){
 unsigned int n,p=1;
 printf("Inserisci il numero intero n (positivo)\n");
 scanf("%d",&n);
 for(;n>=1;p*=n,n--);
 printf("Il fattoriale vale: %d\n",p);
}
