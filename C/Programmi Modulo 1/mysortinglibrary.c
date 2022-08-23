#include <stdlib.h>
#include <stdio.h>
extern char (*compare)();

void scambio(int *n1,int *n2){
 *n1=(*n1)^(*n2);
 *n2=(*n1)^*n2;
 *n1=(*n1)^(*n2);
}
void sorting_ingenuo(void **V, unsigned int dim){
 unsigned int i,j;
 for(i=0;i<dim-1;i++)
  for(j=i+1;j<dim;j++)
   if(compare(*(V+i),*(V+j))==1)
    scambio(V+i,V+j);
}
void selection_sorting(void **V, int dim){
 unsigned int i,j;
 int min;
 for(i=0;i<dim-1;i++){
  min=i;
  for(j=min+1;j<dim;j++)
   if(compare(*(V+min),*(V+j))==1)
    min=j;
  if(min!=i)
   scambio(V+i,V+min);
 }
}
void bubble_sort(void **V, int dim){
 unsigned int i,j;
 char flag=1;
 for(i=0;(i<dim-1)&&(flag);dim--){
  flag=0;
  for(j=i+1;j<dim;j++)
   if(compare(*(V+j-1),*(V+j))==1){
    scambio(V+j,V+(j-1));
    flag=1;
   }
 }
}
void insertion_sort(void **V, int dim){
 unsigned int i;
 int j;
 void *val;
 for(i=1;i<dim;i++){
  val=*(V+i);
  for(j=i-1;(j>=0)&&(compare((*(V+j)),val)==1);j--)
   if(compare(*(V+j),val)==1)
    *(V+j+1)=*(V+j);
  *(V+j+1)=val;
 }
}
void counting_sort(void **V, int *W, int dimV, int dimW, int mi){
 unsigned int i,j;
 for(i=0;i<dimV;i++){
  *(W+(*((int *)*(V+i))-mi))+=1;
 }
 for(i=0;i<dimW;i++)
  for(j=0;j<*(W+i);j++)
    *((int *)*(V++))=i+mi;
 free(W);
}