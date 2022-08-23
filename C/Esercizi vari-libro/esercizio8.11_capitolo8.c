#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void main(){
 char *article[5]={"the","a","one","some","any"};
 char *noun[5]={"boy","girl","dog","town","car"};
 char *verb[5]={"drove","jumped","ran","walked","skipped"};
 char *preposition[5]={"to","from","over","under","on"};
 char *str=malloc(sizeof(char));
 size_t val,nstr;
 srand(time(NULL));
 printf("Stampa stringhe casuali\n");
 for(int i=0; i<20; i++){
  val=rand()%5;
  nstr=strlen(article[val])+strlen(noun[val])+strlen(verb[val])+strlen(preposition[val]);
  str=realloc(str,(5+nstr)*sizeof(char));
  str=strcpy(str,article[val]);
  str=strcat(str," ");
  str=strcat(str,noun[val]);
  str=strcat(str," ");
  str=strcat(str,verb[val]);
  str=strcat(str," ");
  str=strcat(str,preposition[val]);
  str=strcat(str,".");
  str[0]=str[0]-32;
  str[4+nstr]='\0';
  puts(str);
 }
 
}