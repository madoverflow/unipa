#include <stdio.h>
void trasforma(char s[]);

void main(){
 unsigned int const N=81;
 char stringa[N];
 printf("Inserisci una stringa di massimo %d elementi\n",N-1);
 gets(stringa);
 trasforma(stringa);
 printf("Stringa trasformata: %s\n",stringa);
}

void trasforma(char s[]){
 unsigned int i;
 for(i=0;s[i];i++)
  if((s[i]>='a')&&(s[i]<='z'))
   s[i]-=32;
}