#include <stdio.h>
#include <math.h>

void main(){
 unsigned int n,a,b,c,k;
 
 printf("Inserisci numero intero positivo\n");
 scanf("%d",&n);
 for(a=1;a<=n;a++)
  for(b=1;b<=a;b++){
   k=(a*a)+(b*b);
   c=sqrt(k);
   if((c*c==k)&&(c<=n))
    printf("Terna trovata: %d,%d,%d\n",a,b,c);
  }
}
