#include <stdio.h>

void main(){
 unsigned int a,b,M,i,N;
 printf("Inserisci due interi\n");
 scanf("%d %d",&a,&b);
 N=a*b;
 M=N/2;
 for(i=0;i<N*M;i++){
  printf("*");
  if((i%M==M-1))
   printf("\n");
 }
}