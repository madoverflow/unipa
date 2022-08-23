#include <stdio.h>
#include <stdlib.h>
#include "interfaceQueueADT.h"
void resizable(const Item val);

static size_t SIZE=4,N=0,tail=0,top=0;
static Item *queue=NULL;

void queueInit(){
 queue=malloc(SIZE*sizeof(Item));
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
 if((!N)||(N<SIZE)){
  queue[tail]=val;
  tail=(tail+1)%SIZE;
  N+=1;
 }
 else
  resizable(val);
}

Item *dequeue(){
 Item x,*p=NULL;
 if(N>0){
  x=queue[top];
  top=(top+1)%SIZE;
  N-=1;
  p=&x;
 }
 else
  printf("Coda vuota.\n");
 return p;
}

bool queueIsEmpty(){
 return N==0;
}

void resizable(const Item val){
 SIZE*=2;
 Item *v=malloc(SIZE*sizeof(Item));
 if(v==NULL){
  printf("Spazio nell'heap insufficiente. Dimensione coda invariata.\n");
  display();
 }
 else{
  for(int i=0; i<N; i++){
   v[i]=queue[top];
   top=(top+1)%(SIZE/2);
  }
  v[N]=val;
  N+=1;
  tail=N;
  top=0;
  free(queue);
  queue=v;
  v=NULL;
 }
}

void display(){
 size_t point=top;
 if(!N)
  printf("Coda vuota.\n");
 else{
  for(int i=N; i>0; i--){
   #ifdef intero
    printf(" %d -> ",queue[point]);
    #else
     #ifdef virgola
      printf(" %f -> ",queue[point]l);
     #else
      #ifdef struttura
       Item com;
       com=(queue[point])->val;
       printf(" %d -> ",com->element);
       com=NULL;
      #else
       printf(" %c -> ",queue[point]);   
      #endif
     #endif
    #endif
   point=(point+1)%SIZE;
  }
 }
 printf("\n");
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