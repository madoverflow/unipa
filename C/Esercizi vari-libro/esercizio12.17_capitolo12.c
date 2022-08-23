#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
 char *val;
 struct node *rightPtr;
 struct node *leftPtr;
}Nodo;

static void treeInsert(Nodo **radPtr, char *x);
static void treePrint(Nodo *radPtr);
static void display(Nodo *radPtr);
static void treeInOrder(Nodo *radPtr);
static void displayInOrder(Nodo *radPtr);
static void treePreOrder(Nodo *radPtr);
static void displayPreOrder(Nodo *radPtr);
static void treePostOrder(Nodo *radPtr);
static void displayPostOrder(Nodo *radPtr);

static size_t level=0;

void main(){
 Nodo *rootPtr=NULL;
 char str[81],*token;
 printf("Inserisci una stringa di massimo 80 elementi\n");
 gets(str);
 token=strtok(str," ");
 treeInsert(&rootPtr,token);
 while((token=strtok(NULL," "))!=NULL)
  treeInsert(&rootPtr,token);
 treePrint(rootPtr);
 treeInOrder(rootPtr);
 treePostOrder(rootPtr);
 treePreOrder(rootPtr);
}

static void treeInsert(Nodo **radPtr, char *x){
 Nodo *newPtr=malloc(sizeof(Nodo));
 newPtr->val=x;
 newPtr->rightPtr=NULL;
 newPtr->leftPtr=NULL;
 while(*radPtr!=NULL){
  if(strcmp(x,(*radPtr)->val)>0)
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
 printf("\n");
}

static void display(Nodo *radPtr){
 if(radPtr!=NULL){
  level++;
  display(radPtr->rightPtr);
  printf(">%*s%5s\n",level*5,"", radPtr->val);
  display(radPtr->leftPtr);
  level--;
 }
}

static void treeInOrder(Nodo *radPtr){
 if(radPtr==NULL)
  printf("Albero vuoto\n");
 else
  displayInOrder(radPtr);
 printf("\n");
}

static void displayInOrder(Nodo *radPtr){
 if(radPtr!=NULL){
  displayInOrder(radPtr->leftPtr);
  printf("%s -> ",radPtr->val);
  displayInOrder(radPtr->rightPtr);
 }
}

static void treePreOrder(Nodo *radPtr){
 if(radPtr==NULL)
  printf("Albero vuoto\n");
 else
  displayPreOrder(radPtr);
 printf("\n");
}

static void displayPreOrder(Nodo *radPtr){
 if(radPtr!=NULL){
  printf("%s -> ",radPtr->val);
  displayPreOrder(radPtr->rightPtr);
  displayPreOrder(radPtr->leftPtr);
 }
}

static void treePostOrder(Nodo *radPtr){
 if(radPtr==NULL)
  printf("Albero vuoto\n");
 else
  displayPostOrder(radPtr);
 printf("\n");
}

static void displayPostOrder(Nodo *radPtr){
 if(radPtr!=NULL){
  displayPostOrder(radPtr->rightPtr);
  displayPostOrder(radPtr->leftPtr);
  printf("%s -> ",radPtr->val);
 }
}