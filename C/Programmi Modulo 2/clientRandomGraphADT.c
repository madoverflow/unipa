#include <stdio.h>
#include "interfaceRandomGraphADT.h"

void main(){
 int choose;
 size_t N;
 do{
  printf("Inserisci:\n1 creazione albero casuale\n2 stampa nodi albero\n3 stampa liste adiacenti\n0 per terminare\n");
  scanf("\n%d",&choose);
  switch (choose){
   case 1:
    printf("Insersci il numero di nodi da inserire\n");
    scanf("%ld",&N);
    graphInit(N);
    break;
   case 2:
    printGraphNodes();
    break;
   case 3:	
    printNeighbors();
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