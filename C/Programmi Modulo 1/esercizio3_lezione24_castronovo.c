#include <stdio.h>

void main(){
 unsigned int x,y;
 printf("Inserisci i due numeri interi (positivi)\n");
 scanf("%d %d",&x,&y);
 if(x>y){
  x+=y;
  y=x-y;
  x-=y;
 }
 y=(y/x)*x;
 while(y>=x){
  printf("%d ",y);
  y=y-x;
 }
}
