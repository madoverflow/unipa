#include <stdio.h>
#include <stdlib.h>
#include "treeInterface.h"

struct node{
 Item val;
 struct node *rightPtr;
 struct node *leftPtr;
};

struct albero{
 struct node *rootPtr;
};

typedef struct node Nodo;
typedef struct albero Albero;

static void insert(Nodo **radPtr, Nodo *newPtr);
static void display(Nodo *radPtr);
static Item getMin(Nodo *radPtr);
static void deleteMin(Nodo **curPtr);
static void search(Nodo *curPtr, Item x, int *val);
static int yourChildren(Nodo *radPtr, Item a, Item b);

static int level=0;

Tree treeInit(Tree t){
 t=malloc(sizeof(Albero));
 t->rootPtr=NULL;
 return t;
}

char treeIsEmpty(Tree t){
 return t->rootPtr==NULL;
}

void treeInsert(Tree t, Item x){
 Nodo *newPtr=malloc(sizeof(Nodo));
 newPtr->rightPtr=NULL;
 newPtr->leftPtr=NULL;
 newPtr->val=x;
 insert(&(t->rootPtr),newPtr);
}

static void insert(Nodo **radPtr, Nodo *newPtr){
 //caso base
 if(*radPtr==NULL)
  *radPtr=newPtr;
 //chiamata ricorsiva
 else{
  if(newPtr->val>(*radPtr)->val)
   insert(&((*radPtr)->rightPtr),newPtr);
  if(newPtr->val<(*radPtr)->val)
   insert(&((*radPtr)->leftPtr),newPtr);
 }
}

void printTree(Tree t){
 if(treeIsEmpty(t))
  printf("Albero vuoto\n");
 else
  display(t->rootPtr);
}

static void display(Nodo *radPtr){
 if(radPtr!=NULL){
  level++;
  display(radPtr->rightPtr);
  printf(">%*s%5d\n",level*5,"", radPtr->val);
  display(radPtr->leftPtr);
  level--;
 }
}

int treeSearch(Tree t, Item x){
 int val=0;
 Nodo *curPtr;
 if(treeIsEmpty(t)){
  printf("Albero vuoto\n");
  val=-1;
 }
 else{
  curPtr=t->rootPtr;
  while((curPtr!=NULL)&&(curPtr->val!=x)){
   if(x>curPtr->val)
    curPtr=curPtr->rightPtr;
   else
    curPtr=curPtr->leftPtr;
   val++;
  }
  if(curPtr==NULL){
   printf("Valore non trovato\n");
   val=-1;
  }
  else
   printf("Valore trovato. Nodi attraversati -> %d\n",val);
 }
 return val;
}

void treeDelete(Tree t, Item x){
 Nodo **curPtr=&(t->rootPtr);
 Nodo *comodoPtr;
 Item min;
 while((*curPtr!=NULL)&&((*curPtr)->val!=x)){
  if(x>(*curPtr)->val)
   curPtr=&((*curPtr)->rightPtr);
  else
   curPtr=&((*curPtr)->leftPtr);
 }
 if(*curPtr==NULL)
  printf("Il valore inserito non fa parte dell'albero.\n");
 else{
  if((*curPtr)->rightPtr==NULL){
   comodoPtr=(*curPtr)->leftPtr;
   (*curPtr)->leftPtr=NULL;
   free(*curPtr);
   *curPtr=comodoPtr;
   return;
  }
  if((*curPtr)->leftPtr==NULL){
   comodoPtr=(*curPtr)->rightPtr;
   (*curPtr)->rightPtr=NULL;
   free(*curPtr);
   *curPtr=comodoPtr;
   return;
  }
  min=getMin((*curPtr)->rightPtr);
  (*curPtr)->val=min;
  deleteMin(&((*curPtr)->rightPtr));
  comodoPtr=NULL;
 }
}

static Item getMin(Nodo *curPtr){
 while(curPtr->leftPtr!=NULL)
  curPtr=curPtr->leftPtr;
 return curPtr->val;
}

static void deleteMin(Nodo **curPtr){
 Nodo *comodoPtr;
 while((*curPtr)->leftPtr!=NULL)
  curPtr=&((*curPtr)->leftPtr);
 comodoPtr=(*curPtr)->rightPtr;
 (*curPtr)->rightPtr=NULL;
 free(*curPtr);
 *curPtr=comodoPtr;
 comodoPtr=NULL;
}

int treeRecursiveSearch(Tree t, Item x){
 int val=0;
 search(t->rootPtr,x,&val);
 return val;
}

static void search(Nodo *curPtr, Item x, int *val){
 //caso base
 if(curPtr==NULL){
  *val=-1;
  return;
 }
 //chiamata ricorsiva
 if(curPtr->val!=x){
  *val+=1;
  if(x>curPtr->val)
   search(curPtr->rightPtr,x,val);
  else
   search(curPtr->leftPtr,x,val);
  }
}

int treeDistance(Tree t, Item a, Item b){
 Nodo *curPtr=t->rootPtr;
 int distanza=-1,flag,dist1,dist2;
 while((curPtr!=NULL)&&((flag=yourChildren(curPtr,a,b))!=0)){
  if(flag==1)
   curPtr=curPtr->rightPtr;
  else
   curPtr=curPtr->leftPtr;
 }
 if(curPtr!=NULL){
  search(curPtr,a,&dist1);
  search(curPtr,b,&dist2);
  if((dist1!=-1)&&(dist2!=-1))
   distanza=dist1+dist2;
 }
 return distanza;
}

static int yourChildren(Nodo *radPtr, Item a, Item b){
 if(a>radPtr->val&&b>radPtr->val)
  return 1;
 if(a<radPtr->val&&b<radPtr->val)
  return -1;
 return 0;
} 
