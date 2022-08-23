#include <stdio.h>
#include <stdlib.h>
#include "mysortinglibrary.h"
int *search_binary(void **A, int a, int b, int *val);
char compareint(int *a, int *b);
char comparedouble(double *a, double *b);
char comparechar(char *a, char *b);
char (*compare) ();

void main(){
 unsigned int N=5;
 unsigned int i=0;
 #ifdef interi
  compare=&compareint;
  int A[5]={7,5,4,3,1};
  int val=1;
  void **V=(void **)malloc(N*sizeof(int *));
  void **p=(void **)malloc(sizeof(int *));
  for(i=0;i<N;i++)
   *(V+i)=A+i;
 #else
  #ifdef virgola
   compare=&comparedouble;
   double A[5]={4.2,5.4,-1.3,-1.2,-6.84};
   double val=8.2;
   void **V=(void **)malloc(N*sizeof(double *));
   void **p=(void **)malloc(sizeof(double *));
   for(i=0;i<N;i++)
    *(V+i)=A+i;
  #else
   compare=&comparechar;
   char A[5]="ciao";
   char val='i';
   N--;
   void **V=(void **)malloc(N*sizeof(char *));
   void **p=(void **)malloc(sizeof(char *));
   for(i=0;i<N;i++)
    *(V+i)=A+i;
  #endif
 #endif
 insertion_sort(V,N);
 *p=search_binary(V,0,N-1,&val);
 if(*p!=NULL)
  #ifdef interi
   printf("Il valore %d è stato trovato. Indirizzo: %d\n",*((int *)*p),*p);
  #else
   #ifdef virgola
    printf("Il valore %3.4lf è stato trovato. Indirizzo: %d\n",*((double *)*p),*p);
   #else
    printf("Il valore %c è stato trovato. Indirizzo: %d\n",*((char *)*p),*p);
   #endif
  #endif
 else
  printf("Valore non trovato\n");
}

int *search_binary(void **A, int a, int b, int *val){
 int c=(b-a)/2,*p=NULL;
 if(compare(*(A+b),val)==0){
  c=0;
  a=b;
 }
 else{
  while((c)&&(compare(*(A+a+c),val))){
   if(compare(val,*(A+(a+c)))==1)
    a=c+a;
   else
    b=c;
   c=(b-a)/2;
  }
 }
 if((c)||(compare(*(A+a),val)==0))
  p=*(A+a+c);
 return p;
}
char compareint(int *a, int *b)
{	
 return(((*a-*b)>0)-((*a-*b)<0));
}
char comparedouble(double *a, double *b)
{	
 return(((*a-*b)>0)-((*a-*b)<0));
}
char comparechar(char *a, char *b)
{	
 return(((*a-*b)>0)-((*a-*b)<0));
}