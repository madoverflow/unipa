#include <stdio.h>
#include <stdlib.h>

typedef struct node{
 char val;
 struct node *nextPtr;
}Nodo;

static void insertOrderList(Nodo **topPtr, Nodo *newPtr);
static void printList(Nodo *curPtr);
static Nodo *merge(Nodo *list1, Nodo *list2);

void main(){
 Nodo *array_liste[3]={NULL,NULL,NULL};
 Nodo *newPtr=NULL;
 int choose1,choose2;
 printf("Inserisci:\n1 per gestire la prima lista\n2 per la seconda\nQualunque numero per terminare\n");
 scanf("%d",&choose1);
 while((choose1==1)||(choose1==2)){
  do{
   printf("Inserisci:\n1 inserimento nodo\n2 stampa lista\n0 per terminare\n");
   scanf("%d",&choose2);
   switch(choose2){
    case 1:
	 newPtr=malloc(sizeof(Nodo));
	 printf("Inserisci il carattere del nodo\n");
	 scanf("\n%c",&(newPtr->val));
	 insertOrderList(&array_liste[choose1-1],newPtr);
	 break;
    case 2:
	 printList(array_liste[choose1-1]);
	 break;
	case 0:
	 printf("Menu terminato\n");
	 break;
	default:
	 printf("Valore non corretto. Riprovare\n");
	 break;
   }
  }while(choose2);
  printf("Inserisci:\n1 per gestire la prima lista\n2 per la seconda\nQualunque numero per terminare\n");
  scanf("%d",&choose1);
 }
 array_liste[2]=merge(array_liste[0],array_liste[1]);
 printf("Risultato Merge\n");
 printList(array_liste[2]);
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

static Nodo *merge(Nodo *list1, Nodo *list2){
 Nodo *list=NULL,*comodoPtr=NULL;
 Nodo **curPtr=&list;
 while((list1!=NULL)&&(list2!=NULL)){
  comodoPtr=malloc(sizeof(Nodo));
  comodoPtr->nextPtr=NULL;
  if(list1->val<list2->val){
   comodoPtr->val=list1->val;
   list1=list1->nextPtr;
  }
  else{
   comodoPtr->val=list2->val;
   list2=list2->nextPtr;
  }
  *curPtr=comodoPtr;
  curPtr=&((*curPtr)->nextPtr);
 }
 if(list1!=NULL){
  while(list1!=NULL){
   comodoPtr=malloc(sizeof(Nodo));
   comodoPtr->nextPtr=NULL;
   comodoPtr->val=list1->val;
   *curPtr=comodoPtr;
   curPtr=&((*curPtr)->nextPtr);
   list1=list1->nextPtr;
  }
 }
 else{
  while(list2!=NULL){
   comodoPtr=malloc(sizeof(Nodo));
   comodoPtr->nextPtr=NULL;
   comodoPtr->val=list2->val;
   *curPtr=comodoPtr;
   curPtr=&((*curPtr)->nextPtr);
   list2=list2->nextPtr;
  }
 }
 return list;
}