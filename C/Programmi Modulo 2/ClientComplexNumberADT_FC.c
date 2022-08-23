#include <stdio.h>
#include "interfaceComplexNumberADT_FC.h"

void main(){
 ComplexPtr a=NULL,b=NULL,c=NULL;
 size_t N;
 a=init(2,3);
 b=init(4,5);
 printf("Somma:\n");
 c=add(a,b);
 display(c);
 c=sub(a,b);
 printf("Sottrazione:\n");
 display(c);
 c=cdiv(a,b);
 printf("Divisione:\n");
 display(c);
 c=prod(a,b);
 printf("Prodotto:\n");
 display(c);
 printf("Inserisci il numero di radici dell'unità\n");
 scanf("\n%ld",&N);
 nrad(N);
}