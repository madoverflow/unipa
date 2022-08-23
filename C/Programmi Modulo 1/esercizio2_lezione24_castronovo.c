#include <stdio.h>

void main(){
 unsigned int n,a=2;
 printf("Inserisci numero n (positivo)\n");
 scanf("%d",&n);
 while(a<=n/a){
  if(!(n%a))
   printf("(%d,%d)\n",a,n/a);
  a++;
 }
}
