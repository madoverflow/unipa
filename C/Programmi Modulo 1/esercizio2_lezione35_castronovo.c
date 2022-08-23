#include <stdio.h>
#include <stdlib.h>
char *copian(char *src, unsigned int n);

void main(){
 unsigned int const N=81;
 unsigned int n=0;
 char src[N],*str;
 printf("Inserisci una stringa di massimo %d elementi\n",N-1);
 gets(src);
 do{
  printf("Inserisci il numero di caratteri che vuoi copiare\n");
  printf("Deve essere minore o uguale ad %d\n",N-1);
  scanf("%d",&n);
 }while(n>=N);
 str=copian(src,n);
 printf("Stringa copiata nell'heap: %s",str);
}

char *copian(char *src, unsigned int n){
 unsigned int i;
 char *stringa=(char *)malloc((n+1)*sizeof(char));
 for(i=0;src[i]&&(i<n);i++)
  stringa[i]=src[i];
 stringa[i]=0;
 return stringa;
}