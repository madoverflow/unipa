#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *inserisci(const char *s, const char *t, int k);

void main(){
 unsigned int const N=81;
 int k;
 char str1[N],str2[N],*ris;
 printf("Inserisci due stringhe di massimo %d elementi\n",N-1);
 gets(str1);
 gets(str2);
 do{
  printf("Inserisci un indice intero\n");
  scanf("%d",&k);
 }while(k>strlen(str1));
 ris=inserisci(str1,str2,k);
 printf("Stringa conclusiva: %s",ris);
}

char *inserisci(const char *s, const char *t, int k){
 unsigned int M=(strlen(s)+strlen(t))+1;
 char *stringa=(char *)malloc(M*sizeof(char));
 strncpy(stringa,s,k);
 stringa[k]=0;
 strcat(stringa,t);
 strcat(stringa,s+k);
 return stringa;
}