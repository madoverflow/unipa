#include <stdio.h>
#include <stdlib.h>
#include "libreria_liste.h"
void backwards(const stru * const node);

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
 printf("Lista visualizzata al contrario\n");
 backwards(source);
}

void backwards(const stru * const node){
 //caso base
 if(node==NULL)
  return;
 //chiamata ricorsiva
 backwards(node->np);
 printf("%c -> ",node->c);
}