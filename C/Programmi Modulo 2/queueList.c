#include <stdio.h>
#include <stdlib.h>
struct node{
 char lettera;
 struct node *nextPtr;
};
typedef struct node Nodo;
void menu(Nodo **top, Nodo **till);
void enqueue(Nodo **top, Nodo **til, const char l);
void dequeue(Nodo **head, Nodo **till);
void printQueue(const Nodo *list);

void main(){
 Nodo *top=NULL;
 Nodo *till=top;
 menu(&top, &till);
}

void menu(Nodo **top, Nodo **till){
 int choose;
 char temp;
 do{
  printf("Inserisci: \n1 funzione enqueue\n2 funzione dequeue\n3 stampa della coda\n0 per terminare\n");
  scanf("\n%d",&choose);
  switch (choose){
   case 1:
    printf("Inserisci il carattere da inserire nella coda\n");
    scanf("\n%c",&temp);
    enqueue(top,till,temp);
    break;
   case 2:
    dequeue(top,till);
    break;
   case 3:
    if(*top==NULL)
     printf("Coda vuota\n");
    else{
     printf("Stampa della coda\n");
     printQueue(*top);
     printf("\n");
    }
    break;
   case 0:
    printf("Menu terminato.\n");
    break;
   default:
    printf("Hai sbagliato ad inserire il valore. Riprova.\n");
    break;
  }
 }while(choose);
}

void enqueue(Nodo **top, Nodo **till, const char l){
 Nodo *node=malloc(sizeof(Nodo));
 node->lettera=l;
 node->nextPtr=NULL;
 //coda vuota
 if(*top==NULL){
  *top=node;
  *till=node;
 }
 else{
  (*till)->nextPtr=node;
  *till=node;
 }
}

void dequeue(Nodo **head, Nodo **till){
 Nodo *temp;
 //coda vuota
 if(*head==NULL){
  *till=*head;
  printf("Coda vuota\n");
 }
 else{
  temp=(*head)->nextPtr;
  (*head)->nextPtr=NULL;
  printf("Lettera estratta dallo stack: %c\n",(*head)->lettera);
  free(*head);
  *head=temp;
 }
}

void printQueue(const Nodo *list){
 //caso base
 if(list!=NULL){
  printf(" -> %c",list->lettera);
  list=list->nextPtr;
  //chiamata ricorsiva
  printQueue(list);
 }
}