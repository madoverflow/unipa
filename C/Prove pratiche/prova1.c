#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
 int (*fun)(char *s);
 char *s;
 struct node *rightPtr;
 struct node *leftPtr;
}Nodo;

static int countC(char *s);
static int countV(char *s);
static void treeInsert(char **array_str, size_t dim, Nodo **rootPtr, int (*funPtr)(char *s));
static void insert(Nodo **radPtr, Nodo *newPtr);
static void treeDisplay(Nodo *radPtr);
static int treeVisit(Nodo *rootPtr);
static void visit(Nodo *radPtr, int *x);

static int level=0;

void main(){
 Nodo *crootPtr=NULL,*vrootPtr=NULL;
 FILE *fd=fopen("strings.txt","r");
 char **array_str=malloc(sizeof(char *));
 char ch;
 size_t i=0,j=0;
 int cval,vval;
 if(fd==NULL)
  printf("Errore: apertura file\n");
 else{
  while(!feof(fd)){
   fscanf(fd,"%c",&ch);
   array_str[i]=malloc(sizeof(char));
   while(ch!='\n'){
    array_str[i][j]=ch;
    j++;
    array_str[i]=realloc(array_str[i],(j+1)*sizeof(char));
    fscanf(fd,"%c",&ch);
   }
   array_str[i][j]='\0';
   j=0;
   i++;
   array_str=realloc(array_str,(i+1)*sizeof(char *));
  }
  i--;
  free(array_str[i]);
  array_str=realloc(array_str,i*sizeof(char *));
  treeInsert(array_str,i,&crootPtr,&countC);
  treeInsert(array_str,i,&vrootPtr,&countV);
  cval=treeVisit(crootPtr);
  vval=treeVisit(vrootPtr);
  printf("Numero totale vocali nelle stringhe: %d\nNumero totale consonanti nelle stringhe: %d\n",vval,cval);
 }
}

static int countC(char *s){
 int val=0;
 int vocali;
 char *l=s;
 while(*s!='\0'){
  if(((*s)>='A'&&(*s)<='Z')||((*s)>='a'&&(*s)<='z'))
   val++;
  s++;
 }
 vocali=countV(l);
 val=val-vocali;
 return val;
}

static int countV(char *s){
 int val=0;
 while(*s!='\0'){
  if(((*s)=='A')||((*s)=='E')||((*s)=='I')||((*s)=='O')||((*s)=='U')||((*s)=='a')||((*s)=='e')||((*s)=='i')||((*s)=='o')||((*s)=='u'))
   val++;
  s++;
 }
 return val;
}

static void treeInsert(char **array_str, size_t dim, Nodo **rootPtr, int (*funPtr)(char *s)){
 Nodo *newPtr;
 char *token;
 for(size_t i=0; i<dim; i++){
   newPtr=malloc(sizeof(Nodo));
   newPtr->rightPtr=NULL;
   newPtr->leftPtr=NULL;
   newPtr->fun=funPtr;
   newPtr->s=malloc((strlen(array_str[i])+1)*sizeof(char));
   strcpy(newPtr->s,array_str[i]);
   insert(rootPtr,newPtr);
 } 
}

static void insert(Nodo **radPtr, Nodo *newPtr){
 //caso base
 if(*radPtr==NULL)
  *radPtr=newPtr;
 else{
  if(strcmp(newPtr->s,(*radPtr)->s)>0)
   insert(&((*radPtr)->rightPtr),newPtr);
  if(strcmp(newPtr->s,(*radPtr)->s)<0)
   insert(&((*radPtr)->leftPtr),newPtr);
 }
}

static void treeDisplay(Nodo *radPtr){
 if(radPtr!=NULL){
  level++;
  treeDisplay(radPtr->rightPtr);
  printf(">%*s%5s\n",level*5,"", radPtr->s);
  treeDisplay(radPtr->leftPtr);
  level--;
 }
}

static int treeVisit(Nodo *rootPtr){
 int valore=0;
 visit(rootPtr,&valore);
 return valore;
}

static void visit(Nodo *radPtr, int *x){
 if(radPtr!=NULL){
  visit(radPtr->rightPtr,x);
  *x+=(radPtr->fun(radPtr->s));
  visit(radPtr->leftPtr,x);
 }
}

