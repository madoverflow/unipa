#include <stdio.h>
#include <string.h>

void main(){
 unsigned int i;
 char str[2];
 char *op[4]={"somma","moltiplicazione","divisione","differenza"};
 float a,b;
 printf("Inserisci i due operandi:\n");
 scanf("%f %f",&a,&b);
 while(getchar()!='\n');
 printf("Scrivi, l'operatore delll'operazione da effettuare.\nSomma +\nMoltiplicazione *\nDivisione /\nDifferenza -\n");
 gets(str);
 if(!strcmp(str,"+"))
  printf("La somma tra %3.4f e %3.4f vale: %3.4f\n",a,b,a+b);
 else
  if(!strcmp(str,"*"))
   printf("La moltiplicazione tra %3.4f e %3.4f vale: %3.4f\n",a,b,a*b);
  else
   if(!strcmp(str,"-"))
    printf("La differenza tra %3.4f e %3.4f vale: %3.4f\n",a,b,a-b);
   else
   	if(!strcmp(str,"/"))
   	 if(b)
   	  printf("La divisione tra %3.4f e %3.4f vale: %3.4f\n",a,b,a/b);
   	 else
   	  printf("Non è possibile eseguire la divisione\n");
   	else
   	 printf("Non hai inserito un'operazione valida\n");	
}