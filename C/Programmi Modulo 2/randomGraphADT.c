#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "interfaceRandomGraphADT.h"

typedef struct lnode{
 int v;
 struct lnode *nextPtr;
}nodeList;

typedef struct gnode{
 int val;
 int Nneighbors;
 nodeList *topPtr;
}graphNode;

static void Nneighbors();
static void adiacente(size_t a, size_t b);
static bool graphIsEmpty();

static graphNode **arrayGraph;
static size_t SIZE=0;

void graphInit(size_t N){
 int valore;
 graphNode *comodoPtr;
 nodeList *listPtr;
 if(N<=0){
  printf("Dimensione albero non corretta. Creazione fallita\n");
  return;
 }
 arrayGraph=malloc(N*sizeof(graphNode *));
 if(arrayGraph==NULL)
  printf("Spazio nell'heap insufficiente. Creazione grafo fallita.\n");
 else{
  srand(time(NULL));
  SIZE=N;
  for(int i=0; i<N; i++){
   valore=rand()%1000;
   comodoPtr=malloc(sizeof(graphNode));
   listPtr=malloc(sizeof(nodeList));
   listPtr->nextPtr=NULL;
   comodoPtr->val=valore;
   comodoPtr->Nneighbors=0;
   comodoPtr->topPtr=listPtr;
   arrayGraph[i]=comodoPtr;
  }
  Nneighbors();
 }
}

static void Nneighbors(){
 size_t a,b;
 if(3<SIZE){
  adiacente(3,0);
  adiacente(0,3);
 } 
 for(int i=1; i<SIZE; i++){
  a=i-1;
  b=i+3;
  adiacente(a,i);
  adiacente(i,a);
  if(b<SIZE){
  adiacente(b,i);
  adiacente(i,b);
  }
 }
}

static void adiacente(size_t a, size_t b){
 nodeList *comodoPtr;
 comodoPtr=malloc(sizeof(nodeList));
 comodoPtr->v=arrayGraph[a]->val;
 comodoPtr->nextPtr=arrayGraph[b]->topPtr;
 arrayGraph[b]->topPtr=comodoPtr;
 arrayGraph[b]->Nneighbors+=1;
}

void printGraphNodes(){
 if(graphIsEmpty())
  printf("Grafo vuoto\n");
 else{
  printf("Nodi dell'albero\n");
  for(int i=0; i<SIZE; i++)
   printf("%3d -> ",arrayGraph[i]->val);
  printf("\n");
 }
}

void printNeighbors(){
 nodeList *listPtr;
 if(graphIsEmpty())
  printf("Grafo vuoto\n");
 else{
  for(int i=0; i<SIZE; i++){
   printf("Numero nodi adiacenti del nodo %d: %d\n",arrayGraph[i]->val,arrayGraph[i]->Nneighbors);
   printf("Lista nodi adiacenti\n");
   listPtr=arrayGraph[i]->topPtr;
   while(listPtr->nextPtr!=NULL){
    printf("%3d -> ",listPtr->v);
    listPtr=listPtr->nextPtr;
   }
   printf("\n");
  }
 }
}

static bool graphIsEmpty(){
 return SIZE==0;
}