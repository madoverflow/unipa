#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *immettitesto();

void main(){
 char *ris=immettitesto();
 printf("Stringa: %s",ris);
}

char *immettitesto(){
 unsigned int i=0;
 char *str=(char *)malloc(250*sizeof(char));
 char ch,*p;
 printf("Inserisci una stringa. Attenzione, verranno salvati solo i primi 256 caratteri\n");
 while(((ch=getchar())!='\n')&&(i<=256)){
  str[i]=ch;
  i++;
 }
 str[i]=0;
 p=strstr(str,"fine.");
 *(p-1)=0;
 return str;
}