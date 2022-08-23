#include <stdio.h>
#include <stdlib.h>
#include "interfaceStackADT_FC.h"

typedef struct node{
 Item val;
 struct node *nextPtr;
}Nodo;

struct stack{
 Nodo *topPtr;
};
typedef struct stack Stack;

static void putItemStack(Item a);

S stackInit(S stackPtr){
 stackPtr=malloc(sizeof(Stack));
 if(stackPtr==NULL){
  printf("Spazio nell'heap insufficiente. Stack non creato\n");
  stackPtr=NULL;
 }
 else
  stackPtr->topPtr=NULL;
 return stackPtr;
}

bool stackIsEmpty(S stackPtr){
 return (stackPtr->topPtr==NULL)||(stackPtr==NULL);
}

void stackPush(S stackPtr, Item a){
 Nodo *comodoPtr=malloc(sizeof(Nodo));
 if(comodoPtr==NULL)
  printf("Spazio nell'heap insufficiente. Funzione push fallita.\n");
 else{
  comodoPtr->val=a;
  if(stackIsEmpty(stackPtr)){
   comodoPtr->nextPtr=NULL;
   stackPtr->topPtr=comodoPtr;
  }
  else{
   comodoPtr->nextPtr=stackPtr->topPtr;
   stackPtr->topPtr=comodoPtr;
  }
  comodoPtr=NULL;
 }
}

Item *stackPop(S stackPtr){
 Item *valore=malloc(sizeof(Item));
 Nodo *comodoPtr;
 if(stackIsEmpty(stackPtr))
  printf("Stack vuoto\n");
 else{
  comodoPtr=stackPtr->topPtr;
  stackPtr->topPtr=comodoPtr->nextPtr;
  comodoPtr->nextPtr=NULL;
  *valore=comodoPtr->val;
  free(comodoPtr);
  comodoPtr=NULL;
 }
 return valore;
}

void stackDisplay(S stackPtr){
 Nodo *comodoPtr;
 if(stackIsEmpty(stackPtr))
  printf("Stack vuoto\n");
 else{
  comodoPtr=stackPtr->topPtr;
  while(comodoPtr!=NULL){
   putItemStack(comodoPtr->val);
   comodoPtr=comodoPtr->nextPtr;
  }
  printf("\n");
 }
}

static void putItemStack(Item a){
 #ifdef intero
  printf("%d -> ",a);
 #else
  #ifdef virgola
   printf("%f -> ",a);
  #else
   printf("%c -> ",a);
  #endif
 #endif
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