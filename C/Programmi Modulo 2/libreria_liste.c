//libreria funzioni liste
#include <stdio.h>
#include <stdlib.h>
#include "libreria_liste.h"

void insert(stru **p,const char l){
 stru *nn=malloc(sizeof(stru));
 (*p)->np=nn;
 *p=nn;
 nn->np=NULL;
 nn->c=l;
}
void delete(stru **src,const char data){
 stru *prec=*src,*nextp=(*src)->np,*cur=*src;
 if(cur->c==data){
  *src=nextp;
  free(prec);
  return;
 }
 while((cur->c!=data)&&(nextp!=NULL)){
  prec=cur;
  cur=nextp;
  nextp=cur->np;
 }
 if(cur->c==data){
   prec->np=nextp;
   free(cur); 
 }
 else
  printf("Valore nodo non trovato");
}
void display(stru *first){
 while(first!=NULL){
  printf("%c -> ", first->c);
  first=first->np;
 }
 printf("\n");
}
void menu(stru **source){
 stru *cur=*source;
 char temp;
 int ch;
 do{
  printf("Inserisci\n1: per aggiungere\n2: per eliminare\n0: per terminare\n");
  scanf("%d",&ch);
  switch (ch){
   case 1:
    printf("Insersci il carattere del nodo\n");
    scanf("\n%c",&temp);
    insert(&cur,temp);
    //insertSort(source,temp);
    display(*source);
   break;
   case 2:
    printf("Inserisci l'elemento del nodo che vuoi eliminare\n");
    scanf("\n%c",&temp);
    delete(source,temp);
    break;
   case 0:
    printf("Menu terminato.\n");
    break;
   default:
    printf("Valore menu sbagliato. Riprova.\n");
   break;
  }
 }while(ch);
}
void insertSort(stru **src, char data){
 stru *nodo=*src,*prec=*src;
 stru *newnode=malloc(sizeof(stru));
 newnode->c=data;
 newnode->np=NULL;
 if(data<(nodo->c)){
  newnode->np=nodo;
  *src=newnode;
 }
 else{
  while((nodo!=NULL)&&(data>=(nodo->c))){
   prec=nodo;
   nodo=nodo->np;
  }
  if(nodo==NULL)
   prec->np=newnode;
  else{
   prec->np=newnode;
   newnode->np=nodo;
  }
 }
}
void pulizia(stru *lista){
 //caso base
 if(lista==NULL)
  return;
 else{
  //chiamata ricorsiva
  pulizia(lista->np);
  free(lista);
 }
}