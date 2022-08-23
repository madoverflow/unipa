#include <stdio.h>
#include <stdlib.h>

void main(){
 FILE *fi;
 char str[30],*p;
 unsigned int i=0,M=1;
 float *V=(float *)malloc(sizeof(float));
 fi=fopen("vettore.txt","r");
 if(fi){
  while(fgets(str,30,fi)!=NULL){
   p=str;
   V=realloc(V,++M*sizeof(float));
   sscanf(str,"%f",V+(i++));
   p++;
   while((*p!='\n')&&(*p)){
    if(*p==32){
	 V=realloc(V,++M*sizeof(float));
     sscanf(p,"%f",V+(i++));
	}
	p++;
   }
  }
 }
 else{
  printf("Errore apertura file");
 }
 for(i=0;i<M-1;i++)
  printf("%3.4f\n",*(V+i));
}