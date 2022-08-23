#include <stdio.h>
#include <stdlib.h>
#include "mysortinglibrary.h"

char compare(double *A, double*B);

void main(){
 unsigned int const N=5;
 unsigned int i;
 unsigned char chose;
 double A[5]={4.2,5.4,-1.3,-1.2,-6.84},*p;
 void **V=(void **)malloc(N*sizeof(double *));
 for(i=0;i<N;i++)
  *(V+i)=A+i;
 printf("Scegli un algoritmo per ordinare il tuo array: \n1 sorting ingenuo\n2 selection sorting\n3 bubble sort\n4 insertion sort\n");
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
  default :
   printf("Scelta non valida. Array non ordinato.\n");
   break;
 }
 for(i=0;i<N;i++){
  p=*(V+i);
  printf("%3.4lf ",*p);
 }
}

char compare(double *A, double*B){
 return(((*A-*B)>0)-((*A-*B)<0));
}