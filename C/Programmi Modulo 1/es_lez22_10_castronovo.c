#include <stdio.h>

void main(){
 unsigned int n,M,C,D,U;
 do{
  printf("Inserisci un numero a 4 cifre maggiore di 0\n");
  scanf("%d",&n);
 }while(n/10000);
 M=n/1000;
 C=(n-M*1000)/100;
 D=((n-M*1000)-(C*100))/10;
 U=(n-M*1000)-(C*100)-(D*10);
 printf("%dM, %dC %dD %dU",M,C,D,U);
 
}