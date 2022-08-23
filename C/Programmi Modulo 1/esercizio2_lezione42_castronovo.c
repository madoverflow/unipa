#include <stdio.h>
#include <stdlib.h>
#include "mysortinglibrary.h"
char compareint(int *a, int *b);
char (*compare) ();

void main(){
 compare=&compareint;
 unsigned int A[3],i=3,a,b,c;
 void **V=(void **)malloc(3*sizeof(int *));
 for(i=0;i<3;i++){
  printf("Inserisci un intero\n");
  scanf("%d",A+i);
  *(V+i)=A+i;
 }
 sorting_ingenuo(V,3);
 a=*((int *)*(V));
 b=*((int *)*(V+1));
 c=*((int *)*(V+2));
 free(V);
 if(c*c==(a*a)+(b*b))
  printf("I numeri interi inseriti formano un triangolo rettangolo.\n");
 else
  if((a==b)&&(b==c))
   printf("I numeri inseriti formano un triangolo equilatero.\n");
  else
  if((a==b)||(b==c)||(a==c))
   printf("I numeri inseriti formano un triangolo isoscele.\n");
  else
   printf("I numeri inseriti non formano un triangolo.\n");
}
char compareint(int *a, int *b)
{	
 return(((*a-*b)>0)-((*a-*b)<0));
}