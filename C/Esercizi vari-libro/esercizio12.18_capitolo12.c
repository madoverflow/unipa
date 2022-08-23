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
static void treeDeleteMin(Nodo **radPtr);
static void deleteMin(Nodo **radPtr);
static void treeDeleteDuplicate(Nodo *radPtr);
static int *getMin(Nodo *radPtr);

static size_t level=0;

void main(){
 Nodo *rootPtr=NULL;
 srand(time(NULL));
 for(int i=0; i<20; i++)
  treeInsert(&rootPtr,rand()%100);
 treePrint(rootPtr);
 treeDeleteDuplicate(rootPtr);
 printf("Albero senza duplicati\n");
 treePrint(rootPtr);
 printf("%ld\n",level2);
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
 else{
  display(radPtr);
  printf("\n");
 }
}

static void display(Nodo *curPtr){
 if(curPtr!=NULL){
  level++;
  display(curPtr->rightPtr);
  printf(">%*s%5d\n",level*5,"", curPtr->val);
  display(curPtr->leftPtr);
  level --;
 }
}

static void treeDeleteDuplicate(Nodo *radPtr){
 if(radPtr!=NULL){
  int *comodoPtr;
  comodoPtr=getMin(radPtr->rightPtr);
  while((comodoPtr!=NULL)&&(*comodoPtr==radPtr->val)){
   treeDeleteMin(&(radPtr->rightPtr));
   comodoPtr=getMin(radPtr->rightPtr);
  }
  treeDeleteDuplicate(radPtr->rightPtr);
  treeDeleteDuplicate(radPtr->leftPtr);
 }
}

static void treeDeleteMin(Nodo **radPtr){
 if(*radPtr==NULL)
  printf("Albero vuoto\n");
 else
  deleteMin(radPtr);
}

static void deleteMin(Nodo **radPtr){
 //caso base
 if((*radPtr)->leftPtr==NULL){
  Nodo *comodoPtr=(*radPtr)->rightPtr;
  (*radPtr)->rightPtr=NULL;
  free(*radPtr);
  *radPtr=comodoPtr;
  comodoPtr=NULL;
 }//chiamata ricorsiva
 else
  deleteMin(&((*radPtr)->leftPtr));
}

static int *getMin(Nodo *radPtr){
 int *x=malloc(sizeof(int));
 //caso base
 if(radPtr==NULL)
  return NULL;
 if(radPtr->leftPtr==NULL){
  *x=radPtr->val;
  return x;
 }
 //chiamata ricorsiva
 getMin(radPtr->leftPtr);
}