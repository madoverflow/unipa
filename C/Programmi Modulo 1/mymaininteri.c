#include <stdio.h>
#include <stdlib.h>
#include "mysortinglibrary.h"

void minmax(void **V, int **Ma, int **mi, int dim);
char compare(int *A, int*B);

void main(){
 unsigned int const N=5;
 unsigned int i,M;
 unsigned char chose;
 int A[5]={4,5,-1,1,6},*p;
 void **V=(void **)malloc(N*sizeof(int *));
 for(i=0;i<N;i++)
  *(V+i)=A+i;
 printf("Scegli un algoritmo per ordinare il tuo array: \n1 sorting ingenuo\n2 selection sorting\n3 bubble sort\n4 insertion sort\n5 counting sort\n");
 scanf("%d",&chose);
 switch (chose){
  case 1:
   sorting_ingenuo(V,N);
   break;
  case 2:
   selection_sorting(V,N);
   break;
  case 3:
   bubble_sort(V,N);
   break;
  case 4:
   insertion_sort(V,N);
   break;
  case 5:
   int *ma,*mi;
   ma=*V;
   mi=*V;
   minmax(V,&ma,&mi,N);
   M=(*ma-*mi)+1;
   int *B=(int *)calloc(M,sizeof(int));
   counting_sort(V,B,N,M,*mi);
   break;
  default :
   printf("Scelta non valida. Array non ordinato.\n");
   break;
 }
 for(i=0;i<N;i++){
  p=*(V+i);
  printf("%d ",*p);
 }
}

void minmax(void **V, int **Ma, int **mi, int dim){
 unsigned int i;
 for(i=0;i<dim;i++){
  if(compare(*(V+i),*Ma)==1)
   *Ma=*(V+i);
  if(compare(*(V+i),*mi)==-1)
   *mi=*(V+i);
 }
}
char compare(int *A, int*B){
 return((*A-*B>0)-(*A-*B<0));
}