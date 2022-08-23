#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct node{
 int val;
 struct node *nextPtr;
}Nodo;

static void enqueue(Nodo **topPtr, Nodo **tailPtr, Nodo *newPtr);
static int dequeue(Nodo **curPtr, Nodo **tailPtr);
static void printQueue(Nodo *curPtr);

void main(){
 Nodo *topPtr=NULL,*tailPtr=NULL,*newPtr;
 time_t startTime,finishTime,curTime,serviceTime;
 size_t i=0,valClient,valService,client;
 char *strTime;
 srand(time(NULL));
 time(&startTime);
 finishTime=startTime+(720*60);
 curTime=startTime;
 serviceTime=startTime;
 valClient=((rand()%4)+1)*60;
 valService=((rand()%4)+1)*60;
 curTime+=valClient;
 serviceTime+=valService;
 do{
  i++;
  valClient=((rand()%4)+1)*60;
  curTime+=valClient;
  newPtr=malloc(sizeof(Nodo));
  newPtr->val=i;
  newPtr->nextPtr=NULL;
  enqueue(&topPtr,&tailPtr,newPtr);
  if(difftime(curTime,serviceTime)>=0){
   strTime=ctime(&serviceTime);
   printf("Cliente numero %d servito alla data %s\n",dequeue(&topPtr,&tailPtr),strTime);
   valService=((rand()%4)+1)*60;
   serviceTime+=valService;
  }
 }while(difftime(finishTime,curTime)>0);
 printQueue(topPtr);
}

static void enqueue(Nodo **topPtr, Nodo **tailPtr, Nodo *newPtr){
 //coda vuota
 if(*topPtr==NULL){
  *tailPtr=newPtr;
  *topPtr=newPtr;
 }//coda non vuota
 else{
  (*tailPtr)->nextPtr=newPtr;
  *tailPtr=newPtr;
 }
 newPtr=NULL;
}

static int dequeue(Nodo **topPtr, Nodo **tailPtr){
 int valore;
 Nodo *comodoPtr;
 //coda vuota
 if(*topPtr==NULL){
  printf("Coda vuota\n");
  valore=0;
 }//coda non vuota
 else{
  comodoPtr=(*topPtr)->nextPtr;
  (*topPtr)->nextPtr=NULL;
  valore=(*topPtr)->val;
  free(*topPtr);
  *topPtr=comodoPtr;
  comodoPtr=NULL;
 }
 return valore;
}

static void printQueue(Nodo *curPtr){
 printf("Stampa della coda\n");
 if(curPtr==NULL)
  printf("Coda vuota\n");
 else{
  while(curPtr!=NULL){
   printf("%d -> ",curPtr->val);
   curPtr=curPtr->nextPtr;
  }
  printf("\n");
 }
}