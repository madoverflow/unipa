#include <stdio.h>
#include <stdlib.h>
void menu(int *q, int *tail, int *top, int *dim, int *SIZE);
void enqueue(int **ptrQueue, int *tail, int *top, int val, int *dim, int *SIZE);
int *dequeue(int *q, int *tail, int *top, int *dim, int *SIZE);
int *resizable(int *q, int *tail, int *top, const int val, int *dim, int *SIZE);
void printQueue(int *q, int top, int dim, int *SIZE);

void main(){
 int SIZE=4;
 int N=0;
 int *q=malloc(SIZE*sizeof(int));
 int tail=0,top=0;
 menu(q,&tail,&top,&N,&SIZE);
}

void menu(int *q, int *tail, int *top, int *dim, int *SIZE){
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
    enqueue(&q,tail,top,temp,dim,SIZE);
    break;
   case 2:
    if((p=dequeue(q,tail,top,dim,SIZE))!=NULL){
     printf("Valore estratto -> %d\n",*p);
     printQueue(q,*top,*dim,SIZE);
    }
    break;
   case 3:
    printf("Stampa della coda\n");
    printQueue(q,*top,*dim,SIZE);
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

void enqueue(int **ptrQueue, int *tail, int *top, int val, int *dim, int *SIZE){
 if((!(*dim))||(*dim<(*SIZE))){
  (*ptrQueue)[*tail]=val;
  *tail=(*tail+1)%(*SIZE);
  *dim=*dim+1;
  printf("%d",*SIZE);
 }
 else
  *ptrQueue=resizable(*ptrQueue,tail,top,val,dim,SIZE);
}

int *dequeue(int *q, int *tail, int *top, int *dim, int *SIZE){
 int x;
 int *p;
 if(*dim>0){
  x=q[*top];
  *top=(*top+1)%(*SIZE);
  *dim=*dim-1;
  p=&x;
 }
 else{
  printf("Coda vuota.\n");
  p=NULL;
  return p;
 }
}

int *resizable(int *q, int *tail, int *top, const int val, int *dim, int *SIZE){
 *SIZE*=2;
 int *v=malloc((*SIZE)*sizeof(int));
 if(v==NULL){
  printf("Spazio nell'heap insufficiente. Dimensione coda invariata.\n");
  printQueue(q,*top,*dim,SIZE);
 }
 else{
  for(int N=*dim,i=0;N>0;N--,i++){
   v[i]=q[*top];
   *top=(*top+1)%(*SIZE/2);
  }
  v[*dim]=val;
  for(int i=0; i<*SIZE; printf("%d ",v[i]),i++);
  *dim+=1;
  *tail=*dim;
  *top=0;
 }
 return v;
}

void printQueue(int *q, int top, int dim, int *SIZE){
 if(!dim)
  printf("Coda vuota.\n");
 else{
  for(; dim>0; dim--){
   printf(" %d ->",q[top]);
   top=(top+1)%(*SIZE);
  }
 }
 printf("\n");
}