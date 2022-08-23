#include <stdio.h>
unsigned char uguali(int a[],unsigned int N);

void main(){
 unsigned int i;
 const unsigned int N=4;
 int v[N];
 for(i=0;i<N;i++){
 	printf("Inserisci l'elemento della posizione %d\n",i);
 	scanf("%d",&v[i]);
 }
 printf("Valore ritornato dalla funzione: %d\n",uguali(v,N));
}

unsigned char uguali(int a[],unsigned int N){
 unsigned int k;
 for(k=0;(a[k]==a[k+1])&&(k<N-2);k++);
 return (a[k]==a[k+1]);
}