#include <stdio.h>
#include "interfaceStackADT_FC.h"

void main(){
 int choose,scelta;
 size_t dim,stack;
 Item a,*b;
 printf("Inserisci il numero di stack che vuoi gestire\n");
 scanf("\n%ld",&dim);
 S arraystack[dim];
 //creazione code
 for(int i=0; i<dim; i++)
  arraystack[i]=stackInit(arraystack[i]);
 do{
  do{
   printf("Inserisci il numero dello stack da gestire. Stack disponibili da %d a %ld\n",0,dim-1);
   scanf("\n%ld",&stack);
  }while((stack<0)||(stack>dim-1));
  do{
   printf("Inserisci:\n1 funzione push\n2 funzione pop\n3 stampa dello stack\n0 per terminare\n");
   scanf("\n%d",&choose);
   switch (choose){
    case 1:
     a=getItem();
     stackPush(arraystack[stack],a);
     break;
    case 2:
     b=stackPop(arraystack[stack]);
     putItem(b);
     break;
    case 3:	
     stackDisplay(arraystack[stack]);
     break;
    case 0:
     printf("Menu terminato\n");
     break;
    default:
     printf("Valore sbagliato. Riprovare.\n");
     break;
   }
  }while(choose);
  printf("Vuoi gestire un altro stack?\nSi qualunque numero\n0 terminare la gestione\n");
  scanf("\n%d",&scelta);
 }while(scelta);
 printf("Stampa degli stack gestiti\n");
 for(int i=0; i<dim; i++)
  stackDisplay(arraystack[i]);
}