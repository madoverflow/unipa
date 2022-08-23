#include <stdio.h>

void main(){
 int number;
 int div;
 printf("Inserisci un nunero intero\n");
 scanf("%d",&number);
 for(int i=2;i<=11;i++){
  div=number/i;
  if(!(number-(div*i)))
   printf("Il numero %d e' divisibile per %d\n",number,i);
 }
}
