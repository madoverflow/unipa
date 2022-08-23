#include <stdio.h>

void main(){
 unsigned int n,i,count;
 printf("Inserisci numero intero (positivo)\n");
 scanf("%d",&n);
 for(count=1;n>>count;count++);
 for(i=count-1;i;i--){
  printf("%d",(n&1<<i)>>i);
 }
 printf("%d",n&1<<i);
 //for(i=0;
}
