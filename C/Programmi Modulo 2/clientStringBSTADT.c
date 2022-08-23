#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interfaceBSTADT.h"

void main(){
 const size_t SIZE=81;
 char str[SIZE],a[SIZE],b[SIZE],*token;
 char key[2]=" ";
 int choose;
 size_t N=0,M=0,i=0;
 //creazione BST
 treeInit();
 do{
  printf("Inserisci:\n1 inserimento foglie\n2 ricerca foglie\n3 distanza foglie\n4 stampa albero\n0 per terminare\n");
  scanf("\n%d",&choose);
  switch (choose){
   case 1:
    printf("Inserisci la stringa di massimo %ld elementi contenenti le parole da inserire nell'albero\n",SIZE-1);
    getchar();
    gets(str);
    token=strtok(str,key);
    while(token!=NULL){
     treeInsertNode(token);
     token=strtok(NULL,key);
    }
    break;
   case 2:
    printf("Inserisci la parola da cercare (massimo %ld elementi)\n",SIZE-1);
    getchar();
    gets(a);
    if(search(a,&N))
     printf("La parola è stata trovata. Numero confronti necessari: %ld\n",N);
    else
     printf("Parola non trovata\n");
    N=0;
    break;
   case 3:
    printf("Inserisci le parole (massimo %ld elementi) delle quali si vuol calcolare la distanza\n",SIZE-1);
    getchar();
    gets(a);
    gets(b);
    M=distance(a,b);
    if(M)
     printf("La distanza tra le due parole è: %ld\n",M);
    else
     printf("Parole uguali o parole non facenti parte dell'albero\n");
    N=0;
    M=0;
    break;
   case 4:	
    printTree();
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