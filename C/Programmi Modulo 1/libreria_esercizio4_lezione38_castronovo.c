#include <stdlib.h>

void scambio(int *n1,int *n2){
 *n1=(*n1)^(*n2);
 *n2=(*n1)^*n2;
 *n1=(*n1)^(*n2);
}

void sorting_ingenuo(int *V, unsigned int dim){
 unsigned int i,j;
 for(i=0;i<dim-1;i++)
  for(j=i+1;j<dim;j++)
   if(*(V+i)>*(V+j))
    scambio(V+i,V+j);
}

void selection_sorting(int *V, int dim){
 unsigned int i,j;
 int min;
 for(i=0;i<dim-1;i++){
  min=i;
  for(j=min+1;j<dim;j++)
   if(*(V+min)>*(V+j))
    min=j;
  if(min!=i)
   scambio(V+i,V+min);
 }
}

void bubble_sort(int *V, int dim){
 unsigned int i,j;
 char flag=1;
 while(flag)
  for(i=0;i<dim-1;dim--){
   flag=0;
   for(j=i+1;j<dim;j++)
    if(*(V+j-1)>*(V+j)){
     scambio(V+j,V+j-1);
     flag=1;
    }
   }
}

void insertion_sort(int *V, int dim){
 unsigned int i;
 int j,val;
 for(i=1;i<dim;i++){
  val=*(V+i);
  for(j=i-1;(j>=0)&&(*(V+j))>val;j--)
   if(*(V+j)>val)
    *(V+j+1)=*(V+j);
  *(V+j+1)=val;
 }
}

void counting_sort(int *V, int *W, int dimV, int dimW, int ma, int mi){
 unsigned int i,j;
 for(i=0;i<dimV;i++)
  *(W+(*(V+i)-mi))+=1;
 for(i=0;i<dimW;i++)
  for(j=0;j<*(W+i);j++)
    *(V++)=i+mi;
 free(W);
}