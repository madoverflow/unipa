#include <stdio.h>

void main(){
 unsigned int n,p;
 do{
  printf("Inserisci i numeri interi n e p maggiori di zero\n");
  scanf("%d %d", &n,&p);
 }while(n<=0||p<=0);
 printf("%d",(1<<p)<=n&&n<(1<<p+1));
}