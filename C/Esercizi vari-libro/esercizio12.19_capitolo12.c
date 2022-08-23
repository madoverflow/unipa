#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodeB{
 int val;
 struct nodeB *rightPtr;
 struct nodeB *leftPtr;
};
struct nodeL{
 struct nodeB *nodoPtr;
 struct nodeL *nextPtr;
};
typedef struct nodeB NodoB;
typedef struct nodeL NodoL;

static void treeInsert(NodoB **radPtr, size_t x);
static void insert(NodoB **radPtr, NodoB *newPtr);
static void treePrint(NodoB *radPtr);
static void display(NodoB *curPtr);
static NodoB *treeLevelOrder(NodoB *radPtr, NodoL **topPtr, NodoL **tailPtr);
static void enqueue(NodoB *nodePtr, NodoL **topPtr, NodoL **tailPtr);
static NodoB *dequeue(NodoL **topPtr);
static size_t distance(NodoB *comodoPtr, NodoB *rootPtr);

static size_t level=0;

void main(){
 NodoB *rootPtr=NULL,*comodoPtr=NULL;
 NodoL *topPtr=NULL,*tailPtr=NULL;
 size_t val;
 srand(time(NULL));
 for(int i=0; i<20; i++)
  treeInsert(&rootPtr,rand()%100);
 treePrint(rootPtr);
 comodoPtr=treeLevelOrder(rootPtr,&topPtr,&tailPtr);
 val=distance(comodoPtr,rootPtr);
 printf("Numero livelli albero %d\n",val);
}

static void treeInsert(NodoB **radPtr, size_t x){
 NodoB *newPtr=malloc(sizeof(NodoB));
 NodoB **comodoPtr;
 newPtr->val=x;
 newPtr->rightPtr=NULL;
 newPtr->leftPtr=NULL;
 insert(radPtr,newPtr);
 newPtr=NULL;
}

static void insert(NodoB **radPtr, NodoB *newPtr){
 //caso base
 if(*radPtr==NULL)
   *radPtr=newPtr;
 else
  if(((*radPtr)->val)!=newPtr->val){
   if(newPtr->val>(*radPtr)->val)
	 insert(&((*radPtr)->rightPtr),newPtr);
   else
	 insert(&((*radPtr)->leftPtr),newPtr);
  }
}

static void treePrint(NodoB *radPtr){
 if(radPtr==NULL)
  printf("Albero vuoto\n");
 else{
  display(radPtr);
  printf("\n");
 }
}

static void display(NodoB *curPtr){
 if(curPtr!=NULL){
  level++;
  display(curPtr->rightPtr);
  printf(">%*s%5d\n",level*5,"", curPtr->val);
  display(curPtr->leftPtr);
  level --;
 }
}

static NodoB *treeLevelOrder(NodoB *radPtr, NodoL **topPtr, NodoL **tailPtr){
 NodoB *comPtr;
 enqueue(radPtr,topPtr,tailPtr);
 while(*topPtr!=NULL){
  comPtr=dequeue(topPtr);
  if(comPtr->rightPtr!=NULL)
   enqueue(comPtr->rightPtr,topPtr,tailPtr);
  if(comPtr->leftPtr!=NULL)
   enqueue(comPtr->leftPtr,topPtr,tailPtr);
 }
 return comPtr;
}

static void enqueue(NodoB *nodePtr, NodoL **topPtr, NodoL **tailPtr){
 NodoL *newPtr=malloc(sizeof(NodoL));
 newPtr->nodoPtr=nodePtr;
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

static NodoB *dequeue(NodoL **topPtr){
 NodoB *valPtr=NULL;
 NodoL *comodoPtr=NULL;
 if(*topPtr==NULL)
  printf("Coda vuota\n");
 else{
  comodoPtr=*topPtr;
  valPtr=comodoPtr->nodoPtr;
  *topPtr=comodoPtr->nextPtr;
  comodoPtr->nextPtr=NULL;
  free(comodoPtr);
 }
 return valPtr;
}

static size_t distance(NodoB *comodoPtr, NodoB *rootPtr){
 size_t x=1;
 if(rootPtr==NULL){
  printf("Albero vuoto\n");
  x=0;
 }
 else
  while((rootPtr->val)!=(comodoPtr->val)){
   x++;
   if((comodoPtr->val)>(rootPtr->val))
    rootPtr=rootPtr->rightPtr;
   else
	rootPtr=rootPtr->leftPtr;
  }
 return x;
}