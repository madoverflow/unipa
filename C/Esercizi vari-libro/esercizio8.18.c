/*
//Esercizio originale
#include <stdio.h>
#include <string.h>

void main(){
 char str[81],occ,*strPtr,*comodoPtr;
 size_t count=0;
 printf("Inserisci una stringa di massimo 80 elementi\n");
 gets(str);
 printf("Inserisci il carattere da ricercare nella stringa\n");
 scanf("%c",&occ);
 comodoPtr=str;
 while((strPtr=strchr(comodoPtr,occ))!=NULL){
  comodoPtr=strPtr+1;
  count++;
 }
 printf("Numero di occorrenze -> %ld\n",count);
}*/

//Esercizio modificato con file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
 FILE *fd=fopen("strings.txt","r");
 char ch,*comodoPtr;
 char **array_str=malloc(sizeof(char *));
 char *str=malloc(sizeof(char));
 size_t i=0,j=0,count=0;
 if(fd==NULL)
  printf("Errore apertura file.\n");
 else{
  while(!feof(fd)){
   array_str=realloc(array_str,(j+1)*sizeof(char *));
   fscanf(fd,"%c",&ch);
   array_str[j]=malloc(sizeof(char));
   while(ch!='\n'){
    array_str[j][i]=ch;
    i++;
    array_str[j]=realloc(array_str[j],(i+1)*sizeof(char));
    fscanf(fd,"%c",&ch);
   }
   array_str[j][i]='\0';
   i=0;
   j++;
  }
  free(array_str[j]);
  array_str=realloc(array_str,(j-1)*sizeof(char *));
  j--;
  printf("Stringhe nel file\n");
  for(int i=0; i<j; i++)
   puts(array_str[i]);
  printf("Inserisci il carattere da ricercare nelle frasi\n");
  scanf("%c",&ch);
  for(int i=0; i<j; i++){
   comodoPtr=array_str[i];
   while((comodoPtr=strchr(comodoPtr,ch))!=NULL){
    comodoPtr++;
    count++;
   }
   printf("Numero occorrenze -> %ld\n",count);
   count=0;
  }
 }
}

