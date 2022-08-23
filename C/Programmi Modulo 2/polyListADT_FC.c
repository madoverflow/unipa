#include <stdio.h>
#include <stdlib.h>
#include "interfacePolyADT_FC.h"

typedef struct node{
 size_t expo;
 int coef;
 struct node *nextPtr;
}Monomio;

struct poly{
 size_t maxGrad;
 Monomio *topPtr;
};
typedef struct poly Polinomio;

void static copyList(Monomio **topPtr, Monomio *rootPtr);

Poly term(int coef, size_t expo){
 Poly comodoPtr=malloc(sizeof(Polinomio));
 Monomio *monPtr;
 if(comodoPtr==NULL)
  printf("Spazio nell'heap insufficiente. Polinomio non inizializzato.\n");
 else{
  monPtr=malloc(sizeof(Monomio));
  if(monPtr==NULL){
   printf("Spazio nell'heap insufficiente. Polinomio non inizializzato.\n");
   free(comodoPtr);
   comodoPtr=NULL;
  }
  else{
   monPtr->expo=expo;
   monPtr->coef=coef;
   monPtr->nextPtr=NULL;
   comodoPtr->topPtr=monPtr;
   comodoPtr->maxGrad=expo;
  }
 }
 return comodoPtr;
}

Poly add(Poly p1, Poly p2){
 Poly pSum=malloc(sizeof(Polinomio));
 if(pSum==NULL)
  printf("Spazio nell'heap insufficiente. Operazione di somma fallita.\n");
 else{
  if((p1==NULL)||(p1->topPtr==NULL))
   return p2;
  if((p2==NULL)||(p2->topPtr==NULL))
   return p1;
  if(p1->maxGrad>p2->maxGrad){
   copyList(&(pSum->topPtr),p1->topPtr);
   pSum->maxGrad=(pSum->topPtr)->expo;
   show(pSum);
  }
 }
}

void show(Poly p){
 Monomio *comodoPtr;
 if((p==NULL)||(p->topPtr==NULL))
  printf("Polinomio non inizializzato.\n");
 else{
  comodoPtr=p->topPtr;
  printf("Polinomio -> ");
  while(comodoPtr!=NULL){
   printf("%dx^%ld ",comodoPtr->coef,comodoPtr->expo);
   comodoPtr=comodoPtr->nextPtr;
  }
  printf("\n");
 }
}

void static copyList(Monomio **topPtr, Monomio *rootPtr){
 *topPtr=malloc(sizeof(Monomio));
 Monomio *comodoPtr=*topPtr;
 Monomio *newPtr;
 (*topPtr)->expo=rootPtr->expo;
 (*topPtr)->coef=rootPtr->coef;
 (*topPtr)->nextPtr=NULL;
 rootPtr=rootPtr->nextPtr;
 while(rootPtr!=NULL){
  newPtr=malloc(sizeof(Monomio));
  newPtr->expo=rootPtr->expo;
  newPtr->coef=rootPtr->coef;
  newPtr->nextPtr=NULL;
  comodoPtr->nextPtr=newPtr;
  comodoPtr=newPtr;
 }
}