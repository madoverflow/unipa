#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void occorrenze_lettere(char *str);
static void occorrenze_lunghezza(char *str);
static void occorrenze_parole(char *str);
static size_t occorrenze(char *word, char *str);

void main(){
 FILE *fd=fopen("strings.txt","r");
 char ch;
 char **array_stringhe=malloc(sizeof(char *));
 size_t i=0,j=0;
 if(fd==NULL)
  printf("Errore apertura file.\n");
 else{
  while(!feof(fd)){
   array_stringhe=realloc(array_stringhe,(i+1)*sizeof(char *));
   array_stringhe[i]=malloc(j*sizeof(char));
   fscanf(fd,"%c",&ch);
   while(ch!='\n'){
    array_stringhe[i][j]=ch;
    j++;
    array_stringhe[i]=realloc(array_stringhe[i],(j+1)*sizeof(char));
    fscanf(fd,"%c",&ch);
   }
   array_stringhe[i][j]='\0';
   j=0;
   i++;
  }
  i--;
  free(array_stringhe[i]);
  array_stringhe=realloc(array_stringhe,(i-1)*sizeof(char *));
  for(int k=0; k<i; k++){
   printf("Occorrenze lettere della stringa -> %s\n",array_stringhe[k]);
   occorrenze_lettere(array_stringhe[k]);
   printf("Occorrenze lunghezze parole della stringa -> %s\n",array_stringhe[k]);
   occorrenze_lunghezza(array_stringhe[k]);
   printf("Occorrenze parole della stringa -> %s\n",array_stringhe[k]);
   occorrenze_parole(array_stringhe[k]);
  }
 }
}

static void occorrenze_lettere(char *str){
 char lettere[256]={0};
 char *comodoPtr=str;
 for(int i=65; i<=90; i++){
  while((comodoPtr=strchr(comodoPtr,i))!=NULL){
   lettere[i]+=1;
   comodoPtr++;
  }
  comodoPtr=str;
 }
 for(int i=97; i<=122; i++){
  while((comodoPtr=strchr(comodoPtr,i))!=NULL){
   lettere[i]+=1;
   comodoPtr++;
  }
  comodoPtr=str;
 }
 for(int i=65; i<=90; i++)
  printf("%c e %c -> %d e %d\n",i,i+32,lettere[i],lettere[i+32]);
}

static void occorrenze_lunghezza(char *str){
 size_t size_max=strlen(str);
 int *lunghezze;
 char *token;
 char *str1=malloc(sizeof(char));
 size_t j=0,N;
 for(int i=0;i<size_max;i++){
  if(!(((str[i]>=33&&str[i]<=47)&&str[i]!=39)||(str[i]>=58&&str[i]<=63))){
   str1[j]=str[i];
   j++;
   str1=realloc(str1,(j+1)*sizeof(char));
  }
 }
 str1[j]='\0';
 size_max=strlen(str1);
 lunghezze=calloc(size_max,sizeof(int));
 token=strtok(str1, " ");
 while(token!=NULL){
  N=strlen(token);
  lunghezze[N]+=1;
  token=strtok(NULL, " ");
 }
 for(int i=0; i<size_max; i++)
  printf("Lunghezza parola %d, Occorrenze -> %d \n",i,lunghezze[i]);
 free(lunghezze);
 free(str1);
}

static void occorrenze_parole(char *str){
 size_t size_max=strlen(str);
 int *lunghezze;
 char *token;
 char *str1=malloc(sizeof(char)),*str2=malloc(sizeof(char));
 char **parole=malloc(sizeof(char *));
 size_t j=0,N=1;
 for(int i=0;i<size_max;i++){
  if(!(((str[i]>=33&&str[i]<=47)&&str[i]!=39)||(str[i]>=58&&str[i]<=63))){
   str1[j]=str[i];
   j++;
   str1=realloc(str1,(j+1)*sizeof(char));
  }
 }
 str1[j]='\0';
 str2=realloc(str2,(strlen(str1)+1)*sizeof(char));
 strcpy(str2,str1);
 token=strtok(str2, " ");
 j=0;
 while(token!=NULL){
  parole[j]=token;
  j++;
  parole=realloc(parole,(j+1)*sizeof(char *));
  token=strtok(NULL, " ");
 }
 parole=realloc(parole,j*sizeof(char *));
 for(int k=0; k<j; k++)
  printf("Parola %s, occorrenze -> %ld\n",parole[k],occorrenze(parole[k],str1));
 free(str2);
 free(parole);
 free(str1);
}

static size_t occorrenze(char *word, char *str){
 size_t N=0;
 char *token;
 char *str1=malloc((strlen(str)+1)*sizeof(char));
 strcpy(str1,str);
 token=strtok(str1, " ");
 while(token!=NULL){
  if(!strcmp(token,word))
   N++;
  token=strtok(NULL, " ");
 }
 free(str1);
 return N;
}
