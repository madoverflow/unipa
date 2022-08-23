#include <stdio.h>
#include <string.h>

void main(){
 char str[81],occ[81],*strPtr,*comodoPtr;
 printf("Inserisci una stringa di massimo 80 elementi\n");
 gets(str);
 printf("Inserisci la sottostringa da ricercare nella stringa\n");
 gets(occ);
 comodoPtr=str;
 while((strPtr=strstr(comodoPtr,occ))!=NULL){
  printf("Occorrenza trovata. Stampa della stringa a partire dall'occorrenza\n");
  puts(strPtr);
  comodoPtr=strPtr+1;
 }
}
