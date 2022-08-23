//2 luglio 2021

#include <stdio.h>
#include <stdlib.h>

typedef struct arco{
 size_t nodo;
 struct arco *arcoPtr;
}Arco;

void insertList(Arco **topPtr, size_t x);
void printList(Arco *curPtr);
size_t countNodes(Arco *curPtr);
void mergesort(Arco **array_liste, size_t *lookuptable, size_t dim);
void subSort(Arco **array_liste, size_t *lookuptable, size_t a, size_t b);
void merge(Arco **array_liste, size_t *lookuptable, size_t a, size_t middle1, size_t middle2, size_t b);

void main(){
 FILE *fd;
 Arco **array_liste=malloc(sizeof(Arco *));
 size_t i=0,*lookuptable;
 char ch;
 fd=fopen("grafo.txt","r");
 if(fd==NULL)
  printf("Errore apertura file\n");
 else{
  while(!feof(fd)){
   array_liste=realloc(array_liste,(i+1)*sizeof(Arco *));
   array_liste[i]=NULL;
   fscanf(fd,"%c",&ch);
   while(ch!='\n'){
    if(ch>='0'&&ch<='9')
     insertList(&array_liste[i],ch-48);
    fscanf(fd,"%c",&ch); 
   }
   i++;
  }
  i--;
  array_liste=realloc(array_liste,i*sizeof(Arco *));
  lookuptable=calloc(i,sizeof(size_t));
  printf("Lettura linee di testo file\n");
  for(size_t k=0; k<i; k++)
   printList(array_liste[k]);
  for(size_t k=0; k<i; k++)
   lookuptable[k]=countNodes(array_liste[k]);
  mergesort(array_liste,lookuptable,i);
  printf("Stampa in ordine di numero di nodi liste\n");
  for(size_t k=0; k<i; k++)
   printList(array_liste[k]);
 }
}

void insertList(Arco **topPtr, size_t x){
 Arco *newPtr=malloc(sizeof(Arco));
 newPtr->nodo=x;
 newPtr->arcoPtr=NULL;
 while(*topPtr!=NULL)
  topPtr=&((*topPtr)->arcoPtr);
 *topPtr=newPtr;
}

void printList(Arco *curPtr){
 if(curPtr==NULL)
  printf("Lista vuota\n");
 else{
  while(curPtr!=NULL){
   printf("%ld -> ",curPtr->nodo);
   curPtr=curPtr->arcoPtr;
  }
  printf("\n");
 } 
}

size_t countNodes(Arco *curPtr){
 size_t val=0;
 while(curPtr!=NULL){
  val++;
  curPtr=curPtr->arcoPtr;
 }
 return val;
}

void mergesort(Arco **array_liste, size_t *lookuptable, size_t dim){
 size_t middle1,middle2,a=0,b=dim-1;
 if(dim>1){
  middle1=(b+a)/2;
  middle2=middle1+1;
  subSort(array_liste,lookuptable,a,middle1);
  subSort(array_liste,lookuptable,middle2,b);
  merge(array_liste,lookuptable,a,middle1,middle2,b);
 }
}

void subSort(Arco **array_liste, size_t *lookuptable, size_t a, size_t b){
 if((b-a)>=1){
  size_t middle1,middle2;
  middle1=(b+a)/2;
  middle2=middle1+1;
  subSort(array_liste,lookuptable,a,middle1);
  subSort(array_liste,lookuptable,middle2,b);
  merge(array_liste,lookuptable,a,middle1,middle2,b);
 }
}

void merge(Arco **array_liste, size_t *lookuptable, size_t a, size_t middle1, size_t middle2, size_t b){
 size_t i=a;
 Arco *comodoListe[(b-a)+1];
 size_t comodoLook[(b-a)+1];
 size_t k=0;
 while((i<=middle1)&&(middle2<=b)){
  if(lookuptable[i]<lookuptable[middle2]){
   comodoLook[k]=lookuptable[i];
   comodoListe[k]=array_liste[i];
   i++;
   k++;
  }
  else{
   comodoLook[k]=lookuptable[middle2];
   comodoListe[k]=array_liste[middle2];
   middle2++;
   k++;
  }
 }
 if(i>middle1)
  while(middle2<=b){
   comodoLook[k]=lookuptable[middle2];
   comodoListe[k]=array_liste[middle2];
   middle2++;
   k++;
  }
 if(middle2>b)
  while(i<=middle1){
   comodoLook[k]=lookuptable[i];
   comodoListe[k]=array_liste[i];
   i++;
   k++;
  }
 for(size_t j=0; j<k; j++,a++){
  array_liste[a]=comodoListe[j];
  lookuptable[a]=comodoLook[j];
 }
}
