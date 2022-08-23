#include <stdio.h>
#include <stdlib.h>
#include "libreria_liste.h"
stru * merge(stru *list1, stru *list2);
stru * mergeSort(stru *src);

void main(){
 char temp;
 stru *src1=malloc(sizeof(stru));
 stru *src3=malloc(sizeof(stru));
 printf("Inserisci il carattere del nodo della prima lista\n");
 scanf("\n%c",&temp);
 src1->c=temp;
 src1->np=NULL;
 menu(&src1);
 printf("Stampa delle due liste inserite\n");
 display(src1);
 src3=mergeSort(src1);
 pulizia(src1);
 printf("Merge delle due liste\n");
 display(src3);
}

stru * merge(stru *list1, stru *list2){
 stru * const startpoint=malloc(sizeof(stru));
 stru *prec=startpoint;
 if((list1->c)<(list2->c)){
  startpoint->c=list1->c;
  startpoint->np=NULL;
  list1=list1->np;
 }
 else{
  startpoint->c=list2->c;
  startpoint->np=NULL;
  list2=list2->np;
 }
 while((list1!=NULL)&&(list2!=NULL)){
  stru *tempoint=malloc(sizeof(stru));
  tempoint->np=NULL;
  if((list1->c)<(list2->c)){
   tempoint->c=list1->c;
   list1=list1->np;
  }
  else{
   tempoint->c=list2->c;
   list2=list2->np;
  }

  prec->np=tempoint;
  prec=tempoint;
 }
 if(list1==NULL)
  while(list2!=NULL){
   stru *tempoint=malloc(sizeof(stru));
   tempoint->c=list2->c;
   tempoint->np=NULL;
   list2=list2->np;
   prec->np=tempoint;
   prec=tempoint;
 }
 else
  while(list1!=NULL){
   stru *tempoint=malloc(sizeof(stru));
   tempoint->c=list1->c;
   tempoint->np=NULL;
   list1=list1->np;
   prec->np=tempoint;
   prec=tempoint;
 }
 return startpoint;
}

stru * mergeSort(stru *src){
 stru **A=malloc(sizeof(stru *));
 stru *temp;
 unsigned int count=0,k,i;
 while(src!=NULL){
  A=realloc(A,(count+1)*sizeof(stru *));
  A[count]=src;
  count++;
  temp=src->np;
  src->np=NULL;
  src=temp;
 }
 while(count!=1){
  for(i=0,k=0; i<count-1;){
   A[k++]=merge(A[i],A[i+1]);
   i=i+2;
  }
  if(i==count-1)
   A[k++]=A[i];
  count= !(count%2) ? count/2 : (count/2)+1;
  printf("%d\n",count);

 }
 return A[0];
}