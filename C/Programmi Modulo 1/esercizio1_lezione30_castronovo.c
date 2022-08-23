#include <stdio.h>
void griglia(unsigned int m);

void main(){
 unsigned int n;
 printf("Inserisci il numero intero n (positivo)\n");
 scanf("%d",&n);
 griglia(n);
}

void griglia(unsigned int m){
 unsigned int i;
 for(i=1;i<=m*m;i++){
  i%m ? printf("%d,",i) : printf("%d,\n",i);
 }
}