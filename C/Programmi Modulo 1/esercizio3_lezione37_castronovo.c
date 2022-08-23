#include <stdio.h>
void MaxMin(double *V, int dim, double **M, double **m);

void main(){
 double v1[4]={3.0,2.8,10.0,1.0};
 double *max=v1;
 double *min=v1;
 MaxMin(v1,4,&max,&min);
 printf("Il massimo vale %3.4f ed il minimo %3.4f",*max,*min);
}

void MaxMin(double *V, int dim, double **M, double **m){
 for(dim--;dim>=0;dim--,V++){
  if(*V>**M)
   *M=V;
  if(*V<**m)
   *m=V;
 }
}