//Ricerca ricorsiva lineare lista
#include <stdio.h>
#include <stdlib.h>
#include "libreria_liste.h"
void linear_research(const stru * const src, const char data);

void main(){
 //Creazione lista
 char temp;
 stru *source=malloc(sizeof(stru));
 printf("Inserisci il carattere del nodo\n");
 scanf("\n%c",&temp);
 source->c=temp;
 source->np=NULL;
 //
 menu(&source);
 display(source);
 printf("Inserisci il carattere del nodo che vuoi cercare\n");
 scanf("\n%c",&temp);
 linear_research(source,temp);
}

void linear_research(const stru * const node, const char data){
 //casi base
 if(node==NULL){
  printf("Valore non trovato nella lista\n");
  return;
 }
 if(node->c==data){
  printf("Valore trovato\n");
  return;
 }
 //chiamata ricorsiva
 linear_research(node->np,data);
}