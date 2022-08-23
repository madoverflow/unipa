#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "interfaceBSTADT.h"
#include "interfaceQueueADT.h"

#ifdef stringhe
 #define equal(a,b) (strcmp((a),(b))==0)
 #define isShorter(a,b) (strcmp((a),(b))<0)
#else
 #define equal(a,b) ((a)==(b))
 #define isShorter(a,b) ((a)<(b))
#endif

struct node{
 ItemTree val;
 struct node *rightPtr;
 struct node *leftPtr;
};

typedef struct node Nodo;

static void insertNode(Nodo **radPtr, Nodo *curPtr);
static void treeDisplay(Nodo *radPtr);
static bool research(Nodo *radPtr, ItemTree a, size_t *count);
static Nodo *yourChildren(Nodo *radicePtr, ItemTree a, ItemTree b);
static void preindex(const Nodo * const ItemTree);
static void postindex(const Nodo * const ItemTree);
static void inorder(const Nodo * const ItemTree);
static ItemTree minimo(Nodo *radPtr);
static void delMin(Nodo **radPtr);
static Nodo **researchItem(Nodo **radPtr, ItemTree a);
static void deleteItem(Nodo **radPtr);

static Nodo *rootPtr;
static int level=0;
void treeInit(){
 srand(time(NULL));
 rootPtr=NULL;
}

bool treeIsEmpty(){
 return rootPtr==NULL;
}

void treeInsertNode(ItemTree a){
 Nodo *comPtr=malloc(sizeof(Nodo));
 if(comPtr==NULL){
  printf("Spazio nell'heap insufficiente. Nodo non inserito.\n");
  printTree();
 }
 else{
  comPtr->val=a;
  comPtr->rightPtr=NULL;
  comPtr->leftPtr=NULL;
  insertNode(&rootPtr,comPtr);
  comPtr=NULL;
 }
}

static void insertNode(Nodo **radPtr, Nodo *curPtr){
 //caso base
 if(*radPtr==NULL)
  *radPtr=curPtr;
 else //chiamata ricorsiva
  if(!equal(curPtr->val,(*radPtr)->val)){
   if(isShorter(curPtr->val,(*radPtr)->val))
    insertNode(&((*radPtr)->leftPtr),curPtr);
   else
    insertNode(&((*radPtr)->rightPtr),curPtr);
  }
}

