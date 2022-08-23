#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
 char val;
 struct node *nextPtr;
}Nodo;

static void printList(Nodo *curPtr);

void main(){
 Nodo *topPtr=NULL,*comodoPtr=NULL;
 char ch,*str;
 size_t count=0;
 size_t i=0;
 printf("Inserisci una stringa\n");
 while((ch=getchar())!='\n'){
  if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')){
   comodoPtr=malloc(sizeof(Nodo));
   comodoPtr->val=ch;
   comodoPtr->nextPtr=topPtr;
   topPtr=comodoPtr;
   str=realloc(str,count*sizeof(char));
   str[count]=ch;
   count++;
  }
 }
 str[count]='\0';
 comodoPtr=topPtr;
 puts(str);
 printList(topPtr);
 while(str[i]!='\0'&&str[i]==comodoPtr->val){
  comodoPtr=comodoPtr->nextPtr;
  i++;
 }
 if(str[i]!='\0')
  printf("Stringa non palindroma\n");
 else
  printf("Stringa palindroma\n");
}

static void printList(Nodo *curPtr){
 if(curPtr==NULL)
  printf("\n");
 else{
  printf("%c -> ",curPtr->val);
  curPtr=curPtr->nextPtr;
  printList(curPtr);
 }
}