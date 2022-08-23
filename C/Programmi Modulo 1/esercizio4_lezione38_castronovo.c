#include <stdio.h>
#include <stdlib.h>
#include "libreria_esercizio4_lezione38_castronovo.h"

void minmax(int *V, int *Ma, int *mi, int dim);

void main(){
 unsigned int const N=5;
 unsigned int i,M;
 unsigned char chose;
 #ifdef HEAP
  int *A=(int *)malloc(N*sizeof(int));
  for(i=0;i<N;i++){
   printf("Inserisci elemento dell'array\n");
   scanf("%d",A+i);
  }
 #else
  int A[5]={4,5,1,1,6};
 #endif
 printf("Scegli un algoritmo per ordinare il tuo array: \n1 sorting ingenuo\n2 selection sorting\n3 bubble sort\n4 insertion sort\n5 counting sort\n");
 scanf("%d",&chose);
 switch (chose){
  case 1:
   sorting_ingenuo(A,N);
   break;
  case 2:
   selection_sorting(A,N);
   break;
  case 3:
   bubble_sort(A,N);
   break;
  case 4:
   insertion_sort(A,N);
   break;
  case 5:
   int ma=*A,mi=*A;
   minmax(A,&ma,&mi,N);
   M=(ma-mi)+1;
   int *B=(int *)calloc(M,sizeof(int));
   counting_sort(A,B,N,M,ma,mi);
   break;
  default :
   printf("Scelta non valida. Array non ordinato.\n");
   break;
 }
 for(i=0;i<N;i++)
  printf("%d ",*(A+i));
}

void minmax(int *V, int *Ma, int *mi, int dim){
 unsigned int i;
 for(i=0;i<dim;i++){
  if(*(V+i)>*Ma)
   *Ma=*(V+i);
  if(*(V+i)<*mi)
   *mi=*(V+i);
 }
}