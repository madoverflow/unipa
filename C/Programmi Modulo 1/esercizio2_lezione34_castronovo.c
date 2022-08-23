#include <stdio.h>
unsigned int mystrlen(char s[]);
void copiastringa2(char s[], char t[]);

void main(){
 unsigned int N=81,M;
 char str1[N];
 printf("Inserisci una stringa di massimo %d elementi\n",N-1);
 gets(str1);
 N=mystrlen(str1);
 M=(2*N)-1;
 char str2[M];
 copiastringa2(str1,str2);
 printf("Le due stringhe sono\n%s\n%s",str1,str2);
}
unsigned int mystrlen(char s[]){
 unsigned int i;
 for(i=0;s[i];i++);
 return (i+1);
}
void copiastringa2(char s[], char t[]){
 unsigned int i,j=0;
 for(i=0;s[i];i++,j++){
  t[i*2]=s[i];
  t[(i*2)+1]=s[i];
 }
 t[i*2]=0;
}