#include <stdio.h>

void main(){
 unsigned int k,i,j;
 float s=0,s1;
 printf("Inserisci il numero intero positivo\n");
 scanf("%d",&k);
 for(i=1;i<=k;i++){
  for(j=1,s1=0;j<=i;s1+=(float)1/(i+j),j++);
  s+=s1*s1;
 }
 printf("La somma vale: %f\n",s);
}
