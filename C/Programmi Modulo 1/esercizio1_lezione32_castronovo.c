#include <stdio.h>
int trova(int a[],unsigned int N,unsigned int n);

void main(){
 unsigned int i,n;
 const unsigned int N=4;
 int v[N];
 for(i=0;i<N;i++){
    printf("Inserisci l'elemento della posizione %d\n",i);
    scanf("%d",&v[i]);
 }
 printf("Inserisci il numero di riferimento\n");
 scanf("%d",&n);
 printf("Valore funzione trova: %d\n",trova(v,N,n));
}

int trova(int a[],unsigned int N,unsigned int n){
 int k;
 for(k=N-1;(a[k]!=n)&&(k>=0);k--);
 return k;
}
