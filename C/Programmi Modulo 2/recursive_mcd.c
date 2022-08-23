//MCD (con sottrazioni) ricorsivo in coda
#include <stdio.h>
void scambio(int* n1,int* n2);
size_t mcd(size_t a, size_t b);
void main(){
 size_t a,b;
 printf("Inserisci due numeri interi positivi \n");
 scanf("%d %d", &a,&b);
 if(b>a)
  scambio(&b,&a);
 printf("Il MCD tra %d e %d e': %d",a,b,mcd(a,b));
}

void scambio(int* n1,int* n2){
 *n1=(*n1)^(*n2);
 *n2=(*n1)^*n2;
 *n1=(*n1)^(*n2);
}

size_t mcd(size_t a, size_t b){
 //casi base
 if((a==b)||(!b))
  return a;
 //chiamata ricorsiva
 if(a>b)
  mcd(a-b,b);
 else
  mcd(a,b-a);
}