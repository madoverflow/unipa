#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void alfabeto(char caratteri[], char *str);
static size_t occorrenze(char str[], char c);

void main(){
 FILE *fd=fopen("strings.txt","r");
 char ch;
 char **array_str=malloc(sizeof(char *));
 char caratteri[256]={0};
 size_t i=0,j=0;
 while(!feof(fd)){
  array_str=realloc(array_str,(i+1)*sizeof(char *));
  fscanf(fd,"%c",&ch);
  array_str[i]=malloc(sizeof(char));
  while(ch!='\n'){
   array_str[i][j]=ch;
   j++;
   array_str[i]=realloc(array_str[i],(j+1)*sizeof(char));
   fscanf(fd,"%c",&ch);
  }
  array_str[i][j]='\0';
  j=0;
  i++;
 }
 i--;
 free(array_str[i]);
 array_str=realloc(array_str,i*sizeof(char *));
 printf("Stringhe del file\n");
 for(int k=0; k<i; k++)
  puts(array_str[k]);
 for(int k=0; k<i; k++)
  alfabeto(caratteri,array_str[k]);
}

static void alfabeto(char caratteri[], char *str){
 for(int i=65; i<=90; i++)
  caratteri[i]=occorrenze(str,i);
 for(int i=97; i<=122; i++)
  caratteri[i]=occorrenze(str,i);
 printf("Occorrenze lettere dell'alfabeto nella stringa -> %s\n",str);
 for(int i=65; i<=90; i++)
  printf("%c e %c -> %d\n",i,i+32,caratteri[i]+caratteri[i+32]);
}

static size_t occorrenze(char str[], char c){
 char *comodoPtr=str;
 size_t count=0;
 while((comodoPtr=strchr(comodoPtr,c))!=NULL){
  comodoPtr++;
  count++;
 }
 return count;
}
