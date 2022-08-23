#include <stdio.h>
#include <stdlib.h>
#include "interfacePolyADT_FC.h"

struct poly{
 size_t maxGrad;
 int *arraycoefficienti;
};

typedef struct poly Polinomio;

Poly term(int coef, size_t expo){
 Poly comodoPtr=malloc(sizeof(Polinomio));
 if(comodoPtr==NULL)
  printf("Spazio nell'heap insufficiente. Polinomio non creato\n");
 else{
  comodoPtr->arraycoefficienti=calloc(expo+1,sizeof(int));
  (comodoPtr->arraycoefficienti)[expo]=coef;
  comodoPtr->maxGrad=expo;
 }
 return comodoPtr;
}

Poly add(Poly p1, Poly p2){
 Poly comodoPtr=malloc(sizeof(Polinomio));
 if(comodoPtr==NULL)
  printf("Spazio nell'heap insufficiente. Operazione di somma fallita.\n");
 else{
  if((p1==NULL)||(p1->arraycoefficienti==NULL))
   return p2;
  if((p2==NULL)||(p2->arraycoefficienti==NULL))
   return p1;
  if(p1->maxGrad>p2->maxGrad){
   comodoPtr->maxGrad=p1->maxGrad;
   comodoPtr->arraycoefficienti=calloc((p1->maxGrad)+1,sizeof(int));
   for(int i=0; i<=p2->maxGrad; i++)
    (comodoPtr->arraycoefficienti)[i]=(p1->arraycoefficienti)[i]+(p2->arraycoefficienti)[i];
   for(int i=p2->maxGrad+1; i<=p1->maxGrad; i++)
    comodoPtr->arraycoefficienti[i]=p1->arraycoefficienti[i];
  }
  else{
   comodoPtr->maxGrad=p2->maxGrad;
   comodoPtr->arraycoefficienti=calloc((p2->maxGrad)+1,sizeof(int));
   for(int i=0; i<=p1->maxGrad; i++)
    (comodoPtr->arraycoefficienti)[i]=(p1->arraycoefficienti)[i]+(p2->arraycoefficienti)[i];
   for(int i=p1->maxGrad+1; i<=p2->maxGrad; i++)
    comodoPtr->arraycoefficienti[i]=p2->arraycoefficienti[i];
  }
 }
 return comodoPtr;
}

Poly mult(Poly p1, Poly p2){
 Poly comodoPtr=NULL;
 if(((p1==NULL)||(p1->arraycoefficienti==NULL))||((p2==NULL)||(p2->arraycoefficienti==NULL)))
  printf("Uno dei due polinomi non e' inizializzato. Il prodotto non puo' essere eseguito\n");
 else{
  comodoPtr=malloc(sizeof(Polinomio));
  if(comodoPtr==NULL)
   printf("Spazio nell'heap insufficiente.\n");
  else{
   comodoPtr->maxGrad=p1->maxGrad+p2->maxGrad;
   comodoPtr->arraycoefficienti=calloc(comodoPtr->maxGrad+1,sizeof(int));
   for(int i=0; i<=p1->maxGrad; i++)
    for(int j=0; j<=p2->maxGrad; j++){
     (comodoPtr->arraycoefficienti)[i+j]+=((p1->arraycoefficienti)[i])*((p2->arraycoefficienti)[j]);
    }
  }
 }
 return comodoPtr;
}

float eval(Poly p, float x){
 float t=0.0;
 if((p==NULL)||(p->arraycoefficienti==NULL))
  printf("Polinomio non inizializzato. Valutazione fallita.\n");
 else
   for(int i=p->maxGrad; i>=0; i--)
    t=(t*x)+(p->arraycoefficienti[i]);
 return t;
}

void show(Poly comodoPtr){
 printf("Polinomio-> ");
 for(int i=comodoPtr->maxGrad; i>=0;i--)
  printf("%dx^%d ",(comodoPtr->arraycoefficienti)[i],i);
 printf("\n");
}