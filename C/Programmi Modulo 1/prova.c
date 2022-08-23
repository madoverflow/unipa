#include <stdio.h>
#include <stdlib.h>
void prova(void *p);

void main(){
 int val=3;
 prova(&val);
}

void prova(void *p){
 printf("%d",*((int *)p));
}