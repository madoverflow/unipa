#include <stdio.h>
#include "interfaceQueueADT.h"

void main(){
 int choose;
 Item a,*b;
 //creazione coda
 queueInit();
 do{
  printf("Inserisci:\n1 funzione enqueue\n2 funzione dequeue\n3 stampa della coda\n0 per terminare\n");
  scanf("\n%d",&choose);
  switch (choose){
   case 1:
    a=getItem();
    enqueue(a);
    break;
   case 2:
    b=dequeue();
    putItem(b);
    break;
   case 3:	
    display();
    break;
   case 0:
    printf("Menu terminato\n");
    break;
   default:
    printf("Valore sbagliato. Riprovare.\n");
    break;
  }
 }while(choose);
}