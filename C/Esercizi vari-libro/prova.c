#include <stdio.h>

typedef union numero{
 int x;
 char c;
 double y;
}Prova;


void funzione1(int x, int y){
 printf("Somma %d\n",x+y);
}

void funzione2(int x, int y){
 printf("Differenza %d\n",x-y);
}

void main(){
 void (*functPtr)(int a, int b);
 functPtr=&funzione1;
 functPtr(3,2);
 functPtr=&funzione2;
 functPtr(3,2);
}

