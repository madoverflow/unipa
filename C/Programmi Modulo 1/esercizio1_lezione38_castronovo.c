#include <stdio.h>
#include <stdlib.h>
void MinMax(double **A, int N, int M, double **mi, double **Mi);

void main(){
 unsigned int const N=3,M=3;
 int k1,k2;
 double A[3][3]={{1.0,2.0,3.0},{-4.0,12.0,65.0},{12.39,49.0,44.0}};
 double *P=*A;
 #ifdef HEAP
  unsigned int i;
  double *L=(double *)malloc(N*M*sizeof(double));
  for(i=0;i<N*M;i++)
   *(L+i)=*(*A+i);
  P=L;
 #endif
 double *Ma=*A,*mi=*A;
 MinMax(&P,N,M,&mi,&Ma);
 k1=Ma-*A;
 k2=mi-*A;
 printf("Il massimo si trova nella posizione : %d %d\n",k1/M,k1%M);
 printf("Il minimo si trova nella posizione : %d %d\n",k2/M,k2%M);
}

void MinMax(double **A, int N, int M, double **mi, double **Mi){
 unsigned int i;
 for(i=0;i<N*M;*A+=1,i++){
  if(**A>**Mi)
   *Mi=*A;
  if(**A<**mi)
   *mi=*A;
 }
}