#include <stdio.h>
#include <stdlib.h>
unsigned int mystrlen(char s[]);
char *copia(char *src);

void main(){
 unsigned int const N=81;
 char src[N],*str;
 printf("Inserisci una stringa di massimo %d elementi\n",N-1);
 gets(src);
 str=copia(src);
 printf("Stringa copiata nell'heap: %s",str);
}

unsigned int mystrlen(char s[]){
 unsigned int i;
 for(i=0;s[i];i++);
 return (i+1);
}
char *copia(char *src){
 unsigned int M=mystrlen(src),i;
 char *stringa=(char *)malloc(M*sizeof(char));
 for(i=0;src[i];i++)
  stringa[i]=src[i];
 stringa[i]=0;
 return stringa;
}