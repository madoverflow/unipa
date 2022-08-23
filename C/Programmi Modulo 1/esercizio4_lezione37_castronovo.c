#include <stdio.h>
#include <stdlib.h>
void addSort(double **V, int dim, double a);

void main(){
 unsigned const int N=4;
 unsigned int i;
 double *v=(double *)malloc(N*sizeof(double));
 double a=2.5;
 printf("Inserisci %d elementi\n",N);
 printf("%d\n",v);
 for(i=0;i<N;v++,i++)
  scanf("%lf",v);
 v-=i;
 addSort(&v,N,a);
 printf("Array aggiornato\n");
 for(i=0;i<N+1;printf(" %3.4f ",*v++),i++);
}

void addSort(double **V, int dim, double a){
 unsigned int i;
 *V=realloc(*V,(dim+1)*sizeof(double));
 for(i=0;(i<dim)&&(a>=**V);*V+=1,i++);
 if(a<**V){
   for(dim--;dim>=i;dim--){
	*(*V+(dim-i+1))=*(*V+(dim-i));
   }
  **V=a;
 }
 *V-=i;
}
