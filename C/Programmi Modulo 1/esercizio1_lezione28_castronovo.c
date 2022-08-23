#include <stdio.h>
void scambio(int* n1,int* n2);

void main(){
 int a,b;
 printf("Inserisci due numeri interi\n");
 scanf("%d %d",&a,&b);
 scambio(&a,&b);
 printf("Variabili scambiate: %d %d",a,b);
}

void scambio(int* n1,int* n2){
 *n1=(*n1)^(*n2);
 *n2=(*n1)^*n2;
 *n1=(*n1)^(*n2);
}