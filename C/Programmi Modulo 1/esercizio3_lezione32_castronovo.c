#include <stdio.h>
unsigned char crescenti(float a[],unsigned int N);

void main(){
 unsigned int i;
 const unsigned int N=4;
 float v[N];
 for(i=0;i<N;i++){
 	printf("Inserisci l'elemento della posizione %d\n",i);
 	scanf("%f",&v[i]);
 }
 printf("Valore ritornato dalla funzione: %d\n",crescenti(v,N));
}

unsigned char crescenti(float a[],unsigned int N){
 unsigned int k;
 for(k=0;(a[k]<=a[k+1])&&(k<N-2);k++);
 return (a[k]<=a[k+1]);
}
