#include <stdio.h>
unsigned char stringanumero(char s[]);

void main(){
 unsigned int const N=81;
 char str1[N];
 printf("Inserisci una stringa di massimo %d elementi\n",N-1);
 gets(str1);
 printf("Valore della funzione: %d\n",stringanumero(str1));
}

unsigned char stringanumero(char s[]){
 unsigned int i;
 for(i=0;s[i]&&((s[i]>='0')&&(s[i]<='9'));i++);
 return(s[i] ? 0 : 1);
}