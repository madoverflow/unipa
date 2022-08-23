#include <stdio.h>
#include <stdlib.h>
#include "interfaceQueueADT_FC.h"

typedef struct node{
 Item val;
 struct node *nextPtr;
}Nodo;

struct Coda{
 Nodo *topPtr;
 Nodo *tailPtr;
};

typedef struct Coda Queue;

queuePtr queueInit(queuePtr Q){
 queuePtr que=malloc(sizeof(Queue));
 if(que==NULL){
  printf("Spazio nell'heap insufficiente. Coda non inizializzata\n");
  return NULL;
 }
 else{
  Q=que;
  Q->topPtr=NULL;
  Q->tailPtr=NULL;
  return Q;
 }
}

void enqueue(queuePtr Q, Item val){
 Nodo *comodo=malloc(sizeof(Nodo));
 if(comodo==NULL){
  printf("Spazio nell'heap insufficiente. Funzione enqueue() fallita.");
  display(Q);
 }
 else{
  comodo->val=val;
  comodo->nextPtr=NULL;
  if(queueIsEmpty(Q)){
   Q->topPtr=comodo;
   Q->tailPtr=comodo;
  }
  else{
   (Q->tailPtr)->nextPtr=comodo;
   Q->tailPtr=comodo;
  }
  comodo=NULL;
 }
}

Item *dequeue(queuePtr Q){
 Item *p=malloc(sizeof(Item));
 Nodo *comodo;
 if(queueIsEmpty(Q)){
  printf("La coda è vuota\n");
  p=NULL;
 }
 else{
  *p=(Q->topPtr)->val;
  comodo=(Q->topPtr)->nextPtr;
  (Q->topPtr)->nextPtr=NULL;
  free(Q->topPtr);
  Q->topPtr=comodo;
  comodo=NULL;
 }
 return p;
}

bool queueIsEmpty(queuePtr Q){
 return Q->topPtr==NULL;
}

void putItem(Item *ptr){
 if(ptr!=NULL)
  #ifdef intero
   printf("Valore estratto -> %d\n",*ptr);
  #else
   #ifdef virgola
    printf("Valore estratto -> %f\n",*ptr);
   #else
    #ifdef struttura
     printf("Valore estratto -> %d\n",(*ptr)->element);
    #else
     printf("Valore estratto ->  %c\n",*ptr);   
    #endif
   #endif
  #endif
 ptr=NULL;
}

Item getItem(){
 #ifdef intero
  int x;
  printf("Inserisci un numero intero\n");
  scanf("%d",&x);
 #else
  #ifdef virgola
   float x;
   printf("Inserisci un numero reale\n");
   scanf("%f",&x);
  #else
   char x;
   printf("Inserisci un carattere\n");
   scanf("%c",&x);
  #endif
 #endif
 return x;
}

void display(queuePtr Q){
 Nodo *comodo=Q->topPtr;
 if(queueIsEmpty(Q))
  printf("La coda è vuota\n");
 else{
  while(comodo!=NULL){
   #ifdef intero
   printf(" %d -> ",comodo->val);
   #else
    #ifdef virgola
     printf(" %f -> ",comodo->val);
    #else
     #ifdef struttura
      Item com;
      com=comodo->val;
      printf(" %d -> ",com->element);
     #else
      printf(" %c -> ",comodo->val);   
     #endif
    #endif
   #endif
   comodo=comodo->nextPtr;
  }
  printf("\n");
 }
}