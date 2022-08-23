#include <stdio.h>
#include <stdlib.h>
double *somma(double *a, double *b, int dim);

void main(){
 unsigned int i=0;
 double v1[3]={3.0,2.1,1.0};
 double v2[3]={3.0,1.0,1.0};
 double *sum;
 sum=somma(v1,v2,3);
 printf("Il vettore somma vale\n(");
 for(i=0;i<3;i++)
  printf("%3.4f,",*sum++);
 printf(")");
}

double *somma(double *a, double *b, int dim){
 int i=dim;
 double *som=(double *)malloc(dim*sizeof(double));
 for(dim--;dim>=0;dim--)
  *som++=(*a++)+(*b++);
 return (som-i);
}