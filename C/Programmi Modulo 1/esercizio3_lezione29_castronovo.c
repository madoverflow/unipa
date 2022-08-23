#include <stdio.h>
void triangolare (unsigned int n);

void main(){
 unsigned int n;
 printf("Inserisci il numero intero n (positivo)\n");
 scanf("%d",&n);
 printf("\n");
 triangolare(n);
}

void triangolare (unsigned int n){
 unsigned int i,j,k;
 for(i=1,k=i;i<=n;i++){
  for(j=1;j<=i;j++)
   printf("%d,",k++);
  printf("\n");
 }
}