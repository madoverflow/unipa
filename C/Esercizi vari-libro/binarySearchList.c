#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//definizione item
#ifdef intero
 typedef int Item;
 #define lessthan(a,b) ((a)<(b))
 #define equal(a,b) ((a)==(b))
 #define assign(a,b) a=b
#else
 typedef char * Item;
 #define lessthan(a,b) (strcmp(a,b)<0)
 #define equal(a,b) (strcmp(a,b)==0)
 #define assign(a,b) strcpy(a,b)
#endif



struct node{
 Item val;
 struct node *nextPtr;
};

struct nodeQ{
 struct node *nodePtr;
 struct nodeQ *nextPtr;
};

typedef struct node Nodo;
typedef struct nodeQ NodoQ;

static void insertList(Nodo **topPtr, Nodo **tailPtr, Item x);
static void printList(Nodo *curPtr);
static void enqueue(Nodo *comodoPtr);
static Nodo *dequeue();
static void insertListQueue(Nodo *topPtr);
static void printQueue();
static Nodo *mergesort(Nodo *topPtr);
static Nodo *merge(Nodo *list1, Nodo *list2);
static void binarySearchList(Nodo *topPtr, Item x);
static void clean(Nodo *curPtr);

static NodoQ *topQ=NULL,*tailQ=NULL;

void main(){
 Nodo *topPtr=NULL,*tailPtr=NULL;
 Nodo *orderPtr;
 int choose;
 char str[81];
 #ifdef intero
  for(size_t i=0; i<20; i++)
   insertList(&topPtr,&tailPtr,rand()%100);
 #else
  do{
   printf("Inserisci una stringa di massimo 80 elementi\n");
   gets(str);
   insertList(&topPtr,&tailPtr,str);
   printf("Inserisci:\n1 per continuare\n0 per terminare\n");
   scanf("%d",&choose);
   getchar();
  }while(choose>=1);
 #endif
 printf("Stampa lista\n");
 printList(topPtr);
 orderPtr=mergesort(topPtr);
 printf("Lista ordinata\n");
 printList(orderPtr);
 #ifdef intero
  printf("Inserisci il numero da ricercare nella lista\n");
  scanf("%d",&choose);
  binarySearchList(orderPtr,choose);
 #else
  printf("Inserisci la stringa da ricercare nella lista\n");
  gets(str);
  binarySearchList(orderPtr,str);
 #endif
}

static void insertList(Nodo **topPtr, Nodo **tailPtr, Item x){
 Nodo *comodoPtr=malloc(sizeof(Nodo));
 #ifndef intero
 size_t N=strlen(x)+1;
 comodoPtr->val=malloc(N*sizeof(char));
 #endif
 assign(comodoPtr->val,x);
 comodoPtr->nextPtr=NULL;
 //lista vuota
 if(*topPtr==NULL){
  *topPtr=comodoPtr;
  *tailPtr=comodoPtr;
 }//lista non vuota
 else{
  (*tailPtr)->nextPtr=comodoPtr;
  *tailPtr=comodoPtr;
 }
 comodoPtr=NULL;
}

static void printList(Nodo *curPtr){
 if(curPtr==NULL)
  printf("Lista vuota\n");
 else{
  while(curPtr!=NULL){
   #ifdef intero
    printf("%d -> ",curPtr->val);
   #else
    printf("%s -> ",curPtr->val);
   #endif
   curPtr=curPtr->nextPtr;
  }
  printf("\n");
 }
}

static void enqueue(Nodo *comodoPtr){
 NodoQ *newQ=malloc(sizeof(NodoQ));
 newQ->nodePtr=comodoPtr;
 newQ->nextPtr=NULL;
 //coda vuota
 if(topQ==NULL){
  topQ=newQ;
  tailQ=newQ;
 }//coda non vuota
 else{
  tailQ->nextPtr=newQ;
  tailQ=newQ;
 }
 newQ=NULL;
}

static Nodo *dequeue(){
 Nodo *retPtr=NULL;
 NodoQ *comodoPtr;
 //coda vuota
 if(topQ==NULL)
  printf("Coda vuota\n");
 //coda non vuota
 else{
  comodoPtr=topQ;
  retPtr=comodoPtr->nodePtr;
  topQ=(topQ)->nextPtr;
  comodoPtr->nextPtr=NULL;
  free(comodoPtr);
  comodoPtr=NULL;
 }
 return retPtr;
}

