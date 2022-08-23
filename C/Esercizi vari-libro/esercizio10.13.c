#include <stdio.h>
static size_t packCharacters(char a, char b, char c, char d);
static void printBinary(long int number, size_t mask, size_t size);
static void displayBinary(long int number, size_t mask, size_t size, size_t e);
static void extractCharacters(size_t numero);
static void extract(size_t numero, char mask);

void main(){
 char a,b,c,d;
 size_t numero;
 size_t mask=1;
 printf("Inserisci 4 caratteri\n");
 scanf("%c %c %c %c",&a,&b,&c,&d);
 printf("Sequenze numeriche binarie dei 4 caratteri\n");
 printBinary(a,mask,8*sizeof(char));
 printBinary(b,mask,8*sizeof(char));
 printBinary(c,mask,8*sizeof(char));
 printBinary(d,mask,8*sizeof(char));
 numero=packCharacters(a,b,c,d);
 printf("Numeri concatenati in una sequenza di 32 bit\n");
 printBinary(numero,mask,4*sizeof(size_t));
 printf("Spacchettamento sequenza di 32 bit e stampa dei caratteri\n");
 extractCharacters(numero);
}

static size_t packCharacters(char a, char b, char c, char d){
 size_t numero=a;
 numero=numero<<8;
 numero=numero|b;
 numero=numero<<8;
 numero=numero|c;
 numero=numero<<8;
 numero=numero|d;
 return numero;
}

static void printBinary(long int number, size_t mask, size_t size){
 displayBinary(number, mask, size, 0);
 printf("\n");
}

static void displayBinary(long int number, size_t mask, size_t size, size_t e){
 if(e<size){
  size_t result;
  result=number&(mask<<e);
  displayBinary(number,mask,size,e+1);
  result=result>>e;
  printf("%ld",result);
 }
}

static void extractCharacters(size_t numero){
 char mask=~0;
 extract(numero,mask);
 printf("\n");
}

static void extract(size_t numero, char mask){
 if(numero!=0){
  char result=numero&mask;
  extract(numero>>8,mask);
  printf("%c ",result);
 }
}
