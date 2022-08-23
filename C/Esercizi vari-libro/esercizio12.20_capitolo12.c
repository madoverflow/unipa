#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
 int val;
 struct node *nextPtr;
}Nodo;

static void insertList(Nodo **topPtr, Nodo **tailPtr, size_t x);
static void display(Nodo *curPtr);
static void printListBackward(Nodo *topPtr);
static void reverse(Nodo *curPtr);

void main(){
 Nodo *topPtr=NULL,*tailPtr=NULL;
 for(int i=0; i<20; i++)
  insertList(&topPtr,&tailPtr,rand()%100);
 printf("Stampa lista\n");
 display(topPtr);
 printf("Stampa lista al contrario\n");
 printListBackward(topPtr);
}

static void insertList(Nodo **topPtr, Nodo **tailPtr, size_t x){
 Nodo *newPtr=malloc(sizeof(Nodo));
 newPtr->val=x;
 newPtr->nextPtr=NULL;
 if(*topPtr==NULL){
  *topPtr=newPtr;
  *tailPtr=newPtr;
 }
 else{
  (*tailPtr)->nextPtr=newPtr;
  *tailPtr=newPtr;
 }
 newPtr=NULL;
}

static void display(Nodo *curPtr){
 if(curPtr==NULL)
  printf("Lista vuota\n");
 else{
  while(curPtr!=NULL){
   printf("%d -> ",curPtr->val);
   curPtr=curPtr->nextPtr;
  }
  printf("\n");
 }
}

static void printListBackward(Nodo *topPtr){
 if(topPtr==NULL)
  printf("Lista vuota\n");
 else{
  reverse(topPtr);
  printf("\n");
 }
}

static void reverse(Nodo *curPtr){
 if(curPtr!=NULL){
   reverse(curPtr->nextPtr);
   printf("%d -> ",curPtr->val);
 }
}