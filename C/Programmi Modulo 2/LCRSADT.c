#include <stdio.h>
#include <stdlib.h>
#include "interfaceLCRSADT.h"

typedef struct lnode{
 Item val;
 struct lnode *childPtr;
 struct lnode *brotherPtr;
}nodeLCRS;

typedef struct bnode{
 Item val;
 struct bnode *leftPtr;
 struct bnode *rightPtr;
}nodeBST;


static void insert(nodeLCRS *comodoPtr, nodeLCRS ** radPtr);
static void lcrsDisplay(const nodeLCRS *radPtr);
static void insertBST(nodeBST **radBST, nodeLCRS *radLCRS);
static void bstDisplay(const nodeBST * const radPtr);

static nodeLCRS *rootLCRS;
static nodeBST *rootBST=NULL;
static int level=0;

void lcrsInit(){
 rootLCRS=NULL;
}

bool lcrsIsEmpty(){
 return rootLCRS==NULL;
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

void lcrsInsert(const Item a){
 nodeLCRS *comodoPtr=malloc(sizeof(nodeLCRS));
 if(comodoPtr==NULL)
  printf("Spazio nell'heap insufficiente. Inserimento nodo fallito.\n");
 else{
  comodoPtr->val=a;
  comodoPtr->childPtr=NULL;
  comodoPtr->brotherPtr=NULL;
  insert(comodoPtr,&rootLCRS);
  comodoPtr=NULL;
 }
}

static void insert(nodeLCRS *comodoPtr, nodeLCRS ** const radPtr){
 //caso base
 if(*radPtr==NULL)
  *radPtr=comodoPtr;
 //chiamata ricorsiva
 else{
  if((comodoPtr->val)>(*radPtr)->val)
   insert(comodoPtr, &((*radPtr)->brotherPtr));
  if((comodoPtr->val)<(*radPtr)->val)
   insert(comodoPtr, &((*radPtr)->childPtr));
 }
}

void lcrsPrint(){
 if(lcrsIsEmpty())
  printf("Albero LCRS vuoto\n");
 else{
  lcrsDisplay(rootLCRS);
  printf("\n");
 }
}

static void lcrsDisplay(const nodeLCRS *radPtr){
 if(radPtr!=NULL){
  #ifdef intero
   printf("%5d",radPtr->val);
  #else
   #ifdef virgola
    printf("%5f",radPtr->val);
    #else
    #ifdef stringhe
     printf("%5s",radicePtr->val);
    #else
     printf("%5c",radicePtr->val);
    #endif
   #endif
  #endif
  lcrsDisplay(radPtr->brotherPtr);
  lcrsDisplay(radPtr->childPtr);
 }
}

void lcrsToBst(){
 nodeBST *comodoBST;
 if(lcrsIsEmpty())
  printf("Albero LCRS vuoto\n");
 else{
  comodoBST=malloc(sizeof(nodeBST));
  comodoBST->rightPtr=NULL;
  comodoBST->leftPtr=NULL;
  comodoBST->val=rootLCRS->val;
  rootBST=comodoBST;
  comodoBST=NULL;
  insertBST(&(rootBST->rightPtr),rootLCRS->brotherPtr);
  insertBST(&(rootBST->leftPtr),rootLCRS->childPtr);
 }
}

static void insertBST(nodeBST **radBST, nodeLCRS *radLCRS){
 if(radLCRS!=NULL){
  nodeBST *comodoBST=malloc(sizeof(nodeBST));
  comodoBST->rightPtr=NULL;
  comodoBST->leftPtr=NULL;
  comodoBST->val=radLCRS->val;
  *radBST=comodoBST;
  comodoBST=NULL;
  insertBST(&((*radBST)->rightPtr),radLCRS->brotherPtr);
  insertBST(&((*radBST)->leftPtr),radLCRS->childPtr);
 }
}

void bstPrint(){
  if(rootBST==NULL)
   printf("BST vuoto\n");
  else
   bstDisplay(rootBST);
}

static void bstDisplay(const nodeBST * const radPtr){
 if(radPtr!=NULL){
  level++;
  bstDisplay(radPtr->rightPtr);
  #ifdef intero
   printf(">%*s%5d\n",level*5,"", radPtr->val);
  #else
   #ifdef virgola
    printf(">%*s%5f\n",level*5,"", radPtr->val);
    #else
    #ifdef stringhe
     printf(">%*s%5s\n",level*5,"", radPtr->val);
    #else
     printf(">%*s%5c\n",level*5,"", radPtr->val);
    #endif
   #endif
  #endif
  bstDisplay(radPtr->leftPtr);
  level--;
 }
}