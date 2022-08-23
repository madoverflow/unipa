#include <stdio.h>
#include <stdlib.h>
#include "interfaceQueueADT.h"

static size_t N=0;
Item *queue;

void queueInit(){
 queue=NULL;
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
 Item *v=realloc(queue,(N+1)*sizeof(Item));
 if(v==NULL){
  printf("Spazio nell'heap insufficiente. Funzione enqueue() fallita.\n");
  display();
 }
 else{
  v[N]=val;
  if(queue!=v){
   free(queue);
   queue=v;
  }
  N++;
  v=NULL;
 }
}

Item *dequeue(){
 Item valore;
 Item *p=NULL,*comodo=malloc((N-1)*sizeof(Item));
 if(queueIsEmpty()||(comodo==NULL))
  printf("Coda vuota o spazio heap insufficiente.\n");
 else{
  valore=queue[0];
  p=&valore;
  N--;
  for(int i=1; i<=N; comodo[i-1]=queue[i], i++);
  free(queue);
  queue=comodo;
  comodo=NULL;
 }
 return p;
}

bool queueIsEmpty(){
 return N==0;
}

void putItem(Item *ptr){
 if(ptr!=NULL)
  #ifdef intero
   printf("Valore estratto -> %d\n",*ptr);
  #else
   #ifdef virgola
    printf("Valore estratto -> %f\n",*ptr);
   #else
    printf("Valore estratto ->  %c\n",*ptr);   
   #endif
  #endif
 ptr=NULL;
}

void display(){
 if(queueIsEmpty())
  printf("La coda è vuota.\n");
 else{
  for(int i=0; i<N; i++)
   #ifdef intero
    printf(" %d -> ",queue[i]);
   #else
    #ifdef virgola
     printf(" %f -> ",queue[i]);
    #else
     printf(" %c -> ",queue[i]);   
    #endif
   #endif
  printf("\n");
 }
}