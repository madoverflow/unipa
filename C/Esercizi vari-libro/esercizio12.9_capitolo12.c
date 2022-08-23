#include <stdio.h>
#include <stdlib.h>

typedef struct node{
 char val;
 struct node *nextPtr;
}Nodo;

static void insertOrderList(Nodo **topPtr, Nodo *newPtr);
static void printList(Nodo *curPtr);
static Nodo *reverseList(Nodo *list);

void main(){
 Nodo *list1=NULL,*list2=NULL,*newPtr=NULL;
 char x;
 for(int i=0; i<10; i++){
  printf("Inserisci il carattere del nodo\n");
  scanf("\n%c",&x);
  newPtr=malloc(sizeof(Nodo));
  newPtr->val=x;
  insertOrderList(&list1,newPtr);
 }
 printList(list1);
 list2=reverseList(list1);
 printList(list2);
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
  printf("%c -> ",curPtr->val);
  curPtr=curPtr->nextPtr;
  printList(curPtr);
 }
}

static Nodo *reverseList(Nodo *list){
 Nodo *topPtr=NULL,*comodoPtr=NULL;
 while(list!=NULL){
  comodoPtr=malloc(sizeof(Nodo));
  comodoPtr->val=list->val;
  comodoPtr->nextPtr=topPtr;
  topPtr=comodoPtr;
  list=list->nextPtr;
 }
 return topPtr;
}