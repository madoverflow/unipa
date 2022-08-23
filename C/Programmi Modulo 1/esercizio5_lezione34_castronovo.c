#include <stdio.h>
unsigned int mystrlen(char s[]);
unsigned char converti(char s[], unsigned int *pn);
unsigned int potenza(unsigned int base, unsigned int esponente);

void main(){
 unsigned int const N=81;
 unsigned int n=0;
 char stringa[N],flag;
 printf("Inserisci una stringa di massimo %d elementi\n",N-1);
 gets(stringa);
 flag=converti(stringa,&n);
 printf("%d %d\n",flag,n);
}
unsigned int mystrlen(char s[]){
 unsigned int i;
 for(i=0;s[i];i++);
 return (i+1);
}
unsigned char converti(char s[], unsigned int *pn){
 unsigned int i,M=mystrlen(s)-2;
 for(i=0;s[i]&&((s[i]>='0')&&(s[i]<='9'));i++)
  *pn=*pn+((s[i]-'0')*potenza(10,M-i));
 return(s[i] ? 0 : 1);
}
unsigned int potenza(unsigned int base, unsigned int esponente){
 unsigned int valore=1;
 while(esponente){
  valore=valore*base;
  esponente--;
 }
 return valore;
}