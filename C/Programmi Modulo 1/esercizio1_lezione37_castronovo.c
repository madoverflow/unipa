#include <stdio.h>
double prodscal(double *a, double *b, int dim);

void main(){
 double v1[3]={3.0,2.1,1.0};
 double v2[3]={3.0,1.0,1.0};
 printf("Prodotto scalare: %3.4f",prodscal(v1,v2,3));
}

double prodscal(double *a, double *b, int dim){
 double s=0.0;
 for(dim--;dim>=0;dim--)
  s=s+((*a++)*(*b++));
 return s;
}