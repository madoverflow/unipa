#include <stdio.h>

void main(){
 int n,count=0;
 float s=0;
 printf("Inserisci un numero intero positivo o -1 per terminare\n");
 scanf("%d",&n);
 while((n!=-1)&&(n>=0)){
  count++;
  s+=n;
  printf("Inserisci un numero intero positivo o -1 per terminare\n");
  scanf("%d",&n);
 }
 if(count)
  printf("La media aritmetica e': %f\n",s/count);
}
