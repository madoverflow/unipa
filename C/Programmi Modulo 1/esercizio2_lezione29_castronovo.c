#include <stdio.h>
unsigned int mcm(unsigned int m, unsigned int n);
void scambio(int* n1,int* n2);

void main(){
 unsigned int a,b;
 printf("Inserisci i due numeri interi (positivi)\n",a,b);
 scanf("%d %d",&a,&b);
 if(b>a)
  scambio(&b,&a);
 printf("Il mcm tra %d e %d vale: %d\n",a,b,mcm(a,b));
}

unsigned int mcm(unsigned int m, unsigned int n){
 unsigned int i;
 for(i=m;(i%m)||(i%n);i++);
 return (i);
}
void scambio(int* n1,int* n2){
 *n1=(*n1)^(*n2);
 *n2=(*n1)^*n2;
 *n1=(*n1)^(*n2);
}