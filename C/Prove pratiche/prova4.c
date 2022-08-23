//6 settembre 2018

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct node{
 int val;
 struct node *rightPtr;
 struct node *leftPtr;
}Nodo;

Nodo *createBinary(int v[],int dim);
void create(Nodo *radPtr, int v[], int pos, int pot);
void printTree(Nodo *radPtr);
void display(Nodo *radPtr);
void mergesort(int *v, int dim);
void subSort(int *v, size_t a, size_t b);
void merge(int *v, size_t a, size_t middle1, size_t middle2, size_t b);

static int level=0;

void main(){
 Nodo *rootPtr;
 int a,N,*v,M;
 srand(time(NULL));
 printf("Inserisci il numero di elementi dell'albero.\n");
 scanf("%d",&N);
 a=(log2(N))+1;
 M=pow(2,a)-1;
 v=calloc(M,sizeof(int));
 for(size_t i=0; i<N; i++){
  printf("Inserisci un numero intero\n");
  scanf("%d",&v[i]);
 }
 for(size_t i=N; i<M; v[i]=rand()%100,i++);
 printf("Numeri interi dell'array\n");
 for(size_t i=0; i<M; printf("%d -> ",v[i]),i++);
 printf("\n");
 mergesort(v,M);
 printf("Array ordinato\n");
 for(size_t i=0; i<M; printf("%d -> ",v[i]),i++);
 printf("\n");
 printf("Albero bilanciato\n");
 rootPtr=createBinary(v,M);
 printTree(rootPtr);
}

Nodo *createBinary(int v[], int dim){
 int pot=(dim+1)/2;
 int pos=pot-1;
 Nodo *rootPtr=malloc(sizeof(Nodo));
 Nodo **comRight,**comLeft;
 rootPtr->leftPtr=NULL;
 rootPtr->rightPtr=NULL;
 rootPtr->val=v[pos];
 create(rootPtr,v,pos,pot/2);
 return rootPtr;
}

void create(Nodo *radPtr, int v[], int pos, int pot){
 if(pot!=0){
  Nodo *newRight=malloc(sizeof(Nodo));
  Nodo *newLeft=malloc(sizeof(Nodo));
  newRight->rightPtr=NULL;
  newRight->leftPtr=NULL;
  newRight->val=v[pos+pot];
  newLeft->rightPtr=NULL;
  newLeft->leftPtr=NULL;
  newLeft->val=v[pos-pot];
  radPtr->rightPtr=newRight;
  radPtr->leftPtr=newLeft;
  create(radPtr->rightPtr,v,pos+pot,pot/2);
  create(radPtr->leftPtr,v,pos-pot,pot/2);
 }
}

void printTree(Nodo *radPtr){
 if(radPtr==NULL)
  printf("Albero vuoto\n");
 else{
  display(radPtr);
  printf("\n");
 }
}

void display(Nodo *radPtr){
 if(radPtr!=NULL){
  level++;
  display(radPtr->rightPtr);
  printf(">%*s%5d\n",level*5,"", radPtr->val);
  display(radPtr->leftPtr);
  level--;
 }
}

void mergesort(int *v, int dim){
 size_t middle1,middle2;
 if(dim>1){
  middle1=(0+dim-1)/2;
  middle2=middle1+1;
  subSort(v,0,middle1);
  subSort(v,middle2,dim-1);
  merge(v,0,middle1,middle2,dim-1);
 }
 else
  printf("Array gia' ordinato\n");
}

void subSort(int *v, size_t a, size_t b){
 size_t middle1,middle2;
 if((b-a)>=1){
  middle1=(b+a)/2;
  middle2=middle1+1;
  subSort(v,a,middle1);
  subSort(v,middle2,b);
  merge(v,a,middle1,middle2,b);
 }
}

void merge(int *v, size_t a, size_t middle1, size_t middle2, size_t b){
 size_t dim=(b-a)+1,i=0,j=a;
 int com[dim];
 while((j<=middle1)&&(middle2<=b)){
  if(v[j]<v[middle2]){
   com[i]=v[j];
   j++;
  }
  else{
   com[i]=v[middle2];
   middle2++;
  }
  i++;
 }
 if(j>middle1)
  while(middle2<=b){
   com[i]=v[middle2];
   middle2++;
   i++;
  }
 else
  while(j<=middle1){
   com[i]=v[j];
   j++;
   i++;
  }
 i=0;
 for(size_t k=a; k<=b; v[k]=com[i],k++,i++);
}
