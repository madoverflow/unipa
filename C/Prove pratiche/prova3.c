//16 luglio 2020

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
 float val;
 struct node *nextPtr;
}Nodo;

Nodo *insertList(Nodo *list, float x);
void printList(Nodo *curPtr);
void getMinMax(Nodo *curPtr, float *min, float *max);
Nodo *normList(Nodo *a, float min, float max);
Nodo *memberLR(Nodo *a, Nodo *b, float l, float r);
void scambio(float *n1, float *n2);

void main(){
 Nodo *a=NULL,*b=NULL,*c=NULL,*d=NULL;
 Nodo *comodoPtr;
 float min,max,l,r;
 srand(time(NULL));
 for(int i=0; i<7; i++)
  a=insertList(a,rand()%100);
 for(int i=0; i<7; i++)
  b=insertList(b,rand()%100);
 getMinMax(a,&min,&max);
 c=normList(a,min,max);
 d=memberLR(a,b,l,r);
 printList(a);
 printList(b);
 printList(c);
 printf("Inserisci due valori reali\n");
 scanf("%f %f",&l,&r);
 if(r<l)
  scambio(&r,&l);
 d=memberLR(a,b,l,r);
 printList(d);
}

Nodo *insertList(Nodo *list, float x){
 Nodo *newPtr=malloc(sizeof(Nodo));
 Nodo *precPtr,*curPtr,*nextPtr;
 newPtr->val=x;
 if(list==NULL){
  newPtr->nextPtr=NULL;
  list=newPtr;
 }
 else{
  if(x<list->val){
   newPtr->nextPtr=list;
   list=newPtr;
  }
  else{
   precPtr=list;
   curPtr=list;
   nextPtr=list->nextPtr;
   while((x>curPtr->val)&&(nextPtr!=NULL)){
    precPtr=curPtr;
    curPtr=curPtr->nextPtr;
    nextPtr=nextPtr->nextPtr;
   }
   if(x<curPtr->val){
    precPtr->nextPtr=newPtr;
    newPtr->nextPtr=curPtr;
   }
   else
    if(nextPtr==NULL){
     curPtr->nextPtr=newPtr;
     newPtr->nextPtr=NULL;
    }
  }
 }
 return list;
}

void printList(Nodo *curPtr){
 if(curPtr==NULL)
  printf("La lista e' vuota\n");
 else{
  while(curPtr!=NULL){
   printf("%f -> ",curPtr->val);
   curPtr=curPtr->nextPtr;
  }
  printf("\n");
 }
}

void getMinMax(Nodo *curPtr, float *min, float *max){
 if(curPtr==NULL){
  printf("La lista e' vuota\nMinimo e massimo settati a 0\n");
  *min=0;
  *max=0;
 }
 else{
  *min=curPtr->val;
  while(curPtr->nextPtr!=NULL)
   curPtr=curPtr->nextPtr;
  *max=curPtr->val;
 }
}

Nodo *normList(Nodo *a, float min, float max){
 Nodo *c=NULL;
 float ris,num;
 float div=max-min;
 while(a!=NULL){
  num=(a->val)-min;
  ris=num/div;
  c=insertList(c,ris);
  a=a->nextPtr;
 }
 return c;
}

Nodo *memberLR(Nodo *a, Nodo *b, float l, float r){
 Nodo *d=NULL;
 while(a!=NULL){
  if((a->val>=l)&&(a->val<=r))
   d=insertList(d,a->val);
  a=a->nextPtr;
  }
 while(b!=NULL){
  if((b->val>=l)&&(b->val<=r))
   d=insertList(d,b->val);
  b=b->nextPtr;
  }
 return d;
}

void scambio(float *n1, float *n2){
 float comodo;
 comodo=*n2;
 *n2=*n1;
 *n1=comodo;
}
