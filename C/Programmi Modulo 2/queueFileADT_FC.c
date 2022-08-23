#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "interfaceQueueADT_FC.h"

struct Coda{
 FILE *fd;
 size_t tail;
 size_t nelements;
};

typedef struct Coda Queue;
static size_t SIZE=sizeof(Item),count=0; 

queuePtr queueInit(queuePtr Q){
 size_t comodo,a,b;
 char str1[17],str2[15]="_queuefile.bin";
 str2[14]='\0';
 queuePtr que=malloc(sizeof(Queue));
 if(que==NULL){
  printf("Spazio nell'heap insufficiente. Coda non inizializzata\n");
  return NULL;
 }
 else{
  a=count/10;
  if(a)
   b=(a*10)-(count);
  else
   b=count;
  str1[0]=a+48;
  str1[1]=b+48;
  str1[2]='\0';
  strcat(str1,str2);
  Q=que;
  Q->tail=0;
  Q->nelements=0;
  Q->fd=fopen(str1,"wb+");
  count++;
  return Q;
 }
}

bool queueIsEmpty(queuePtr Q){
 return (Q->nelements)==0;
}

void enqueue(queuePtr Q, Item val){
 size_t nelm;
 nelm=fwrite(&val, SIZE, 1, Q->fd);
 if(nelm<1)
  printf("Spazio insufficiente. Funzione enqueue fallita().\n");
 else
  Q->nelements+=1;
}

Item *dequeue(queuePtr Q){
 Item *p=malloc(sizeof(Item));
 FILE comodo;
 if(queueIsEmpty(Q)){
  printf("La coda è vuota.\n");
  fseek(Q->fd, 0, SEEK_SET);
  Q->tail=0;
  p=NULL;
 }
 else{
  comodo=*(Q->fd);
  fseek(Q->fd, (Q->tail)*SIZE, SEEK_SET);
  fread(p, SIZE, 1, Q->fd);
  Q->tail+=1;
  Q->nelements-=1;
  *(Q->fd)=comodo;
 }
 return p;
}

void display(queuePtr Q){
 FILE *comodo=Q->fd;
 size_t dim=Q->nelements;
 if(queueIsEmpty(Q))
  printf("La coda è vuota\n");
 else{
  fseek(comodo, (Q->tail)*SIZE, SEEK_SET);
  while(dim>0){
   #ifdef intero
   int valore;
   fread(&valore, SIZE, 1, comodo);
   printf(" %d -> ",valore);
   #else
    #ifdef virgola
     float valore;
     fread(&valore, SIZE, 1, comodo);
     printf(" %f -> ",valore);
    #else
     char valore;
     fread(&valore, SIZE, 1, comodo);
     printf(" %c -> ",valore);   
    #endif
   #endif
   dim--;
  }
  printf("\n");
 }
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