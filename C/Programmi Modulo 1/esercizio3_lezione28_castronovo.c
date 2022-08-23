#include <stdio.h>
unsigned int euclide(unsigned int a,unsigned int b);
void scambio(int* n1,int* n2);

void main(){
 unsigned int a,b;
 printf("Inserisci i due numeri interi (positivi)\n");
 scanf("%d %d",&a,&b);
 if(b>a)
  scambio(&b,&a);
 printf("Il MCD tra %d e %d e': %d\n",a,b,euclide(a,b));
}

unsigned int euclide(unsigned int a,unsigned int b){
 unsigned int r;
 while(b){
  r=a%b;
  a=b;
  b=r;
 }
 return (a);
}
void scambio(int* n1,int* n2){
 *n1=(*n1)^(*n2);
 *n2=(*n1)^*n2;
 *n1=(*n1)^(*n2);
}