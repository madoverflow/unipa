#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int selection_sort(int v[], size_t n);
size_t minimo(int array[], size_t dim, size_t pos);
void scambio(int* n1,int* n2);

void main(){
 const size_t dim=20;
 int v[dim];
 srand(time(NULL));
 for(int i=0;i<dim;i++)
  v[i]=rand() % 90 + 10;
 selection_sort(v,dim);
 for(int i=0;i<dim;i++)
  printf(" %d ",v[i]);
}
int selection_sort(int v[], size_t n){
 size_t pos;
 //caso base
 if(n==1)
  return;
 else
  pos=minimo(v,n,0);
  scambio(&v[pos],&v[0]);
  selection_sort(&v[1],n-1);
  return;
}
size_t minimo(int array[], size_t dim, size_t pos){
 size_t min;
 //caso base
 if(dim==pos)
  return pos;
 else
  //chiamata ricorsiva
  min=minimo(&array[1],dim,pos+1);
  if(array[0]<array[min-pos])
   min=pos;
  return min;
}
void scambio(int* n1,int* n2){
 *n1=(*n1)^(*n2);
 *n2=(*n1)^*n2;
 *n1=(*n1)^(*n2);
}