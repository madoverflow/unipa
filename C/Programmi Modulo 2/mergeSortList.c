//mergesort top-down per le liste
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
 int info;
 struct node *nextPtr;
}Nodo;
void display(Nodo *first);
void insert(Nodo **head, Nodo **till, size_t val);
Nodo *merge(Nodo *list1, Nodo *list2);
void mergesort(Nodo **src);
void pulizia(Nodo *lista);

void main(){
 size_t nNodi;
 size_t temp;
 Nodo *top=NULL,*till=NULL;
 printf("Quanti nodi deve avere la lista?\n");
 scanf("\n%d",&nNodi);
 printf("Generazione lista di %d nodi con valori random\n");
 for(size_t i=0; i<nNodi; i++){
  temp=rand() %100 + 1;
  insert(&top,&till,temp);
 }
 display(top);
 mergesort(&top);
 display(top);
}

void display(Nodo *first){
 while(first!=NULL){
  printf("%d -> ", first->info);
  first=first->nextPtr;
 }
 printf("\n");
}
void insert(Nodo **head, Nodo **till, size_t val){
 Nodo *comodo=malloc(sizeof(Nodo));
 //controllo memoria heap
 if(comodo==NULL)
  printf("Memoria nell'heap insufficiente\n");
 else{
  comodo->info=val;
  comodo->nextPtr=NULL;
  //lista vuota
  if(*head==NULL)
   *head=comodo;
  else
   (*till)->nextPtr=comodo;
  *till=comodo;
 }
}
void mergesort(Nodo **src){
 Nodo *a=*src,*b=*src,*c=*src,*comodo;
 //casi base
 if((a==NULL) ||(a->nextPtr==NULL))
  return;
 else{
  b=c->nextPtr;
  while((b!=NULL) && (b->nextPtr!=NULL)){
   c=c->nextPtr;
   b=b->nextPtr->nextPtr;
  }
  b=c->nextPtr;
  c->nextPtr=NULL;
  mergesort(&a);
  mergesort(&b);
  *src=merge(a,b);
 }
}

Nodo *merge(Nodo *list1, Nodo *list2){
 Nodo * const startpoint=malloc(sizeof(Nodo));
 Nodo *prec=startpoint;
 Nodo *l1=list1,*l2=list2;
 if((list1->info)<(list2->info)){
  startpoint->info=list1->info;
  startpoint->nextPtr=NULL;
  list1=list1->nextPtr;
 }
 else{
  startpoint->info=list2->info;
  startpoint->nextPtr=NULL;
  list2=list2->nextPtr;
 }
 while((list1!=NULL)&&(list2!=NULL)){
  Nodo *tempoint=malloc(sizeof(Nodo));
  tempoint->nextPtr=NULL;
  if((list1->info)<(list2->info)){
   tempoint->info=list1->info;
   list1=list1->nextPtr;
  }
  else{
   tempoint->info=list2->info;
   list2=list2->nextPtr;
  }

  prec->nextPtr=tempoint;
  prec=tempoint;
 }
 if(list1==NULL)
  while(list2!=NULL){
   Nodo *tempoint=malloc(sizeof(Nodo));
   tempoint->info=list2->info;
   tempoint->nextPtr=NULL;
   list2=list2->nextPtr;
   prec->nextPtr=tempoint;
   prec=tempoint;
 }
 else
  while(list1!=NULL){
   Nodo *tempoint=malloc(sizeof(Nodo));
   tempoint->info=list1->info;
   tempoint->nextPtr=NULL;
   list1=list1->nextPtr;
   prec->nextPtr=tempoint;
   prec=tempoint;
 }
 pulizia(l1);
 pulizia(l2);
 return startpoint;
}

void pulizia(Nodo *lista){
 //caso base
 if(lista==NULL)
  return;
 else{
  //chiamata ricorsiva
  pulizia(lista->nextPtr);
  free(lista);
 }
}