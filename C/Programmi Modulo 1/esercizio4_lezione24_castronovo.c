#include <stdio.h>

void main(){
 unsigned int n,k;
 printf("Inserisci il numero intero n (positivo)\n");
 scanf("%d",&n);
 for(k=1;k*k<=n;k++);
 printf("La radice quadrata intera e': %d\n",--k);
}
