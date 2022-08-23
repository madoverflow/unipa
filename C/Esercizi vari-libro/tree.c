#include <stdio.h>
#include <stdlib.h>
#include "treeInterface.h"
#include <time.h>

void main(){
 int number,num,distanza;
 Tree T;
 srand(time(NULL));
 T=treeInit(T);
 for(int i=0; i<20; i++)
  treeInsert(T,rand()%100);
 printTree(T);
 printf("Inserisci la coppia di valore di cui determinare la distanza\n");
 scanf("%d %d",&number,&num);
 //treeSearch(T,number);
 //treeDelete(T,number);
 distanza=treeDistance(T,number,num);
 if(distanza==-1)
  printf("Uno o entrambi i nodi non sono presenti nell'albero\n");
 else
  printf("Distanza tra i due nodi -> %d\n",distanza);
 printf("%d\n",distanza);
 printTree(T);
}
