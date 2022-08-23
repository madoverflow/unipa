#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
 char val;
 struct node *nextPtr;
}Nodo;

static void printList(Nodo *curPtr);

void main(){
 Nodo *topPtr=NULL,*comodoPtr=NULL;
 char ch;
 printf("Inserisci una stringa\n");
 while((ch=getchar())!='\n'){
  if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')){
   comodoPtr=malloc(sizeof(Nodo));
   comodoPtr->val=ch;
   comodoPtr->nextPtr=topPtr;
   topPtr=comodoPtr;
  }
 }
 printList(topPtr);
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