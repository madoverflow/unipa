#include <stdio.h>
#include <stdlib.h>
void trasposta(double **MA,double**MB, int n, int m);

void main(){
 unsigned int const N=2,M=3;
 unsigned int i,j;
 double A[2][3]={{1,2,3},{4,5,6}},B[3][2];
 double *P=*A,*T=*B;
 #ifdef HEAP
  P=(double *)malloc(N*M*sizeof(double));
  T=(double *)malloc(N*M*sizeof(double));
  for(i=0;i<N*M;i++)
   *(P+i)=*(*A+i);
  for(i=0;i<N*M;i++)
   *(T+i)=*(*B+i);
 #endif
 trasposta(&P,&T,N,M);
 /*for(i=0;i<M*N;T++,i++){
  printf("%lf ",*T);
  if((i%N)==(N-1))
   printf("\n");
 }*/
 for(i=0;i<M;i++){
  for(j=0;j<N;T++,j++)
   printf("%lf ",*T);
  printf("\n");
 }
}

void trasposta(double **MA, double**MB, int n, int m){
 unsigned int i,j;
 for(i=0;i<m;i++)
  for(j=0;j<n;j++)
   *(*MB+i*n+j)=*(*MA+j*m+i);
}