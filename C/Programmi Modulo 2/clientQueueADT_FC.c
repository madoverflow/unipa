#include <stdio.h>
#include "interfaceQueueADT_FC.h"

void main(){
 int choose,scelta;
 size_t dim,queue;
 Item a,*b;
 printf("Inserisci il numero di code che vuoi gestire\n");
 scanf("\n%ld",&dim);
 queuePtr arrayqueue[dim];
 //creazione code
 for(int i=0; i<dim; i++)
  arrayqueue[i]=queueInit(arrayqueue[i]);
 do{
  do{
   printf("Inserisci il numero della coda da gestire. Code disponibili da %d a %ld\n",0,dim-1);
   scanf("\n%ld",&queue);
  }while((queue<0)||(queue>dim-1));
  do{
   printf("Inserisci:\n1 funzione enqueue\n2 funzione dequeue\n3 stampa della coda\n0 per terminare\n");
   scanf("\n%d",&choose);
   switch (choose){
    case 1:
     a=getItem();
     enqueue(arrayqueue[queue],a);
     break;
    case 2:
     b=dequeue(arrayqueue[queue]);
     putItem(b);
     break;
    case 3:	
     display(arrayqueue[queue]);
     break;
    case 0:
     printf("Menu terminato\n");
     break;
    default:
     printf("Valore sbagliato. Riprovare.\n");
     break;
   }
  }while(choose);
  printf("Vuoi gestire un'altra coda?\nSi qualunque numero\n0 terminare la gestione\n");
  scanf("\n%d",&scelta);
 }while(scelta);
 printf("Stampa delle code gestite\n");
 for(int i=0; i<dim; i++)
  display(arrayqueue[i]);
}