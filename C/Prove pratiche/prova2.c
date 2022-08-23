//18 febbraio 2021
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 81

typedef struct node{
 char *s;
 struct node *nextPtr;
}Nodo;

static void creaListaDaTesto(Nodo **topPtr, char str[]);
static void insertList(Nodo **topPtr, char *token);
static void display(Nodo *curPtr);
static char *creaTestoDaLista(Nodo *curPtr);

void main(){
 char str[SIZE];
 char *T;
 Nodo *topPtr=NULL;
 printf("Inserisci il testo (massimo %d elementi)\n",SIZE-1);
 gets(str);
 creaListaDaTesto(&topPtr,str);
 display(topPtr);
 T=creaTestoDaLista(topPtr);
 if(T==NULL)
  printf("Errore: testo non creato\n");
 else
  printf("Testo creato da lista -> %s\n",T);
}

static void creaListaDaTesto(Nodo **topPtr, char str[]){
 char *token=strtok(str," ");
 while(token!=NULL){
  insertList(topPtr,token);
  token=strtok(NULL, " ");
 }
}

static void insertList(Nodo **topPtr, char *token){
 size_t N=(strlen(token))+1;
 Nodo *newPtr,*curPtr;
 if(token==NULL)
  printf("Inserimento non riuscito\n");
 else{
  newPtr=malloc(sizeof(Nodo));
  newPtr->nextPtr=NULL;
  newPtr->s=malloc(N*sizeof(char));
  strcpy(newPtr->s,token);
  if(*topPtr==NULL)
   *topPtr=newPtr;
  else{
   curPtr=*topPtr;
   while(curPtr->nextPtr!=NULL)
    curPtr=curPtr->nextPtr;
   curPtr->nextPtr=newPtr;
  }
  curPtr=NULL;
  newPtr=NULL;
 }
}

static void display(Nodo *curPtr){
 if(curPtr==NULL)
  printf("Lista vuota\n");
 else{
  while(curPtr!=NULL){
   printf("%s -> ",curPtr->s);
   curPtr=curPtr->nextPtr;
  }
  printf("\n");
 }
}

static char *creaTestoDaLista(Nodo *curPtr){
 size_t N;
 char *t=NULL;
 if(curPtr==NULL)
  printf("Lista vuota\n");
 else{
  N=strlen(curPtr->s)+1;
  t=malloc(N*sizeof(char));
  strcpy(t,curPtr->s);
  curPtr=curPtr->nextPtr;
  while(curPtr!=NULL){
   N+=strlen(curPtr->s)+1;
   t=realloc(t,N*sizeof(char));
   t=strcat(t," ");
   t=strcat(t,curPtr->s);
   curPtr=curPtr->nextPtr;
  }
 }
 return t;
}
