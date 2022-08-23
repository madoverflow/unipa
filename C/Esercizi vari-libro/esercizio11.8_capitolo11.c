#include <stdio.h>
#include <stdlib.h>

typedef struct nodeConto{
 int count;
 char person[40];
 float cash;
}nodoC;

typedef struct listaConto{
 nodoC *clientPtr;
 struct listaConto *nextPtr;
}listC;

typedef struct nodeTrans{
 int count;
 float money;
}nodoT;

typedef struct listaTransazione{
 nodoT *transPtr;
 struct listaTransazione *nextPtr;
}listT;


static void insertOrderListC(listC **topPtr, nodoC *comodoPtr);
static void insertOrderListT(listT **topTPtr, nodoT *comodoTPtr);
static FILE *insertListCFile(FILE *fd, char filename[], listC *comodoPtr);
static FILE *insertListTFile(FILE *fd, listT *comodoPtr);
static float search(int conto, listT **topPtr);
static void displayT(listT *curPtr);

void main(){
 size_t N,val;
 listC *topPtr=NULL,*comTopPtr;
 nodoC *comodoPtr;
 nodoT *comodoTPtr;
 listT *topTPtr=NULL;
 FILE *oldmast,*trans,*newmast;
 float x;
 printf("Inserisci il numero di clienti da gestire\n");
 scanf("%ld",&N);
 for(int i=0; i<N; i++){
  comodoPtr=malloc(sizeof(nodoC));
  printf("Inserisci il numero del conto del cliente\n");
  scanf("%d",&(comodoPtr->count));
  printf("Insersci nome e cognome del cliente (massimo 39 caratteri incluso lo spazio)\n");
  getchar();
  gets(comodoPtr->person);
  printf("Inserisci il saldo del cliente\n");
  scanf("%f",&(comodoPtr->cash));
  insertOrderListC(&topPtr, comodoPtr);
 }
 printf("Inserisci il numero delle transazioni da gestire\n");
 scanf("%ld",&N);
 for(int i=0; i<N; i++){
  comodoTPtr=malloc(sizeof(nodoT));
  printf("Inserisci il numero del conto del cliente\n");
  scanf("\n%d",&(comodoTPtr->count));
  printf("Inserisci l'ammontare della transazione del client\n");
  scanf("\n%f",&(comodoTPtr->money));
  insertOrderListT(&topTPtr, comodoTPtr);
 }
 oldmast=insertListCFile(oldmast,"oldmast.dat",topPtr);
 trans=insertListTFile(trans,topTPtr);
 comTopPtr=topPtr;
 while(comTopPtr!=NULL){
  x=search((comTopPtr->clientPtr)->count,&topTPtr);
  comTopPtr->clientPtr->cash+=x;
  comTopPtr=comTopPtr->nextPtr;
 }
 newmast=insertListCFile(newmast,"newmast.dat",topPtr);
 displayT(topTPtr);
 fseek(newmast,0,SEEK_END);
 val=ftell(newmast)/sizeof(nodoC);
 fseek(newmast,0,SEEK_SET);
 for(int i=0; i<val; i++){
  fread(comodoPtr,sizeof(nodoC),1,newmast);
  printf("%3.4f\n",comodoPtr->cash);
 }
}

static void insertOrderListC(listC **topPtr, nodoC *comodoPtr){
 listC **curPtr, *valPtr, *newPtr;
 if(*topPtr==NULL){
  *topPtr=malloc(sizeof(listC));
  (*topPtr)->nextPtr=NULL;
  (*topPtr)->clientPtr=comodoPtr;
 }
 else{
  newPtr=malloc(sizeof(listC));
  newPtr->clientPtr=comodoPtr;
  curPtr=topPtr;
  while((((*curPtr)->clientPtr)->count<comodoPtr->count)&&((*curPtr)->nextPtr!=NULL))
   curPtr=&(*curPtr)->nextPtr;
  if(((*curPtr)->clientPtr)->count>comodoPtr->count){
   valPtr=*curPtr;
   *curPtr=newPtr;
   newPtr->nextPtr=valPtr;
  }
  else{
   newPtr->nextPtr=NULL;
   (*curPtr)->nextPtr=newPtr;
  }
 }
 curPtr=topPtr;
 while((*curPtr)!=NULL){
  printf("%d\n",((*curPtr)->clientPtr)->count);
  curPtr=&(*curPtr)->nextPtr;
 }
}

