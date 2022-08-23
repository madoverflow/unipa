#include <stdio.h>
unsigned int occorrenze(char s[], char c);

void main(){
 unsigned int const N=81;
 char stringa[N],carattere;
 printf("Inserisci una stringa di massimo %d elementi\n",N-1);
 gets(stringa);
 printf("Inserisci un carattere\n");
 scanf("%c",&carattere);
 printf("Numero di volte che compare %c nella stringa: %d\n",carattere,occorrenze(stringa,carattere));
}

unsigned int occorrenze(char s[], char c){
 unsigned int i,count=0;
 for(i=0;s[i];i++)
  if(s[i]==c)
   count++;
 return count;
}