ItemTree getItem(){
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

void printTree(){
  if(treeIsEmpty())
   printf("BST vuoto\n");
  else
   treeDisplay(rootPtr);
}

static void treeDisplay(Nodo *radPtr){
 if(radPtr!=NULL){
  level++;
  treeDisplay(radPtr->rightPtr);
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
  treeDisplay(radPtr->leftPtr);
  level--;
 }
}

bool search(ItemTree a, size_t *count){
 if(treeIsEmpty()){
  printf("BST vuoto\n");
  return 0;
 }
 else
  return research(rootPtr,a,count);
}

static bool research(Nodo *radPtr, ItemTree a, size_t *count){
 //casi base
 if(radPtr==NULL)
  return 0;
 if(equal(radPtr->val,a))
  return 1;
 if(isShorter(a,radPtr->val)){
  *count+=1;
  research(radPtr->leftPtr,a,count);
 }
 else{
  *count+=1;
  research(radPtr->rightPtr,a,count);
 }
}

ItemTree generateItem(){
 #ifdef intero
  int x=rand()%100;
 #else
  #ifdef virgola
   float x=rand()%98.4;
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

size_t distance(ItemTree a, ItemTree b){
 size_t N=0,M=0;
 Nodo *radPtr;
 if(treeIsEmpty())
  return 0;
 if(equal(a,b)||!(search(a,&N)&&search(b,&M)))
  return 0;
 N=0;
 M=0;
 radPtr=yourChildren(rootPtr,a,b);
 research(radPtr,a,&N);
 research(radPtr,b,&M);
 return N+M;
}

static Nodo *yourChildren(Nodo *radicePtr, ItemTree a, ItemTree b){
 if((isShorter(a,radicePtr->val)&&isShorter(b,radicePtr->val))||((!isShorter(a,radicePtr->val))&&(!isShorter(b,radicePtr->val)))){
  if(isShorter(a,radicePtr->val)&&isShorter(b,radicePtr->val))
   yourChildren(radicePtr->leftPtr,a,b);
  else
   yourChildren(radicePtr->rightPtr,a,b);
 }
 else
  return radicePtr;
}

void treePreOrder(){
 if(rootPtr==NULL)
  printf("Il BST è vuoto.\n");
 else{
  preindex(rootPtr);
  printf("\n");
 }
}

void treePostOrder(){
 if(rootPtr==NULL)
  printf("Il BST è vuoto.\n");
 else{
  postindex(rootPtr);
  printf("\n");
 }
}

void treeInOrder(){
 if(rootPtr==NULL)
  printf("Il BST è vuoto.\n");
 else{
  inorder(rootPtr);
  printf("\n");
 }
}

static void preindex(const Nodo * const item){
 if(item!=NULL){
  #ifdef intero
   printf("%5d",item->val);
  #else
   #ifdef virgola
    printf("%5f",item->val);
    #else
    #ifdef stringhe
     printf("%5s",item->val);
    #else
     printf("%5c",item->val);
    #endif
   #endif
  #endif
  preindex(item->leftPtr);
  preindex(item->rightPtr);
 }
}

static void postindex(const Nodo * const item){
 if(item!=NULL){
  postindex(item->leftPtr);
  postindex(item->rightPtr);
  #ifdef intero
   printf("%5d",item->val);
  #else
   #ifdef virgola
    printf("%5f",item->val);
    #else
    #ifdef stringhe
     printf("%5s",item->val);
    #else
     printf("%5c",item->val);
    #endif
   #endif
  #endif
 }
}

static void inorder(const Nodo * const item){
 if(item!=NULL){
  inorder(item->leftPtr);
  #ifdef intero
   printf("%5d",item->val);
  #else
   #ifdef virgola
    printf("%5f",item->val);
    #else
    #ifdef stringhe
     printf("%5s",item->val);
    #else
     printf("%5c",item->val);
    #endif
   #endif
  #endif
  inorder(item->rightPtr);
 }
}

ItemTree *minimum(){
 ItemTree *comodo=malloc(sizeof(ItemTree));
 if(treeIsEmpty()){
  printf("BST vuoto\n");
  free(comodo);
  comodo=NULL;
 }
 else
  *comodo=minimo(rootPtr);
 return comodo;
}

static ItemTree minimo(Nodo *radPtr){
 //caso base
 if(radPtr->leftPtr==NULL)
  return radPtr->val;
 else
  //chiamata ricorsiva
  minimo(radPtr->leftPtr);
}

void putItem(ItemTree a){
 #ifdef intero
  printf("Valore -> %d\n",a);
 #else
  #ifdef virgola
   printf("Valore -> %f\n",a);
  #else
   printf("Valore -> %c\n",a);
  #endif
 #endif
}

void deleteMin(){
 if(treeIsEmpty())
  printf("Impossibile trovare il minimo.\n");
 else{
 //caso radice minimo
  if(rootPtr->leftPtr==NULL)
   rootPtr=rootPtr->rightPtr;
  else
   delMin(&rootPtr);
 }
}

static void delMin(Nodo **radPtr){
 //caso base
 if((*radPtr)->leftPtr==NULL){
  Nodo *comodo;
  comodo=*radPtr;
  *radPtr=(*radPtr)->rightPtr;
  comodo->rightPtr=NULL;
  free(comodo);
  comodo=NULL;
 }
 //chiamata ricorsiva
 else
  delMin(&((*radPtr)->leftPtr));
}

void treeDelete(ItemTree a){
 Nodo **radPtr,*comodo;
 radPtr=researchItem(&rootPtr,a);
 if(radPtr==NULL)
  printf("Il valore inserito non appartiene al BST. Cancellazione fallita.\n");
 else{
  if((*radPtr)->leftPtr==NULL){
   comodo=*radPtr;
   *radPtr=(*radPtr)->rightPtr;
   comodo->rightPtr=NULL;
   free(comodo);
   comodo=NULL;
   return;
  }
  if((*radPtr)->rightPtr==NULL){
   comodo=*radPtr;
   *radPtr=(*radPtr)->leftPtr;
   comodo->leftPtr=NULL;
   free(comodo);
   comodo=NULL;
   return;
  }
  deleteItem(radPtr);
 }
}

static Nodo **researchItem(Nodo **radPtr, ItemTree a){
 //casi base
 if(*radPtr==NULL)
  return NULL;
 if(equal((*radPtr)->val,a))
  return radPtr;
 if(isShorter(a,(*radPtr)->val))
  researchItem(&((*radPtr)->leftPtr),a);
 else
  researchItem(&((*radPtr)->rightPtr),a);
}

static void deleteItem(Nodo **radPtr){
 ItemTree min;
 min=minimo((*radPtr)->rightPtr);
 delMin(&((*radPtr)->rightPtr));
 (*radPtr)->val=min;
}

void treeLevelOrder(){
 Nodo **comodo;
 queueInit();
 enqueue(rootPtr);
 while(!queueIsEmpty()){
  comodo=dequeue();
  #ifdef intero
   printf("%3d",(*comodo)->val);
  #else
   #ifdef virgola
    printf("%3f",(*comodo)->val);
   #else
    printf("%3c",(*comodo)->val);
   #endif
  #endif
  if((*comodo)->leftPtr!=NULL)
   enqueue((*comodo)->leftPtr);
  if((*comodo)->rightPtr!=NULL)
   enqueue((*comodo)->rightPtr);
 }
 printf("\n");
}