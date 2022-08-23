#include <stdio.h>
#include <stdlib.h>
#include "libreria_liste.h"

void main(){
 //Creazione lista
 char temp;
 stru *source=malloc(sizeof(stru));
 source->np=NULL;
 printf("Inserisci il carattere del nodo\n");
 scanf("%c",&temp);
 source->c=temp;
 //
 menu(&source);
 display(source);
 pulizia(source);
 printf("%d\n",sizeof(source));
}