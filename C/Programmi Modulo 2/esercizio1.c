#include <stdio.h>
void reverse(const char * const sPtr);

void main(){
 unsigned const int SIZE = 81;
 char str[SIZE];
 printf("Inserisci una stringa di massimo %d elementi\n",SIZE-1);
 gets(str);
 reverse(str); 
}

void reverse(const char * const sPtr){
 //caso base
 if(sPtr[0]=='\0')
  return;
 //chiamata ricorsiva
 else{
  reverse(&sPtr[1]);
  putchar(sPtr[0]);
 }
}