#include <stdio.h>
unsigned int mcd(unsigned int m, unsigned int n);
void scambio(int* n1,int* n2);

void main(){
 unsigned int a,b;
 printf("Inserisci i due numeri interi (positivi)\n");
 scanf("%d %d",&a,&b);
 if(b>a)
  scambio(&b,&a);
 printf("Il MCD tra %d e %d e': %d\n",a,b,mcd(a,b));
}

unsigned int mcd(unsigned int m, unsigned int n){
 while((m!=n)&&(n)){
  if(m>n)
   m=m-n;
  else
   n=n-m;
  }
 return (m);
}
void scambio(int* n1,int* n2){
 *n1=(*n1)^(*n2);
 *n2=(*n1)^*n2;
 *n1=(*n1)^(*n2);
}