#include <stdio.h>
#include <string.h>

static void printReverseWords(char str[]);
static void reverse();

void main(){
 char str[81];
 printf("Inserisci una stringa di massimo 80 elementi\n");
 gets(str);
 printf("Stringa -> %s\n",str);
 printf("Visualizzazione inversa parole della stringa\n");
 printReverseWords(str);
}

static void printReverseWords(char str[]){
 char *token;
 token=strtok(str," ");
 reverse();
 puts(token);
}

static void reverse(){
 char *token,*comodoPtr;
 token=strtok(NULL, " ");
 comodoPtr=token;
 if(token!=NULL){
  reverse();
  puts(comodoPtr);
 }
}
