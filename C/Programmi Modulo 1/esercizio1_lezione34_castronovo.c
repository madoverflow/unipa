#include <stdio.h>
unsigned int mystrlen(char s[]);
void copiastringa(char s[], char t[]);

void main(){
 unsigned int N=81;
 char str1[N];
 printf("Inserisci una stringa di massimo %d elementi\n",N-1);
 gets(str1);
 N=mystrlen(str1);
 char str2[N];
 copiastringa(str1,str2);
 printf("Le due stringhe sono\n%s\n%s",str1,str2);
 
}

unsigned int mystrlen(char s[]){
 unsigned int i;
 for(i=0;s[i];i++);
 return (i+1);
}
void copiastringa(char s[], char t[]){
 unsigned int i=0;
 for(i=0;s[i];i++)
  t[i]=s[i];
 t[i]=0;
}