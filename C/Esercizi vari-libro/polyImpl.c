#include <stdio.h>
#include <stdlib.h>
#include "interfacePoly.h"

struct poly{
 size_t maxgrad;
 int *v;
};

typedef struct poly P;

Poly polyInit(size_t maxgrad, int coeff){
 Poly newP=malloc(sizeof(P));
 newP->v=calloc(maxgrad+1,sizeof(int));
 (newP->v)[maxgrad]=coeff;
 newP->maxgrad=maxgrad;
 return newP;
}

Poly sum(Poly p1, Poly p2){
 Poly newP=malloc(sizeof(P));
 size_t max1=p1->maxgrad,max2=p2->maxgrad;
 if(max1>max2){
  newP->v=calloc(max1+1,sizeof(int));
  newP->maxgrad=max1;
  for(size_t i=0; i<=max2; i++)
   (newP->v)[i]=(p1->v)[i]+(p2->v)[i];
  for(size_t i=max2+1; i<=max1; i++)
   (newP->v)[i]=(p1->v)[i];
 }
 else{
  newP->v=calloc(max2+1,sizeof(int));
  newP->maxgrad=max2;
  for(size_t i=0; i<=max1; i++)
   (newP->v)[i]=(p1->v)[i]+(p2->v)[i];
  for(size_t i=max1+1; i<=max2; i++)
   (newP->v)[i]=(p2->v)[i];
 }
 return newP;
}

Poly mul(Poly p1, Poly p2){
 size_t max1=p1->maxgrad,max2=p2->maxgrad;
 Poly newP=malloc(sizeof(P));
 newP->v=calloc(max1+max2+1,sizeof(int));
 newP->maxgrad=max1+max2;
 for(size_t i=0; i<=max1; i++)
  for(size_t j=0; j<=max2; j++)
   (newP->v)[i+j]+=(p1->v)[i]*(p2->v)[j];
 return newP;
}

void printPoly(Poly p){
 for(size_t i=p->maxgrad; i>0; i--)
  printf("%dx^%ld + ",(p->v)[i],i);
 printf("%dx^%d\n",(p->v)[0],0);
}

void horner(Poly p, int x){
 int t=0;
 for(int i=p->maxgrad; i>=0; i--)
  t=(t*x)+(p->v)[i];
 printf("Valutazione del polinomio nel punto %d con il metodo di Horner %d\n",x,t);
}
