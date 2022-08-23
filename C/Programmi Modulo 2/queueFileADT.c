#include <stdio.h>
#include <stdlib.h>
#include "interfaceQueueADT.h"

static FILE *fd=NULL;
static size_t tail=0,N=0,size=sizeof(Item);

void queueInit(){
 fd=fopen("queue.bin","wb+");
}

bool queueIsEmpty(){
 return N==0;
}

Item getItem(){
 #ifdef intero
  int x;
  printf("Inserisci un numero intero\n");
  scanf("%d",&x);
 #else
  #ifdef virgola
   float x;
   printf("Inserisci un numero reale\n");
   scanf("%f",&x);
  #else
   char x;
   printf("Inserisci un carattere\n");
   scanf("%c",&x);
  #endif
 #endif
 return x;
}

void enqueue(Item val){
 size_t nelm;
 nelm=fwrite(&val, size, 1, fd);
 if(nelm<1)
  printf("Spazio insufficiente. Funzione enqueue fallita().\n");
 else
  N++;
}

Item *dequeue(){
 Item *p=malloc(sizeof(Item));
 FILE comodo;
 if(queueIsEmpty()){
  printf("La coda è vuota.\n");
  fseek(fd, 0, SEEK_SET);
  tail=0;
  p=NULL;
 }
 else{
  comodo=*fd;
  fseek(fd, tail*size, SEEK_SET);
  fread(p, size, 1, fd);
  tail++;
  N--;
  *fd=comodo;
 }
 return p;
}

void display(){
 FILE *comodo=fd;
 size_t dim=N;
 if(queueIsEmpty())
  printf("La coda è vuota\n");
 else{
  fseek(comodo, tail*size, SEEK_SET);
  while(dim>0){
   #ifdef intero
   int valore;
   fread(&valore, size, 1, comodo);
   printf(" %d -> ",valore);
   #else
    #ifdef virgola
     float valore;
     fread(&valore, size, 1, comodo);
     printf(" %f -> ",valore);
    #else
     char valore;
     fread(&valore, size, 1, comodo);
     printf(" %c -> ",valore);   
    #endif
   #endif
   dim--;
  }
  printf("\n");
 }
}

void putItem(Item *ptr){
 if(ptr!=NULL)
  #ifdef intero
   printf("Valore estratto -> %d\n",*ptr);
  #else
   #ifdef virgola
    printf("Valore estratto -> %f\n",*ptr);
   #else
    #ifdef struttura
     printf("Valore estratto -> %d\n",(*ptr)->element);
    #else
     printf("Valore estratto ->  %c\n",*ptr);   
    #endif
   #endif
  #endif
 ptr=NULL;
}