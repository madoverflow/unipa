//client stack ADT
#include <stdio.h>
#include <stdbool.h>
#include "interfaceStackArrayADT.h"

void main(){
 int choose;
 Item a,b;
 do{
  printf("Inserisci:\n1 funzione push\n2 funzione pop\n3 stampa dello stack\n0 per terminare\n");
  scanf("\n%d",&choose);
  switch (choose){
   case 1:
    a=take();
    stackPush(a);
    break;
   case 2:
    if(stackIsEmpty())
     printf("Stack vuoto\n");
    else{
     b=stackPop();
     printItem(b);
    }
    break;
   case 3:	
    printStack();
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