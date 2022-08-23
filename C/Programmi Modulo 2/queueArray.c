#include <stdio.h>
#include <stdlib.h>
void menu(int **q, int *n);
void enqueue(int **q, int *n, const int val);
int dequeue(int **q, int *dim);
void printQueue(const int * const v, int dim);

void main(){
 int *q=NULL;
 int size=0;
 menu(&q,&size);
}

void menu(int **q, int *n){
 int choose;
 int temp;
 do{
  printf("Inserisci: \n1 funzione enqueue\n2 funzione dequeue\n3 stampa della coda\n0 per terminare\n");
  scanf("\n%d",&choose);
  switch (choose){
   case 1:
    printf("Inserisci il numero da inserire nella coda\n");
    scanf("\n%d",&temp);
    enqueue(q,n,temp);
    break;
   case 2:
    printf("Valore estratto dalla coda -> %d\n",dequeue(q,n));
    printQueue(*q,*n);
    break;
   case 3:
    printf("Stampa della coda\n");
    printQueue(*q,*n);
    break;
   case 0:
    printf("Menu terminato.\n");
    break;
   default:
    printf("Hai sbagliato ad inserire il valore. Riprova.\n");
    break;
  }
 }while(choose);
}

void enqueue(int **q, int *n, const int val){
 int *comodo=NULL;
 comodo=realloc(*q,((*n)+1)*sizeof(int));
 if(comodo==NULL)
  printf("Spazio nell'heap insufficiente\n");
 else{
  comodo[*n]=val;
  *n+=1;
  if(comodo!=*q){
   free(*q);
   *q=comodo;
   comodo=NULL;
  }
 }
}

int dequeue(int **q, int *dim){
 int *comodo=NULL;
 int x;
 comodo=malloc((*dim-1)*sizeof(int));
 if((comodo==NULL)||(!dim)){
  printf("Spazio nell'heap insufficiente o coda vuota. Funzione dequeue() fallita.\n");
  *q=NULL;
 }
 else{
  *dim-=1;
  x=(*q)[0];
  for(int i=1; i<=*dim; comodo[i-1]=(*q)[i], i++);
  free(*q);
  *q=comodo;
  comodo=NULL;
  printQueue(*q,*dim);
 }
 return x;
}

void printQueue(const int * const v, int dim){
 if(v==NULL)
  printf("Coda vuota\n");
 else{
  for(int i=0; i<dim; printf(" %d -> ",v[i++]));
  printf("\n");
 }
}
