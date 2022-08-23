#include <stdio.h>
unsigned char lessicografico(char s[], char t[]);

void main(){
 unsigned int const N=81;
 char str1[N],str2[N];
 printf("Inserisci due stringhe di massimo %d elementi\n",N-1);
 gets(str1);
 gets(str2);
 printf("Valore della funzione: %d\n",lessicografico(str1,str2));
}

unsigned char lessicografico(char s[], char t[]){
 unsigned int i=0;
 for(i=0;(s[i]&&t[i])&&(s[i]==t[i]);i++);
 return (s[i]<t[i]);
}