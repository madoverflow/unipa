#include <stdio.h>
#include "interfaceBSTADT.h"

void main(){
 int choose;
 ItemTree a,b;
 ItemTree *itemPtr;
 size_t N=0,M=0;
 //creazione BST
 treeInit();
 do{
  printf("Inserisci:\n1 inserimento foglie\n2 ricerca foglie\n3 distanza foglie\n4 stampa albero\n5 visita PreOrder\n6 Visita PostOrder\n7 Visita in ordine\n8 Minimo valore\n9 Cancellazione minimo\n10 Cancellazione valore\n11 Visita per livelli\n0 per terminare\n");
  scanf("\n%d",&choose);
  switch (choose){
   case 1:
    printf("Inserisci il numero delle foglie dell'albero\n");
    scanf("\n%ld",&N);
    for(int i=0; i<N; i++){ 
     a=generateItem();
     treeInsertNode(a);
    }
    N=0;
    break;
   case 2:
    printf("Inserisci il valore da ricercare\n");
    a=getItem();
    if(search(a,&N))
     printf("Il valore è stato trovato. Numero confronti necessari: %ld\n",N);
    else
     printf("Valore non trovato\n");
    N=0;
    break;
   case 3:
    printf("Inserisci i valori tra i quali si vuol calcolare la distanza\n");
    a=getItem();
    b=getItem();
    M=distance(a,b);
    if(M)
     printf("La distanza tra i due valori è: %ld\n",M);
    else
     printf("Valori uguali o valori non facenti parte dell'albero\n");
    N=0;
    M=0;
    break;
   case 4:	
    printTree();
    break;
   case 5:
    treePreOrder();
    break;
   case 6:
    treePostOrder();
    break;
   case 7:
    treeInOrder();
    break;
   case 8:
    itemPtr=minimum();
    if(itemPtr!=NULL){
     printf("Minimo valore del BST\n");
     putItem(*itemPtr);
    }
    break;
   case 9:
    deleteMin();
    printTree();
    break;
   case 10:
    printf("Inserimento valore da cancellare\n");
    a=getItem();
    treeDelete(a);
    printTree();
    break;
   case 11:
    treeLevelOrder();
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