//ricerca numero occorrenze carattere stringa ricorsivo
#include <stdio.h>
size_t occorrenze(char *p,char c);

void main(){
 const size_t size=81;
 char c,str[size];
 printf("Inserisci una stringa di massimo %d elementi\n",size-1);
 gets(str);
 printf("Inserisci il carattere per contare le occorrenze: \n");
 scanf("%c",&c);
 printf("Numero occorrenze di %c nella stringa: %d\n",c,occorrenze(str,c));
}

size_t occorrenze(char *p, char c){
 //caso base
 if(*p=='\0')
  return 0;
 else
  return (*p==c)+occorrenze(p+1,c);
}