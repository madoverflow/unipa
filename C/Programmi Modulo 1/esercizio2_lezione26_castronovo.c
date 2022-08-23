#include <stdio.h>

void main(){
 unsigned int r,q,i;
 float s=0;
 do{
  printf("Inserisci i due numeri interi (positivi)\n");
  scanf("%d %d",&r,&q);
 }while((!r)||(!q));
 if(r>q){
  r+=q;
  q=r-q;
  r-=q;
 }
 for(i=r;i<=q;s+=(float)1/i,i++);
 printf("La somma vale: %f\n",s);
}
