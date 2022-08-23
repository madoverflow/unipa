#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned int occorrenze(const char *s, const char *t);

void main(){
 unsigned int const N=81;
 char str1[N],str2[N];
 do{
  printf("Inserisci due stringhe di massimo %d elementi\n",N-1);
  printf("Attenzione: la prima stringa deve avere un numero di elementi maggiore della seconda\n");
  gets(str1);
  gets(str2);
 }while(strlen(str1)<strlen(str2));
 printf("%s contiene %s %d volte",str1,str2,occorrenze(str1,str2));
}

unsigned int occorrenze(const char *s, const char *t){
 char *p;
 unsigned int count=0;
 p=strstr(s,t);
 while(p){
  count++;
  p++;
  p=strstr(p,t);
 }
 return count;
}