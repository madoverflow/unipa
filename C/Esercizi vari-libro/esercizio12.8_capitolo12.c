#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
 int val;
 struct node *nextPtr;
}Nodo;

static void insertOrderList(Nodo **topPtr, Nodo *newPtr);
static void printList(Nodo *curPtr);

void main(){
 Nodo *topPtr=NULL,*newPtr=NULL;
 int x;
 srand(time(NULL));
 for(int i=0; i<25; i++){
  x=rand()%101;
  newPtr=malloc(sizeof(Nodo));
  newPtr->val=x;
  insertOrderList(&topPtr,newPtr);
 }
 printList(topPtr);
}

static void insertOrderList(Nodo **topPtr, Nodo *newPtr){
 Nodo **comodoPtr;
 //lista vuota
 if(*topPtr==NULL){
  newPtr->nextPtr=NULL;
  *topPtr=newPtr;
  newPtr=NULL;
 }//lista non vuota
 else{
  comodoPtr=topPtr;
  while( (newPtr->val>(*comodoPtr)->val) && ((*comodoPtr)->nextPtr!=NULL))
   comodoPtr=&((*comodoPtr)->nextPtr);
  if((*comodoPtr)->val!=newPtr->val){
   if(newPtr->val<(*comodoPtr)->val){
    newPtr->nextPtr=*comodoPtr;
	*comodoPtr=newPtr;
	newPtr=NULL;
   }
   else{
    (*comodoPtr)->nextPtr=newPtr;
	newPtr->nextPtr=NULL;
	newPtr=NULL;
   }
  }
  comodoPtr=NULL;
 }
}

static void printList(Nodo *curPtr){
 if(curPtr==NULL)
  printf("\n");
 else{
  printf("%d -> ",curPtr->val);
  curPtr=curPtr->nextPtr;
  printList(curPtr);
 }
}