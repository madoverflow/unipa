#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "interfaceStackArrayADT.h"

static Item *top;
static size_t dim=0;

bool stackIsEmpty(){
 return top==NULL;
}

Item take(){
 Item a;
 #ifdef intero
  printf("Inserisci il valore (intero) da aggiungere allo stack\n");
  scanf("\n%d",&a);
 #else
  #ifdef virgola
   printf("Inserisci il valore (float) da aggiungere allo stack\n");
   scanf("\n%f",&a);
  #else
   printf("Inserisci il valore (char) da aggiungere allo stack\n");
   scanf("\n%c",&a);
  #endif
 #endif
 return a;
}

void printItem(const Item a){
 #ifdef intero
  printf("Stampa item: %d\n",a);
 #else
  #ifdef virgola
   printf("Stampa item: %f\n",a);
  #else
   printf("Stampa item: %c\n",a);
  #endif
 #endif	
}

void stackPush(const Item a){
 size_t i;
 dim++;
 top=realloc(top,dim*sizeof(Item));
 //memoria insufficiente
 if(top==NULL)
  printf("Memoria insufficiente\n");
 else{
  //shift posizioni
  for(i=dim-1;i>0;i--)
   top[i]=top[i-1];
  top[i]=a;
 }
}

void printStack(){
 if(stackIsEmpty())
  printf("Stack vuoto\n");
 else{
  for(size_t i=0; i<dim; i++)
   #ifdef intero
    printf(" -> %d",top[i]);
   #else
    #ifdef virgola
     printf(" -> %f",top[i]);
    #else
     printf(" -> %c",top[i]);
    #endif
   #endif
  printf("\n");	
 }
}

Item stackPop(){
 Item a=top[0];
 for(size_t i=0;i<dim-1;i++)
  top[i]=top[i+1];
 dim--;
 top=realloc(top,dim*sizeof(Item));
 return a;
}
