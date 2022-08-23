#include <stdio.h>
#define SIZE 64

static void reverseBits(size_t number);
static void printBits(size_t number);
static void displayBits(size_t number, size_t mask, size_t e);

void main(){
 size_t number;
 printf("Inserisci un numero intero senza segno\n");
 scanf("%ld",&number);
 printf("Stampa dei bit del numero\n");
 printBits(number);
 printf("Bit reverse stampa\n");
 reverseBits(number);
}

static void reverseBits(size_t number){
 size_t mask=1;
 size_t result;
 for(int i=0; i<SIZE;i++){
  result=number&(mask<<i);
  result=result>>i;
  printf("%ld",result);
 }
 printf("\n");
}

static void printBits(size_t number){
 size_t mask=1;
 displayBits(number,mask,0);
 printf("\n");
}

static void displayBits(size_t number, size_t mask, size_t e){
 if(e<SIZE){
  displayBits(number,mask,e+1);
  size_t result;
  result=number&(mask<<e);
  result=result>>e;
  printf("%ld",result);
 }
}
