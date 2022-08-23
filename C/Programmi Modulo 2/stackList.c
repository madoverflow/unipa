//stack realizzato con le liste concatenate
#include <stdio.h>
#include <stdlib.h>
struct node{
 char lettera;
 struct node *nextPtr;
};
typedef struct node Nodo;
void menu(Nodo **head);
void push(Nodo **head, const char l);
void printStack(const Nodo *list);
void pop(Nodo **head);


void main(){
 Nodo *top=NULL;
 menu(&top);
}

void menu(Nodo **head){
 int choose;
 char temp;
 do{
  printf("Inserisci: \n1 funzione push\n2 funzione pop\n3 stampa dello stack\n0 per terminare\n");
  scanf("\n%d",&choose);
  switch (choose){
   case 1:
    printf("Inserisci il carattere da inserire nello stack\n");
    scanf("\n%c",&temp);
    push(head,temp);
    break;
   case 2:
    pop(head);
    break;
   case 3:
    if(*head==NULL)
     printf("Stack vuoto\n");
    else{
     printf("Stampa dello stack\n");
     printStack(*head);
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

void push(Nodo **head, const char l){
 Nodo *node=malloc(sizeof(Nodo));
 //malloc fallita
 if(node==NULL)
  printf("Memoria insufficiente nell'heap\n");
 else{
  node->lettera=l;
  //lista vuota
  if(*head==NULL){
   node->nextPtr=NULL;
   *head=node;
  }
  //lista non vuota
  else{
   node->nextPtr=*head;
   *head=node;
  }
 }
}

void printStack(const Nodo *list){
 //caso base
 if(list!=NULL){
  printf(" -> %c",list->lettera);
  list=list->nextPtr;
  //chiamata ricorsiva
  printStack(list);
 }
}

void pop(Nodo **head){
 Nodo *temp;
 //lista vuota
 if(*head==NULL)
  printf("Stack vuoto\n");
 else{
  temp=(*head)->nextPtr;
  (*head)->nextPtr=NULL;
  printf("Lettera estratta dallo stack: %c\n",(*head)->lettera);
  free(*head);
  *head=temp;
 }
}