static void insertOrderListT(listT **topTPtr, nodoT *comodoTPtr){
 listT **curPtr, *valPtr, *newPtr;
 if(*topTPtr==NULL){
  *topTPtr=malloc(sizeof(listT));
  (*topTPtr)->nextPtr=NULL;
  (*topTPtr)->transPtr=comodoTPtr;
 }
 else{
  newPtr=malloc(sizeof(listT));
  newPtr->transPtr=comodoTPtr;
  curPtr=topTPtr;
  while((((*curPtr)->transPtr)->count<comodoTPtr->count)&&((*curPtr)->nextPtr!=NULL))
   curPtr=&(*curPtr)->nextPtr;
  if(((*curPtr)->transPtr)->count==comodoTPtr->count)
   (*curPtr)->transPtr->money+=comodoTPtr->money;
  else{
   if(((*curPtr)->transPtr)->count>comodoTPtr->count){
    valPtr=*curPtr;
    *curPtr=newPtr;
    newPtr->nextPtr=valPtr;
   }
   else{
    newPtr->nextPtr=NULL;
    (*curPtr)->nextPtr=newPtr;
   }
  }
 }
 curPtr=topTPtr;
 while((*curPtr)!=NULL){
  printf("%d\n",((*curPtr)->transPtr)->count);
  curPtr=&(*curPtr)->nextPtr;
 }
}

static FILE *insertListCFile(FILE *fd, char filename[], listC *comodoPtr){
 fd=fopen(filename,"wb+");
 while(comodoPtr!=NULL){
  fwrite(comodoPtr->clientPtr,sizeof(nodoC),1,fd);
  comodoPtr=comodoPtr->nextPtr;
 }
 fseek(fd,0,SEEK_SET);
 return fd;
}

static FILE *insertListTFile(FILE *fd, listT *comodoPtr){
 fd=fopen("trans.dat","wb+");
 while(comodoPtr!=NULL){
  fwrite(comodoPtr->transPtr,sizeof(nodoT),1,fd);
  comodoPtr=comodoPtr->nextPtr;
 }
 fseek(fd,0,SEEK_SET);
 return fd;
}

static float search(int conto, listT **topPtr){
 listT *comTPtr,*prevTPtr,*curTPtr;
 float y=0;
 if(*topPtr==NULL)
  return 0;
 if(((*topPtr)->transPtr)->count==conto){
  comTPtr=*topPtr;
  y=((*topPtr)->transPtr)->money;
  *topPtr=(*topPtr)->nextPtr;
  comTPtr->nextPtr=NULL;
  free(comTPtr->transPtr);
  free(comTPtr);
  comTPtr=NULL;
 }
 else{
  prevTPtr=*topPtr;
  curTPtr=(*topPtr)->nextPtr;
  while((curTPtr!=NULL)&&(curTPtr->transPtr->count!=conto)){
   prevTPtr=curTPtr;
   curTPtr=curTPtr->nextPtr;
  }
  if(curTPtr!=NULL){
   y=curTPtr->transPtr->money;
   prevTPtr->nextPtr=curTPtr->nextPtr;
   curTPtr->nextPtr=NULL;
   free(curTPtr->transPtr);
   free(curTPtr);
  }
 }
 return y;
}

static void displayT(listT *curPtr){
 while(curPtr!=NULL){
  printf("Unmatched transiction record for account number %d",curPtr->transPtr->count);
  curPtr=curPtr->nextPtr;
 }
}