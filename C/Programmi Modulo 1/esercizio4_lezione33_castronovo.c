#include<stdio.h>
unsigned int mystrlen(char s[]);

void main()
{
 unsigned int const N=81;
 char stringa[N];
 printf("Inserisci una stringa di massimo %d elementi\n",N-1);
 gets(stringa);
 printf("La lunghezza della stringa vale: %d",mystrlen(stringa));
}

unsigned int mystrlen(char s[]){
 unsigned int i;
 for(i=0;s[i];i++);
 return (i+1);
}