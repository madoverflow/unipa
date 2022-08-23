#include <stdio.h>
unsigned int contamaiuscole(char s[]);

void main(){
 unsigned int const N=81;
 char stringa[N];
 printf("Inserisci una stringa di massimo %d elementi\n",N-1);
 gets(stringa);
 printf("Numero di lettere maiuscole presenti nella stringa: %d\n",contamaiuscole(stringa));
}

unsigned int contamaiuscole(char s[]){
 unsigned int i,count=0;
 for(i=0;s[i];i++)
  if((s[i]>='A')&&(s[i]<='Z'))
   count++;
 return count;
}