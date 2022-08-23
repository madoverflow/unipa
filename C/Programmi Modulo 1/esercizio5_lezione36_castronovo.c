#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *elimina(const char *s, const char *t);

void main(){
 unsigned int const N=81;
 unsigned int i=0;
 char *str=(char *)calloc(N,sizeof(char));
 char *ris;
 unsigned char tab[256]={0};
 unsigned char ch;
 printf("Inserisci una stringa di massimo %d elementi\n",N-1);
 gets(str);
 printf("Inserisci i caratteri che vuoi elminare dalla stringa\n");
 while((ch=getchar())!='\n'){
  tab[ch]=1;
  i++;
 }
 ris=elimina(str,tab);
 printf("La stringa risulta: %s\n",ris);
}
 
char *elimina(const char *s, const char *t){
 unsigned int M=strlen(s);
 char *res=(char *)malloc((M+1)*sizeof(char));
 char *p=res;
 while(*s){
  for(;s&&(!*(t+(*s)));*res++=*s++);
  s++;
 }
 *res=0;
 return p;
}