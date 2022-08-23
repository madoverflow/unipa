#include <stdio.h>
#include <stdlib.h>
#include "interfaceQueueADT.h"

typedef struct node{
 Item val;
 struct node *nextPtr;
}Nodo;

static Nodo *tail,*top;

void queueInit(){
 tail=NULL;
 top=NULL;
}

/*Item getItem(){
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
}*/

bool queueIsEmpty(){
 return top==NULL;
}

void enqueue(Item val){
 Nodo *comodo=malloc(sizeof(Nodo));
 if(comodo==NULL){
  printf("Spazio nell'heap insufficiente. Funzione enqueue() fallita.");
  display();
 }
 else{
  comodo->val=val;
  comodo->nextPtr=NULL;
  if(queueIsEmpty()){
   top=comodo;
   tail=comodo;
  }
  else{
   tail->nextPtr=comodo;
   tail=comodo;
  }
  comodo=NULL;
 }
}

Item *dequeue(){
 Item *p=malloc(sizeof(Item));
 Nodo *comodo;
 if(queueIsEmpty()){
  printf("La coda è vuota\n");
  free(p);
  p=NULL;
 }
 else{
  *p=top->val;
  comodo=top->nextPtr;
  top->nextPtr=NULL;
  free(top);
  top=comodo;
  comodo=NULL;
 }
 return p;
}

void display(){
 Nodo *comodo=top;
 if(queueIsEmpty())
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
      printf(" %d -> ",com->val);
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

/*void putItem(Item *ptr){
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
}*/