#include <stdio.h>

void main(){
 char c;
 printf("Inserisci un carattere\n");
 c=getchar();
 if((c>='0')&&(c<='9'))
  printf("Hai inserito un carattere numerico");
 else
  if((c>='a')&&(c<='z'))
   if((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u'))
	   printf("Hai inserito una vocale minuscola");
   else
    printf("Hai inserito una consonante minuscola");
  else
   printf("Hai inserito un carattere generico");
}