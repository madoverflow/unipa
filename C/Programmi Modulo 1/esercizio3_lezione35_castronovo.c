#include <stdio.h>
#include <stdlib.h>
unsigned int mystrlen(char s[]);
char *unisci(char *a, char *b);

void main(){
 unsigned int const N=81;
 char str1[N],str2[N],*ris;
 printf("Inserisci le due stringhe di massimo %d elementi\n",N-1);
 gets(str1);
 gets(str2);
 ris=unisci(str1,str2);
 printf("Le due stringhe concatenate sono: %s",ris);
}

unsigned int mystrlen(char s[]){
 unsigned int i;
 for(i=0;s[i];i++);
 return (i+1);
}
char *unisci(char *a, char *b){
 unsigned int M,i,j;
 M=(mystrlen(a)+mystrlen(b))-1;
 char *ab=(char *)malloc(M*sizeof(char));
 for(i=0;a[i];i++)
  ab[i]=a[i];
 for(j=0;b[j];j++,i++)
  ab[i]=b[j];
 ab[i]=0;
 return ab;
}