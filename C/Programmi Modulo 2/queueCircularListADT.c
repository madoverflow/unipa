#include <stdio.h>
#include <stdlib.h>
#include "interfaceQueueADT.h"

typedef struct node{
 Item val;
 struct node *nextPtr;
 struct node *prevPtr;
}Nodo;

static Nodo *tail;

void queueInit(){
 tail=NULL;
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

bool queueIsEmpty(){
 return tail==NULL;
}

void enqueue(Item val){
 Nodo *comPtr=malloc(sizeof(Nodo));
 Nodo *comodo=NULL;
 if(comPtr==NULL){
  printf("Spazio nell'heap insufficiente. Funzione enqueue() fallita.\n");
  display();
 }
 else{
  comPtr->val=val;
  if(queueIsEmpty()){
   comPtr->nextPtr=comPtr;
   comPtr->prevPtr=NULL;
   tail=comPtr;
  }
  else{
   comPtr->prevPtr=tail;
   comodo=tail->nextPtr;
   tail->nextPtr=comPtr;
   comPtr->nextPtr=comodo;
   tail=comPtr;
  }
  comPtr=NULL;
  comodo=NULL;
 }
}

Item *dequeue(){
 Item *p=NULL,comodo;
 Nodo *ptr;
 if(queueIsEmpty())
  printf("La coda è vuota\n");
 else{
  if((tail->prevPtr)==NULL){
   comodo=tail->val;
   tail->nextPtr=NULL;
   free(tail);
   tail=NULL;
  }
  else{
   ptr=tail->nextPtr;
   comodo=ptr->val;
   tail->nextPtr=ptr->nextPtr;
   (ptr->nextPtr)->prevPtr=NULL;
   ptr->nextPtr=NULL;
   ptr->prevPtr=NULL;
   free(ptr);
   ptr=NULL;
  }
  p=&comodo;
 }
 return p;
}

void display(){
 Nodo *comodo;
 if(queueIsEmpty())
  printf("La coda è vuota\n");
 else{
  comodo=tail->nextPtr;
  do{
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
  }while((comodo->prevPtr)!=NULL);
  printf("\n");
 }
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