#include <stdio.h>
void merge(int A[], const unsigned int a, const unsigned int c1, const unsigned int c2, const unsigned int b);
void mergeSort(int A[], const unsigned int dim);
void subprocess(int A[], const unsigned int a, const unsigned int b);

void main(){
 const unsigned int size=12;
 int A[]={6,7,8,9,10,11,1,2,3,4,5,12};
 mergeSort(A,size);
 //merge(A,0,11/2,(11/2)+1,11);
 printf("Ordinamento crescente array con mergesort\n");
 for(int i=0; i<size; i++)
  printf(" %d ",A[i]);
}

void merge(int A[], const unsigned int a, const unsigned int c1, const unsigned int c2, const unsigned int b){
 unsigned int i=a,j=c2,k=0;
 int C[a+b+1];
 while((i!=(c1+1))&&(j!=(b+1))){
  if(A[i]<A[j])
   C[k++]=A[i++];
  else
   C[k++]=A[j++];
 }
 if(i==(c1+1))
  while(j!=(b+1))
   C[k++]=A[j++];
 else
  while(i!=(c1+1))
   C[k++]=A[i++];
 for(int x=0; x<k; x++)
  A[x]=C[x];
}

void mergeSort(int A[], const unsigned int dim){
 subprocess(A,0,dim-1);
}

void subprocess(int A[], const unsigned int a, const unsigned int b){
 size_t c1,c2;
 //caso base
 if((b-a)<1)
  return;
 else{
  c1=(b+a)/2;
  c2=c1+1;
  //chiamata ricorsiva
  subprocess(A,a,c1);
  subprocess(A,c2,b);
  //termine chiamata ricorsiva
  merge(A,a,c1,c2,b);
  printf("%d %d %d %d\n",a,b,c1,c2);
 }
}