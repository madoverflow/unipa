#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
 char *str;
 struct node *nextPtr;
};
struct nodeQ{
 struct node *nodoPtr;
 struct nodeQ *nextPtr;
};
typedef struct node NodoLista;
typedef struct nodeQ NodoCoda;

static void insertList(char *str, NodoLista **topPtr, NodoLista **tailPtr);
static void printList(NodoLista *curPtr);
static void enqueue(NodoLista *newPtr);
static void printCoda();
static NodoLista *mergesort(NodoLista *topPtr);
static NodoLista *dequeue();
static NodoLista *merge(NodoLista *a, NodoLista *b);

static NodoCoda *topCoda=NULL,*tailCoda=NULL;

void main(){
 NodoLista *topPtr=NULL,*tailPtr=NULL;
 NodoLista *newPtr,*firstPtr;
 char str[81];
 size_t i=1,N;
 while(i){
  printf("Inserisci la stringa massimo 80 elementi\n");
  gets(str);
  insertList(str,&topPtr,&tailPtr);
  printf("Premi:\n1 per continuare\n0 per terminare\n");
  scanf("\n%ld",&i);
  getchar();
 }
 printf("Lista stringhe\n");
 printList(topPtr);
 firstPtr=mergesort(topPtr);
 printf("Lista stringhe ordinata\n");
 printList(firstPtr);
}

static void insertList(char *str, NodoLista **topPtr, NodoLista **tailPtr){
 NodoLista *newPtr=malloc(sizeof(NodoLista));
 size_t N=strlen(str);
 newPtr->str=malloc((N+1)*sizeof(char));
 newPtr->nextPtr=NULL;
 strcpy(newPtr->str,str);
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

static void printList(NodoLista *curPtr){
 if(curPtr==NULL)
  printf("Lista vuota\n");
 else{
  while(curPtr!=NULL){
   printf("%s -> ",curPtr->str);
   curPtr=curPtr->nextPtr;
  }
  printf("\n");
 }
}

static void enqueue(NodoLista *newPtr){
 NodoCoda *comodoPtr=malloc(sizeof(NodoCoda));
 comodoPtr->nodoPtr=newPtr;
 comodoPtr->nextPtr=NULL;
 if(topCoda==NULL){
  topCoda=comodoPtr;
  tailCoda=comodoPtr;
 }
 else{
  tailCoda->nextPtr=comodoPtr;
  tailCoda=comodoPtr;
 }
}

static void printCoda(){
 NodoCoda *curPtr=topCoda;
 if(curPtr==NULL)
  printf("Coda vuota\n");
 else
  while(curPtr!=NULL){ 
   puts(curPtr->nodoPtr->str);
   curPtr=curPtr->nextPtr;
  }
}

static NodoLista *mergesort(NodoLista *topPtr){
 NodoLista *curPtr=topPtr;
 NodoLista *newPtr=NULL;
 NodoLista *a,*b;
 size_t N;
 if(curPtr==NULL)
  printf("Lista vuota.\n");
 else{
  while(curPtr!=NULL){
   N=strlen(curPtr->str);
   newPtr=malloc(sizeof(NodoLista));
   newPtr->str=malloc((N+1)*sizeof(char));
   strcpy(newPtr->str,curPtr->str);
   newPtr->nextPtr=NULL;
   enqueue(newPtr);
   curPtr=curPtr->nextPtr;
  }
  newPtr=dequeue();
  while(topCoda!=NULL){
   enqueue(newPtr);
   newPtr=merge(dequeue(),dequeue());
  }
 }
 return newPtr;
}

static NodoLista *dequeue(){
 NodoLista *valPtr=NULL;
 NodoCoda *comodoPtr;
 if(topCoda==NULL)
  printf("Coda vuota\n");
 else{
  comodoPtr=topCoda;
  valPtr=topCoda->nodoPtr;
  topCoda=topCoda->nextPtr;
  comodoPtr->nextPtr=NULL;
  free(comodoPtr);
 }
 return valPtr; 
}

static NodoLista *merge(NodoLista *a, NodoLista *b){
 NodoLista *list1=a,*list2=b;
 NodoLista *topPtr=NULL,*tailPtr=NULL;
 while((list1!=NULL)&&(list2!=NULL)){
  if(strcmp(list1->str,list2->str)<0){
   insertList(list1->str,&topPtr,&tailPtr);
   list1=list1->nextPtr;
  }
  else{
   insertList(list2->str,&topPtr,&tailPtr);
   list2=list2->nextPtr;
  }
 }
 if(list1==NULL)
  while(list2!=NULL){
   insertList(list2->str,&topPtr,&tailPtr);
   list2=list2->nextPtr;
  }
 else
  while(list1!=NULL){
   insertList(list1->str,&topPtr,&tailPtr);
   list1=list1->nextPtr;
  }
 return topPtr;
}
