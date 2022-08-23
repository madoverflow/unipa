#include <stdio.h>
#include <stdlib.h>
#include "interfaceStackADT.h"
typedef struct node{
 Item info;
 struct node *nextPtr;
}Nodo;
void comodoPrintStack(Nodo *ptr);

static Nodo *top=NULL;


Item take(){
 Item a;
 #ifdef intero
  printf("Inserisci il valore (intero) da aggiungere allo stack\n");
  scanf("\n%d",&a);
 #else
  #ifdef virgola
   printf("Inserisci il valore (float) da aggiungere allo stack\n");
   scanf("\n%f",&a);
  #else
   printf("Inserisci il valore (char) da aggiungere allo stack\n");
   scanf("\n%c",&a);
  #endif
 #endif
 return a;
}
void printItem(const Item a){
  #ifdef intero
  printf("Stampa item: %d\n",a);
 #else
  #ifdef virgola
   printf("Stampa item: %f\n",a);
  #else
   printf("Stampa item: %c\n",a);
  #endif
 #endif	
}

void stackPush(const Item a){
 Nodo *node=malloc(sizeof(Nodo));
 //malloc fallita
 if(node==NULL)
  printf("Memoria insufficiente nell'heap\n");
 else{
  node->info=a;
  //lista vuota
  if(stackIsEmpty()){
   node->nextPtr=NULL;
   top=node;
  }
  //lista non vuota
  else{
   node->nextPtr=top;
   top=node;
  }
 }
}

void printStack(){
 Nodo *comodo=top;
 if(stackIsEmpty())
  printf("Stack vuoto\n");
 else{
  comodoPrintStack(comodo);
  printf("\n");
 }
}

void comodoPrintStack(Nodo *ptr){
 if(ptr!=NULL){
  #ifdef intero
   printf(" -> %d",ptr->info);
  #else
   #ifdef virgola
    printf(" -> %f",ptr->info);
   #else
    printf(" -> %c",ptr->info);
   #endif
  #endif
  ptr=ptr->nextPtr;
  comodoPrintStack(ptr);
 }
}

bool stackIsEmpty(){
 return top==NULL;
}

Item stackPop(){
 Item a=top->info;
 Nodo *comodo=top->nextPtr;
 top->nextPtr=NULL;
 free(top);
 top=comodo;
 return a;
}
