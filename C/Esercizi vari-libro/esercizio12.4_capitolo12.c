#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct gradeNode{
 char lastName[20];
 double grade;
 struct gradeNode *nextPtr;
};
typedef struct gradeNode GradeNode;
typedef GradeNode * GradeNodePtr;

static void insertOrderList(GradeNodePtr *topPtr, GradeNodePtr newPtr);
static void printList(const GradeNodePtr curPtr);
static void deleteList(GradeNodePtr *topPtr);

void main(){
 int choose;
 GradeNodePtr topPtr=NULL,newPtr=NULL;
 do{
  printf("Inserisci:\n1 inserimento nodo\n2 stampa lista\n3 cancellazione lista\n0 per terminare\n");
  scanf("%d",&choose);
  switch(choose){
   case 1:
    newPtr=malloc(sizeof(GradeNode));
    printf("Inserisci il cognome\n");
	getchar();
    gets(newPtr->lastName);
	printf("Inserisci il grado\n");
	scanf("%lf",&(newPtr->grade));
    insertOrderList(&topPtr,newPtr);
    break;
   case 2:
    printList(topPtr);
    break;
   case 3:
    deleteList(&topPtr);
    break;
   case 0:
    printf("Menu terminato\n");
	break;
   default:
    printf("Numero non corretto. Riprovare\n");
	break;
  }
 }while(choose);
}

static void insertOrderList(GradeNodePtr *topPtr, GradeNodePtr newPtr){
 GradeNodePtr *comodoPtr=NULL;
 //lista vuota
 if(*topPtr==NULL){
  newPtr->nextPtr=NULL;
  *topPtr=newPtr;
 }//lista non vuota
 else{
  comodoPtr=topPtr;
  while((strcmp(newPtr->lastName,(*comodoPtr)->lastName)>0)&&((*comodoPtr)->nextPtr!=NULL))
   comodoPtr=&((*comodoPtr)->nextPtr);
  if(strcmp(newPtr->lastName,(*comodoPtr)->lastName)!=0){
   if(strcmp(newPtr->lastName,(*comodoPtr)->lastName)<0){
    newPtr->nextPtr=*comodoPtr;
    *comodoPtr=newPtr;
    newPtr=NULL;
   }
   else{
   newPtr->nextPtr=NULL;
   (*comodoPtr)->nextPtr=newPtr;
   newPtr=NULL;
   }
  }
 }
}

static void printList(const GradeNodePtr curPtr){
 //caso base
 if(curPtr!=NULL){
  printf("%s %3.4lf\n",curPtr->lastName,curPtr->grade);
  printList(curPtr->nextPtr);
 }
}

static void deleteList(GradeNodePtr *topPtr){
 if(*topPtr!=NULL){
  GradeNodePtr comodoPtr=(*topPtr)->nextPtr;
  (*topPtr)->nextPtr=NULL;
  free(*topPtr);
  *topPtr=comodoPtr;
  comodoPtr=NULL;
  deleteList(topPtr);
 }
}