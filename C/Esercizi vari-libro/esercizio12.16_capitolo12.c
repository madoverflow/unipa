#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
 int val;
 struct node *rightPtr;
 struct node *leftPtr;
}Nodo;

static void treeInsert(Nodo **radPtr, size_t x);
static void treePrint(Nodo *radPtr);
static void display(Nodo *curPtr);

static size_t level=0;

void main(){
 Nodo *rootPtr=NULL;
 srand(time(NULL));
 for(int i=0; i<20; i++)
  treeInsert(&rootPtr,rand()%100);
 treePrint(rootPtr);
}

static void treeInsert(Nodo **radPtr, size_t x){
 Nodo *newPtr=malloc(sizeof(Nodo));
 newPtr->val=x;
 newPtr->rightPtr=NULL;
 newPtr->leftPtr=NULL;
 //albero vuoto
 while(*radPtr!=NULL){
  if(x>=(*radPtr)->val)
   radPtr=&((*radPtr)->rightPtr);
  else
   radPtr=&((*radPtr)->leftPtr);
 }
 *radPtr=newPtr;
 newPtr=NULL;
}

static void treePrint(Nodo *radPtr){
 if(radPtr==NULL)
  printf("Albero vuoto\n");
 else
  display(radPtr);
}

static void display(Nodo *curPtr){
 if(curPtr!=NULL){
  level++;
  display(curPtr->rightPtr);
  printf(">%*s%5d\n",level*5,"", curPtr->val);
  display(curPtr->leftPtr);
  level--;
 }
}