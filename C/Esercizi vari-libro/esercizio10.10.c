#include <stdio.h>
#include <stdlib.h>
#define SIZE 32
static void printBinary(int x, size_t mask, int e);
size_t count=0;
void main(){
 int x;
 size_t mask=1;
 printf("Inserisci un numero intero: \n");
 scanf("%d",&x);
 printBinary(x,mask,0);
 printf("\n");
 x=x>>2;
 printBinary(x,mask,0);
 printf("\n");
}

static void printBinary(int x, size_t mask, int e){
 if(e<SIZE){
 size_t result;
 count++;
 result=x&(mask<<e);
 printBinary(x,mask,e+1);
 result=result>>e;
 printf("%ld",result);
 }
}
