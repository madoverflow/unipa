//2 luglio 2020

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct listNode{
 char info;
 struct listNode *nextPtr;
}NodoL;

typedef struct treeNode{
 char info;
 struct treeNode *rightPtr;
 struct treeNode *leftPtr;
}NodoT;

void append(NodoL **topPtr, char el);
void printList(NodoL *curPtr);
void appendDup(NodoL **topPtr, NodoL **topPtr2, char el, char el2);
void treeInsert(NodoT **rootPtr, char el);
void insert(NodoT **radPtr, NodoT *newPtr);
void treeDisplay(NodoT *radPtr);
void treeVisit(NodoT *radPtr);
void visit(NodoT *radPtr, NodoL **list1, NodoL **list2);
void freeList(NodoL *curPtr);
void freeTail(NodoL **curPtr);

static int level=0;

void main(){
 NodoL *topPtr=NULL,*topPtr2=NULL;
 NodoT *rootPtr=NULL;
 char ch,ch2;
 int choose;
 srand(time(NULL));
 do{
  printf("Inserisci un carattere da inserire nella lista\n");
  scanf("%c",&ch);
  append(&topPtr,ch);
  
  printf("Inserisci\nQualunque numero per continuare\n0 per terminare\n");
  scanf("%d",&choose);
  getchar();
 }while(choose);
 printf("Stampa lista dopo funzione append\n");
 printList(topPtr);
 //prova utilizzo della funzione appendDup
 printf("Inserisci due caratteri\n");
 scanf("%c %c",&ch,&ch2);
 appendDup(&topPtr,&topPtr2,ch,ch2);
 printf("Stampa liste dopo funzione appendDup\n");
 printList(topPtr);
 printList(topPtr2);
 //fine prova
 for(size_t i=0; i<10; i++){
  ch=65+(rand()%26);
  ch2=97+(rand()%26);
  treeInsert(&rootPtr,ch);
  treeInsert(&rootPtr,ch2);
 }
 treeDisplay(rootPtr);
 treeVisit(rootPtr);
}

void append(NodoL **topPtr, char el){
 NodoL *newPtr=malloc(sizeof(NodoL));
 NodoL **curPtr;
 newPtr->info=el;
 newPtr->nextPtr=NULL;
 //lista vuota
 if(*topPtr==NULL)
  *topPtr=newPtr;
 //lista non vuota
 else{
  curPtr=topPtr;
  while(*curPtr!=NULL)
   curPtr=&((*curPtr)->nextPtr);
  *curPtr=newPtr;
 }
 curPtr=NULL;
 newPtr=NULL;
}

void printList(NodoL *curPtr){
 if(curPtr==NULL)
  printf("Lista vuota\n");
 else{
  while(curPtr!=NULL){
   printf("%c -> ",curPtr->info);
   curPtr=curPtr->nextPtr;
  }
  printf("\n");
 }
}

void appendDup(NodoL **topPtr, NodoL **topPtr2, char el, char el2){
 NodoL *curPtr;
 curPtr=*topPtr;
 while(curPtr!=NULL){
  append(topPtr2,curPtr->info);
  curPtr=curPtr->nextPtr;
 }
 append(topPtr,el);
 append(topPtr2,el2);
}

void treeInsert(NodoT **rootPtr, char el){
 NodoT *newPtr=malloc(sizeof(NodoT));
 newPtr->rightPtr=NULL;
 newPtr->leftPtr=NULL;
 newPtr->info=el;
 insert(rootPtr,newPtr);
}

void insert(NodoT **radPtr, NodoT *newPtr){
 //caso base
 if(*radPtr==NULL)
  *radPtr=newPtr;
 else{
  if(newPtr->info>(*radPtr)->info)
   insert(&((*radPtr)->rightPtr),newPtr);
  if(newPtr->info<(*radPtr)->info)
   insert(&((*radPtr)->leftPtr),newPtr);
 }
}

void treeDisplay(NodoT *radPtr){
 if(radPtr!=NULL){
  level++;
  treeDisplay(radPtr->rightPtr);
  printf(">%*s%5c\n",level*5,"", radPtr->info);
  treeDisplay(radPtr->leftPtr);
  level--;
 }
}

void treeVisit(NodoT *radPtr){
 if(radPtr==NULL)
  printf("Albero vuoto\n");
 else{
  NodoL *list1=NULL,*list2=NULL;
  append(&list1,radPtr->info);
  printList(list1);
  visit(radPtr->rightPtr,&list1,&list2);
  freeList(list1);
  freeList(list2);
  list1=NULL;
  list2=NULL;
  append(&list1,radPtr->info);
  visit(radPtr->leftPtr,&list1,&list2);
  printf("\n");
 }
}

void visit(NodoT *radPtr, NodoL **list1, NodoL **list2){
 if(radPtr!=NULL){
  appendDup(list1,list2,'0',radPtr->info);
  printList(*list2);
  freeList(*list1);
  *list1=*list2;
  *list2=NULL;
  visit(radPtr->rightPtr,list1,list2);
  visit(radPtr->leftPtr,list1,list2);
  freeTail(list1);
 }
}

void freeList(NodoL *curPtr){
 NodoL *comodoPtr;
 while(curPtr!=NULL){
  comodoPtr=curPtr->nextPtr;
  curPtr->nextPtr=NULL;
  free(curPtr);
  curPtr=comodoPtr;
 }
}

void freeTail(NodoL **curPtr){
 while((*curPtr)->nextPtr!=NULL)
  curPtr=&((*curPtr)->nextPtr);
 free(*curPtr);
 *curPtr=NULL;
}
