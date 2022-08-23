#include <stdio.h>
#include <stdlib.h>

void main(){
 FILE *fd=fopen("prova.txt","r");
 size_t dim,x;
 size_t i=0;
 char *str=malloc(sizeof(char));
 char c;
 while(!feof(fd)){
  fscanf(fd,"%c",&c);
  str=realloc(str,(i+1)*sizeof(char));
  if(c!='\n'){
   str[i]=c;
   i++;
  }
  else{
   str[i]='\0';
   puts(str);
   i=0;
  }
 }
 str[i-1]='\0';
 puts(str);
}