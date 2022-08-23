#include <stdio.h>
unsigned int mcd(int m, int n);
void scambio(int* n1,int* n2);

void main(){
 unsigned int a,b;
 printf("Inserisci i due numeri interi (positivi)\n");
 scanf("%d %d",&a,&b);
 if(b>a)
  scambio(&b,&a);
 printf("%d %d\n",a,b);
 printf("Il MCD tra %d e %d e': %d\n",a,b,mcd(a,b));
}

unsigned int mcd(int m, int n){
 int i;
 for(i=n;(m%i)||(n%i);i--);
 return (i);
}
void scambio(int* n1,int* n2){
 *n1=(*n1)^(*n2);
 *n2=(*n1)^*n2;
 *n1=(*n1)^(*n2);
}