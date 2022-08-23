#include <stdio.h>
#include <stdlib.h>
#include "interfaceDequeADT.h"

typedef struct Node{
 Item val;
 struct Node *nextPtr;
 struct Node *prevPtr;
}Nodo;

static Nodo *top,*tail; 
static size_t flag;

void dequeInit(){
 top=NULL;
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

void pushDeque(Item a){
 Nodo *comPtr=malloc(sizeof(Nodo));
 if(comPtr==NULL){
  printf("Spazio nell'heap insufficiente. Operazione di inserimento fallita.\n");
  display();
 }
 else{
  comPtr->val=a;
  do{
   printf("Inserisci:\n1- per inserire l'elemento all'inizio\n0- per inserire l'elemento alla fine\n");
   scanf("%ld",&flag);
  }while((flag)&&(flag!=1));
  if(dequeIsEmpty()){
   comPtr->nextPtr=NULL;
   comPtr->prevPtr=NULL;
   top=comPtr;
   tail=comPtr;
  }
  else{
   if(flag){
    top->prevPtr=comPtr;
    comPtr->nextPtr=top;
    comPtr->prevPtr=NULL;
    top=comPtr;
   }
   else{
    tail->nextPtr=comPtr;
    comPtr->prevPtr=tail;
    comPtr->nextPtr=NULL;
    tail=comPtr;
   }
  }
  comPtr=NULL;
 }
}

Item *popDeque(){
 Item *ptr=NULL,comodo;
 Nodo *comPtr;
 if(dequeIsEmpty())
  printf("Il Deque è vuoto\n");
 else{
  do{
   printf("Inserisci:\n1- per estrarre l'elemento in cima\n0- per estrarre l'elemento in coda\n");
   scanf("%ld",&flag);
  }while((flag)&&(flag!=1));
  if(flag){
   comodo=top->val;
   comPtr=top->nextPtr;
   (top->nextPtr)->prevPtr=NULL;
   top->nextPtr=NULL;
   free(top);
   top=comPtr;
  }
  else{
   comodo=tail->val;
   comPtr=tail->prevPtr;
   (tail->prevPtr)->nextPtr=NULL;
   tail->prevPtr=NULL;
   free(tail);
   tail=comPtr;
  }
  comPtr=NULL;
  ptr=&comodo;
 }
 return ptr;
}

bool dequeIsEmpty(){
 return top==NULL;
}

void display(){
 Nodo *comodo=top;
 if(dequeIsEmpty())
  printf("Il Deque è vuoto\n");
 else{
  while(comodo!=NULL){
   #ifdef intero
   printf(" %d -> ",comodo->val);
   #else
    #ifdef virgola
     printf(" %f -> ",comodo->val);
     #else
      printf(" %c -> ",comodo->val);   
    #endif
   #endif
   comodo=comodo->nextPtr;
  }
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
     printf("Valore estratto ->  %c\n",*ptr);   
   #endif
  #endif
 ptr=NULL;
}
