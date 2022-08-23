#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool palindrome(const char * const sPtr);
bool control(const char * const s, size_t a, size_t b);

void main(){
 const size_t size=81;
 char str[size];
 printf("Inserisci una stringa di massimo %d elementi\n",size-1);
 gets(str);
 if(palindrome(str))
  printf("La stringa e' palindroma\n");
 else
  printf("La stringa non e' palindroma\n");
}

bool palindrome(const char * const sPtr){
 size_t b=strlen(sPtr);
 return control(sPtr,0,b-1);
}

bool control(const char * const s, size_t a, size_t b){
 //caso base
 if((b-a)<=1)
  return 1;
 else
  //chiamata ricorsiva
  return ((s[a]==s[b])&&control(&s[1],0,b-2));
}