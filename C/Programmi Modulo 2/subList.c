//creazione sotto liste a partire da una lista
#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
 int info;
 struct nodo *next;
}Nodo;
typedef struct nodoS{
 struct nodoS *next;
 Nodo *list;
}NodoS;
void menu(Nodo **src);
void insert(Nodo **head, Nodo **till, int val);
void display(Nodo *first);
NodoS *sottoliste(Nodo *l);
size_t counter(const Nodo *ptr);
Nodo *sottolista(Nodo *list, size_t dim, size_t nElement);

void main(){
 Nodo *startPtr=NULL;
 NodoS *sublist;
 menu(&startPtr);
 sublist=sottoliste(startPtr);
 if(sublist==NULL)
  printf("Elementi lista insufficienti\n");
 else{
  printf("Stampa delle sottoliste\n");
  while(sublist!=NULL){
   display(sublist->list);
   sublist=sublist->next;
  }
 }
}

void menu(Nodo **src){
 int choose;
 int temp;
 Nodo *coda=*src;
 do{
  printf("Inserisci:\n1 per inserimento\n2 per stampare\n0 per terminare il menu\n");
  scanf("\n%d",&choose);
  switch (choose){
   case 1:
    printf("Inserisci il valore (intero) da inserire\n");
    scanf("\n%d",&temp);
    insert(src,&coda,temp);
    break;
   case 2:
    display(*src);
    break;
   case 0:
    printf("Menu terminato.\n");
    break;
   default:
    printf("Valore inserito non corretto. Riprova\n");
    break;
  }
 }while(choose);
}

void insert(Nodo **head, Nodo **till, int val){
 Nodo *node=malloc(sizeof(Nodo));
 node->info=val;
 node->next=NULL;
 //lista vuota
 if(*head==NULL){
  *head=node;
  *till=node;
 }
 else{
  (*till)->next=node;
  *till=node;
 }
}

void display(Nodo *first){
 while(first!=NULL){
  printf("%d -> ", first->info);
  first=first->next;
 }
 printf("\n");
}

NodoS *sottoliste(Nodo *l){
 size_t size;
 Nodo *comodo,*startPtr=l;
 NodoS *startsub=NULL,*tillsub=NULL,*nodesub=NULL;
 //dimensione della lista
 size=counter(l);
 //controllo dimensione lista
 if((!size)||(size==1))
  return NULL;
 //riempimento lista delle sottoliste
 for(size_t i=1,dim=size; i<=size; dim=size,l=startPtr,i++){
  while((comodo=sottolista(l,dim,i))!=NULL){
    nodesub=malloc(sizeof(NodoS));
    nodesub->list=comodo;
    nodesub->next=NULL;
  	if(startsub==NULL){
  	 startsub=nodesub;
  	 tillsub=startsub;
  	}
  	else{
     tillsub->next=nodesub;
     tillsub=nodesub;
  	}
  	l=l->next;
  	dim--;
  }
 }
 return startsub;
}

size_t counter(const Nodo *ptr){
 size_t i=0;
 while(ptr!=NULL){
  i++;
  ptr=ptr->next;
 }
 return i;
}

Nodo *sottolista(Nodo *list, size_t dim, size_t nElement){
 Nodo *startPtr=NULL,*till=NULL,*node=NULL;
 //controlli di uscita
 if((list==NULL)||(dim==0))
  return NULL;
 if(nElement>dim)
  return NULL;
 //esecuzione funzione
 startPtr=malloc(sizeof(Nodo));
 startPtr->info=list->info;
 startPtr->next=NULL;
 till=startPtr;
 list=list->next;
 for(size_t j=1; j<nElement; j++){
  node=malloc(sizeof(Nodo));
  node->info=list->info;
  node->next=NULL;
  till->next=node;
  till=node;
  list=list->next;
 }
 return startPtr;
}