static void insertListQueue(Nodo *topPtr){
 Nodo *newPtr,*curPtr=topPtr;
 if(topPtr==NULL)
  printf("Lista vuota\n");
 else{
  while(curPtr!=NULL){
   newPtr=malloc(sizeof(Nodo));
   #ifndef intero
   size_t N=strlen(curPtr->val)+1;
   newPtr->val=malloc(N*sizeof(char));
   #endif
   assign(newPtr->val,curPtr->val);
   puts(newPtr->val);
   newPtr->nextPtr=NULL;
   enqueue(newPtr);
   curPtr=curPtr->nextPtr;
  }
  newPtr=NULL;
 }
}

static void printQueue(){
 NodoQ *curPtr=topQ;
 if(topQ==NULL)
  printf("Coda vuota\n");
 else{
  while(curPtr!=NULL){
   #ifdef intero
    printf("%d -> ",curPtr->nodePtr->val);
   #else
    printf("%s -> ",curPtr->nodePtr->val);
   #endif
   curPtr=curPtr->nextPtr;
  }
  printf("\n");
 }
}

static Nodo *mergesort(Nodo *topPtr){
 Nodo *comodoPtr=NULL;
 if(topPtr==NULL)
  printf("Lista vuota\n");
 else{
  insertListQueue(topPtr);
  comodoPtr=dequeue();
  while(topQ!=NULL){
   enqueue(comodoPtr);
   comodoPtr=merge(dequeue(),dequeue());
  }
 }
 return comodoPtr;
}

static Nodo *merge(Nodo *list1, Nodo *list2){
 Nodo *f1=list1,*f2=list2;
 Nodo *topNL=NULL,*tailNL=NULL;
 while((list1!=NULL)&&(list2!=NULL)){
  if(lessthan(list1->val,list2->val)){
   insertList(&topNL,&tailNL,list1->val);
   list1=list1->nextPtr;
  }
  else{
   insertList(&topNL,&tailNL,list2->val);
   list2=list2->nextPtr;
  }
 }
 if(list1==NULL)
  while(list2!=NULL){
   insertList(&topNL,&tailNL,list2->val);
   list2=list2->nextPtr;
  }
 if(list2==NULL)
  while(list1!=NULL){
   insertList(&topNL,&tailNL,list1->val);
   list1=list1->nextPtr;
  }
 clean(f1);
 clean(f2);
 return topNL;
}

static void binarySearchList(Nodo *topPtr, Item x){
 Nodo *aPtr,*bPtr;
 //caso base
 if(topPtr==NULL||((!equal(topPtr->val,x))&&(topPtr->nextPtr==NULL))){
  clean(topPtr);
  printf("Valore non trovato\n");
  return;
 }
 //chiamata ricorsiva
 aPtr=topPtr;
 bPtr=topPtr->nextPtr;
 while(bPtr!=NULL&&bPtr->nextPtr!=NULL){
  bPtr=bPtr->nextPtr;
  aPtr=aPtr->nextPtr;
 }
 if(equal(aPtr->val,x)){
  printf("Valore trovato\n");
  clean(topPtr);
  return;
 }
 else{
  if(!lessthan(x,aPtr->val)){
   bPtr=aPtr->nextPtr;
   aPtr->nextPtr=NULL;
   clean(topPtr);
   binarySearchList(bPtr,x);
  }
  else{
   clean(aPtr->nextPtr);
   aPtr->nextPtr=NULL;
   binarySearchList(topPtr,x);
  }
 }
}

static void clean(Nodo *curPtr){
 Nodo *comodoPtr;
 if(curPtr==NULL)
  printf("Lista vuota\n");
 else
  while(curPtr!=NULL){
   comodoPtr=curPtr;
   curPtr=curPtr->nextPtr;
   comodoPtr->nextPtr=NULL;
   #ifndef intero
    free(comodoPtr->val);
   #endif    
   free(comodoPtr);
  }
}
