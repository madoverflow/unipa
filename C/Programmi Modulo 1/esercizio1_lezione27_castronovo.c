#include <stdio.h>
unsigned char primo(unsigned int n);

void main(){
 unsigned int n,i;
 printf("Inserisci il numero n (positivo)\n");
 scanf("%d",&n);
 #ifdef DEBUG
  printf("Il valore del numero inserito e' %d\n",n);
 #endif
 for(i=2;i<n;i++){
  #ifdef DEBUG
   printf("Valore i: %d\n",i);
  #endif
  if(primo(i))
   printf("Il numero %d e' primo\n",i);
 }
}
unsigned char primo(unsigned int n){
 int j;
 for(j=2;(n%j)&&(j<n);j++){
  #ifdef DEBUG
   printf("Valore j: %d\n",j);
  #endif
 }
 return(j==n);
}