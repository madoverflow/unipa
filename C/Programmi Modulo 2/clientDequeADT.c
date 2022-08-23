#include <stdio.h>
#include "interfaceDequeADT.h"

void main(){
 int choose;
 Item a,*b;
 //creazione Deque
 dequeInit();
 do{
  printf("Inserisci:\n1 inserimento nel deque\n2 estrazione dal deque\n3 stampa del deque\n0 per terminare\n");
  scanf("\n%d",&choose);
  switch (choose){
   case 1:
    a=getItem();
    pushDeque(a);
    break;
   case 2:
    b=popDeque();
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