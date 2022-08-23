#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

static long int convertToInt(char str[], size_t dim);

void main(){
 char ch,pref[4]={'0'},num[8]={'0'};
 size_t i=0;
 long int valNumber=0,valPref=0;
 printf("Inserisci un numero formato da 7 cifre\n");
 while(i<3&&(ch=getchar())!='\n'){
  if(ch>='0'&&ch<='9'){
   pref[i]=ch;
   num[i]=ch;
   i++;
  }
 }
 pref[3]='\0';
 valNumber=valPref;
 while((ch=getchar())!='\n'&&i<7){
  if(ch>='0'&&ch<='9'){
   num[i]=ch;
   i++;
  }
 }
 num[7]='\0';
 valPref=convertToInt(pref,3);
 valNumber=convertToInt(num,7);
 printf("Prefisso\n");
 puts(pref);
 printf("Conversione prefisso in numero decimale -> %ld\n",valPref);
 printf("Numero completo\n");
 puts(num);
 printf("Conversione numero completo in numero decimale -> %ld\n",valNumber);
}

static long int convertToInt(char str[], size_t dim){
 long int val=0;
 for(int i=0,j=dim-1; i<dim; i++,j--){
  val+=(str[i]-48)*pow(10,j);
  printf("%ld\n",val);
 }
 return val;
}