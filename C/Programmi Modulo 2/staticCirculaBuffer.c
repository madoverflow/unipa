#include <stdio.h>
#define SIZE 4
void menu(int q[], int *tail, int *top, int *dim);
void enqueue(int q[], int *tail, int *top, int val, int *dim);
int *dequeue(int q[], int *tail, int *top, int *dim);
void printQueue(int q[], int top, int dim);

void main(){
 int N=0;
 int q[10]={0};
 int tail=0,top=0;
 menu(q,&tail,&top,&N);
}

void menu(int q[], int *tail, int *top, int *dim){
 int *p;
 int choose;
 int temp;
 do{
  printf("Inserisci: \n1 funzione enqueue\n2 funzione dequeue\n3 stampa della coda\n0 per terminare\n");
  scanf("\n%d",&choose);
  switch (choose){
   case 1:
    printf("Inserisci il numero da inserire nella coda\n");
    scanf("\n%d",&temp);
    enqueue(q,tail,top,temp,dim);
    break;
   case 2:
    if((p=dequeue(q,tail,top,dim))!=NULL){
     printf("Valore estratto -> %d\n",*p);
     printQueue(q,*top,*dim);
    }
    break;
   case 3:
    printf("Stampa della coda\n");
    printQueue(q,*top,*dim);
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

void enqueue(int q[], int *tail, int *top, int val, int *dim){
 if((!(*dim))||(*dim<SIZE)){
  q[*tail]=val;
  *tail=(*tail+1)%SIZE;
  *dim=*dim+1;
 }
 else
  printf("Coda piena.\n");
}

int *dequeue(int q[], int *tail, int *top, int *dim){
 int x;
 int *p;
 if(*dim>0){
  x=q[*top];
  *top=(*top+1)%SIZE;
  *dim=*dim-1;
  p=&x;
 }
 else{
  printf("Coda vuota.\n");
  p=NULL;
  return p;
 }
}

void printQueue(int q[], int top, int dim){
 if(!dim)
  printf("Coda vuota.\n");
 else{
  for(; dim>0; dim--){
   printf(" %d ->",q[top]);
   top=(top+1)%SIZE;
  }
 }
 printf("\n");
}