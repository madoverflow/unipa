#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysortinglibrary.h"

char compare(char *A, char *B);

void main(){
 unsigned int const N=3,M=81;
 unsigned int i;
 unsigned char chose;
 char *p;
 void **V=(void **)malloc(N*sizeof(char *));
 for(i=0;i<N;i++){
  *(V+i)=(char *)malloc(M*sizeof(char));
  printf("Inserisci una stringa di massimo %d elementi\n",M-1);
  gets(*(V+i));
 }
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
  printf("%s ",*(V+i));
 }
}

char compare(char *A, char *B){
 return((strcmp(A,B)>0)-(strcmp(A,B)<0));
}