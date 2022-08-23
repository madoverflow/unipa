#include <stdio.h>
#include <stdlib.h>
#include "interfaceQueueADT.h"
void printList(const NodoList *first);
NodoList *mergesort(NodoList *top);
NodoList *merge(NodoList *list1, NodoList *list2);

void main(){
 NodoList *top=NULL,*tail=NULL,*comPtr=NULL;
 size_t comodo;
 size_t N;
 do{
  printf("Inserisci la dimensione della lista\n");
  scanf("%ld",&N);
 }while(N<=0);
 comPtr=malloc(sizeof(NodoList));
 if(comPtr==NULL)
  printf("Spazio nell'heap insufficiente. Creazione lista fallita.\n");
 else{
  comPtr->element=rand() % 100;
  comPtr->nextPtr=NULL;
  top=comPtr;
  tail=comPtr;
  comPtr=NULL;
  for(int i=1; i<N; i++){
   comPtr=malloc(sizeof(NodoList));
   if(comPtr==NULL)
    printf("Spazio nell'heap insufficiente.\n");
   else{
    comPtr->element=rand() % 100;
    comPtr->nextPtr=NULL;
    tail->nextPtr=comPtr;
    tail=comPtr;
    comPtr=NULL;
   }
  }
  printList(top);
  top=mergesort(top);
  printf("Lista ordinata con algoritmo MergeSort Bottom-Up Queue\n");
  printList(top);
 }
}

void printList(const NodoList *first){
 //caso base
 if(first==NULL)
  printf("\nLista vuota o stampa terminata.\n");
 else{
  printf(" %d -> ",first->element);
  first=first->nextPtr;
  //chiamata ricorsiva
  printList(first);
 }
}

NodoList *mergesort(NodoList *top){
 NodoList *ptr;
 NodoList **comodo;
 //Un solo elemento della coda
 if(top->nextPtr==NULL)
  return top;
 //Lista vuota
 if(top==NULL)
  return NULL;
 //inserimento nodi in una coda
 while(top!=NULL){
  ptr=top->nextPtr;
  top->nextPtr=NULL;
  enqueue(top);
  top=ptr;
 }
 ptr=NULL;
 comodo=dequeue();
 ptr=*comodo;
 while(!queueIsEmpty()){
  enqueue(ptr);
  ptr=merge(*(dequeue()),*(dequeue()));
 }
 display();
 return ptr;
}

NodoList *merge(NodoList *list1, NodoList *list2){
 NodoList * const startpoint=malloc(sizeof(NodoList));
 NodoList *prec=startpoint;
 if((list1->element)<(list2->element)){
  startpoint->element=list1->element;
  startpoint->nextPtr=NULL;
  list1=list1->nextPtr;
 }
 else{
  startpoint->element=list2->element;
  startpoint->nextPtr=NULL;
  list2=list2->nextPtr;
 }
 while((list1!=NULL)&&(list2!=NULL)){
  NodoList *tempoint=malloc(sizeof(NodoList));
  tempoint->nextPtr=NULL;
  if((list1->element)<(list2->element)){
   tempoint->element=list1->element;
   list1=list1->nextPtr;
  }
  else{
   tempoint->element=list2->element;
   list2=list2->nextPtr;
  }

  prec->nextPtr=tempoint;
  prec=tempoint;
 }
 if(list1==NULL)
  while(list2!=NULL){
   NodoList *tempoint=malloc(sizeof(NodoList));
   tempoint->element=list2->element;
   tempoint->nextPtr=NULL;
   list2=list2->nextPtr;
   prec->nextPtr=tempoint;
   prec=tempoint;
 }
 else
  while(list1!=NULL){
   NodoList *tempoint=malloc(sizeof(NodoList));
   tempoint->element=list1->element;
   tempoint->nextPtr=NULL;
   list1=list1->nextPtr;
   prec->nextPtr=tempoint;
   prec=tempoint;
 }
 return startpoint;
}