#include <stdio.h>
#include <stdlib.h>

typedef struct node{
 char val;
 struct node *nextPtr;
}Nodo;

static void insertOrderList(Nodo **topPtr, Nodo *newPtr);
static void printList(Nodo *curPtr);
static Nodo *concatenate(Nodo *list1, Nodo *list2);

void main(){
 Nodo *array_liste[2]={NULL,NULL};
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
 array_liste[0]=concatenate(array_liste[0],array_liste[1]);
 printf("Lista concatenata\n");
 printList(array_liste[0]);
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

static Nodo *concatenate(Nodo *list1, Nodo *list2){
 Nodo *comodoPtr=list1;
 while(comodoPtr->nextPtr!=NULL)
  comodoPtr=comodoPtr->nextPtr;
 comodoPtr->nextPtr=list2;
 return list1;
}