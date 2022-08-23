#include <stdio.h>

void main(){
 unsigned int n, a=1;
 printf("Inserisci il numero n (positivo)\n");
 scanf("%d",&n);
 while (a<=(n>>1)){
  printf("(%d,%d)\n",a,n-a);
  a++;
 }
}
