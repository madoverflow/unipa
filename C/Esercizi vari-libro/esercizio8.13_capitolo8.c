#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void printLatinWord(char *str);

void main(){
 char *str=malloc(sizeof(char));
 char ch;
 size_t i=0;
 printf("Inserisci il frase in inglese. Considerati solo lettere e spazi.\n");
 while((ch=getchar())!='\n'){
  if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||ch==32){
   str=realloc(str,i+1*sizeof(char));
   str[i]=ch;
   i++;
  }
 }
 str[i]='\0';
 printf("Stampa della frase\n");
 puts(str);
 printf("Stampa della frase in latino maccheronico\n");
 printLatinWord(str);
}

static void printLatinWord(char *str){
 char *token,*comodoPtr,lettera[2];
 char *tokenComodo=malloc(sizeof(char));
 char *strLatin=malloc(sizeof(char));
 size_t N=0,dim;
 token=strtok(str," ");
 dim=strlen(token);
 N+=dim+3;
 strLatin=realloc(strLatin,N*sizeof(char));
 lettera[0]=token[0];
 lettera[1]='\0';
 strLatin=strcpy(strLatin,token+1);
 strLatin=strcat(strLatin,lettera);
 strLatin=strcat(strLatin,"ay");
 while((token=strtok(NULL," "))!=NULL){
  dim=strlen(token);
  N+=dim+4;
  strLatin=realloc(strLatin,N*sizeof(char));
  lettera[0]=token[0];
  lettera[1]='\0';
  strLatin=strcat(strLatin," ");
  strLatin=strcat(strLatin,token+1);
  strLatin=strcat(strLatin,lettera);
  strLatin=strcat(strLatin,"ay");
 }
 strLatin[N-1]='\0';
 puts(strLatin);
}