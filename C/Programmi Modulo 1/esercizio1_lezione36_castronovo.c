#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *inverti(const char *s);

void main(){
 unsigned int const N=81;
 char str[N],*inv;
 printf("Inserisci una stringa di massimo %d elementi\n",N-1);
 gets(str);
 inv=inverti(str);
 printf("Stringa invertita: %s",inv);
}

char *inverti(const char *s){
 unsigned int i;
 int M;
 M=strlen(s);
 char *rev=(char *)malloc((M+1)*sizeof(char));
 rev[M]=0;
 for(i=0,M--;M>=0;i++,M--)
  rev[i]=s[M];
 return rev;
}