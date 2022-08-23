//ricerca binaria ricorsiva per le liste
#include <stdio.h>
#include <stdlib.h>
struct lista{
 char c;
 struct lista *np;
};
typedef struct lista stru;
void insert(stru **p,const char l, stru **pos);
stru ** menu(stru **source, unsigned int *count);
void display(stru *first);
char recursive_binary(stru **A, unsigned int b, const char data);

void main(){
 unsigned int count=1;
 char temp;
 stru **array;
 stru *source=malloc(sizeof(stru));
 printf("Inserisci il carattere del nodo\n");
 scanf("\n%c",&temp);
 source->c=temp;
 source->np=NULL;
 array=menu(&source,&count);
 for(int i=0; i<count; i++)
  printf("%c -> ",array[i]->c);
 printf("Inserisci il carattere del nodo da cercare\n");
 scanf("\n%c",&temp);
 printf("%d",recursive_binary(&array[0],count-1,temp));
}

void insert(stru **p,const char l, stru **pos){
 stru *nn=malloc(sizeof(stru));
 (*p)->np=nn;
 *p=nn;
 nn->np=NULL;
 nn->c=l;
 *pos=nn;
}
stru ** menu(stru **source, unsigned int *count){
 stru *cur=*source;
 stru **array=malloc(sizeof(stru *));
 array[0]=*source;
 char temp;
 int ch;
 do{
  printf("Inserisci\n1: per aggiungere\n2: per eliminare\n0: per terminare\n");
  scanf("%d",&ch);
  switch (ch){
   case 1:
    printf("Insersci il carattere del nodo\n");
    scanf("\n%c",&temp);
    *count+=1;
    array=realloc(array,(*count)*sizeof(stru *));
    insert(&cur,temp,&array[(*count)-1]);
    display(*source);
   break;
   case 0:
    printf("Menu terminato.\n");
    break;
   default:
    printf("Valore menu sbagliato. Riprova.\n");
   break;
  }
 }while(ch);
 return array;
}
void display(stru *first){
 while(first!=NULL){
  printf("%c -> ", first->c);
  first=first->np;
 }
 printf("\n");
}
char recursive_binary(stru **A, unsigned int b, const char data){
 unsigned int a=0,m;
 m=(b-a)/2;
 //casi base
 if(!m)
  return (*A)->c==data;
 if(((A[m]->c)==data)||(A[b]->c==data))
  return 1;
 //chiamata ricorsiva
 if(data>A[m]->c)
  recursive_binary(&A[m],b-m,data);
 else
  recursive_binary(&A[0],m,data);
}