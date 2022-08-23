#include <stdio.h>
void merge(int C[], int A[], int B[], const unsigned int a, const unsigned int b);

void main(){
 const unsigned int size=12; 
 //gli array devono essere ordinati
 int A[]={6,7,8,9,10,11,12};
 int B[]={1,2,3,4,5};
 //
 int C[size];
 merge(C,A,B,7,5);
 printf("Fusione degli array\n");
 for(unsigned int i=0; i<12; i++)
  printf(" %d ",C[i]);
}

void merge(int C[], int A[], int B[], const unsigned int a, const unsigned int b){
 unsigned int i=0,j=0,k=0;
 while((i!=(a))&&(j!=(b))){
  if(A[i]<B[j])
   C[k++]=A[i++];
  else
   C[k++]=B[j++];
 }
 if(i==(a))
  while(j!=(b))
   C[k++]=B[j++];
 else
  while(i!=(a))
   C[k++]=A[i++];
}