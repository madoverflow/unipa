#include <stdio.h>
#include <stdlib.h>
void trasposta(double **MA,double**MB, int n, int m);
double prodscal(double *a, double *b, int dim);

void main(){
 unsigned int const N=2,M=3;
 unsigned int i,j;
 double A[2][3]={{1,0,2},{0,3,-1}},B[3][2]={{4,1},{-2,2},{0,3}},C[2][3];
 double *F=*A,*P=*B,*T=*C,s=0.0;
 #ifdef HEAP
  F=(double *)malloc(N*M*sizeof(double));
  P=(double *)malloc(N*M*sizeof(double));
  T=(double *)malloc(N*M*sizeof(double));
  for(i=0;i<N*M;i++)
   *(F+i)=*(*A+i);
  for(i=0;i<N*M;i++)
   *(P+i)=*(*B+i);
  for(i=0;i<N*M;i++)
   *(T+i)=*(*C+i);
 #endif
 trasposta(&P,&T,M,N);
 for(i=0;i<N;i++)
  s=s+prodscal(F+i*M,T+i*M,M);
 printf("Il prodotto riga per colonna vale: %lf",s);

}
void trasposta(double **MA, double**MB, int n, int m){
 unsigned int i,j;
 for(i=0;i<m;i++)
  for(j=0;j<n;j++)
   *(*MB+i*n+j)=*(*MA+j*m+i);
}
double prodscal(double *a, double *b, int dim){
 double s=0.0;
 for(dim--;dim>=0;dim--){
  s=s+((*a++)*(*b++));
 }
 return s;
}