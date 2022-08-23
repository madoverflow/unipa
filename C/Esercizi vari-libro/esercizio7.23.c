#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void display(char labirinto[][12]);
static void mazeTraverse(char labirinto[][12]);
static void traverse(char labirinto[][12], size_t i, size_t j);
static void mazeGenerator(char labirinto[][12]);
static void generator(char labirinto[][12], size_t i, size_t j);

void main(){
 char labirinto[12][12];
 srand(time(NULL));
 mazeGenerator(labirinto);
 printf("Labirinto generato casualmente\n");
 display(labirinto);
 mazeTraverse(labirinto);
}

static void display(char labirinto[][12]){
 for(size_t i=0; i<12; i++){
  for(size_t j=0; j<12; j++)
   printf(" %c ",labirinto[i][j]);
  printf("\n");
 }
}

static void mazeGenerator(char labirinto[][12]){
 size_t i=0,j=0,comodo;
 for(size_t i=0; i<12; i++)
  for(size_t j=0; j<12; j++)
   labirinto[i][j]='X';
 i=(rand()%10)+1;
 labirinto[i][j]='.';
 labirinto[i][j+1]='.';
 generator(labirinto,i,j+1);
 
 //creazione cancelletti nei 4 lati del quadrato
 
 //primo lato verticale 
 for(i=0,j=0; (i<12)&&labirinto[i][j]!='.'; i++)
  labirinto[i][j]='#';
 for(size_t k=i+1; k<12; k++)
  labirinto[k][j]='#';
 //primo lato orizzontale
 for(i=0,j=0; (j<12)&&labirinto[i][j]!='.'; j++)
  labirinto[i][j]='#';
 for(size_t k=j+1; k<12; k++)
  labirinto[i][k]='#';
 //secondo lato orizzontale
 for(i=11,j=0; j<12; labirinto[i][j]='#',j++);
 //secondo lato verticale
 for(i=0,j=11; (i<12)&&labirinto[i][j]!='.'; i++)
  labirinto[i][j]='#';
 for(size_t k=i+1; k<12; k++)
  labirinto[k][j]='#';
 //fine cancelletti nei 4 lati del quadrato
 
 //riempimento casuale labirinto
 for(i=1; i<11; i++)
  for(j=1; j<11; j++){
   comodo=rand()%2; //1 punto, 0 cancelletto
   if(labirinto[i][j]=='X'){
    if(comodo==1)
     labirinto[i][j]='.';
    else
     labirinto[i][j]='#';
   }
  }
}

static void generator(char labirinto[][12], size_t i, size_t j){
 //caso base
 if(j==11)
  return;
 //chiamata ricorsiva
 size_t comodo;
 comodo=(rand()%3)-1; 
 //1 spostamento a destra, 0 spostamento sopra, -1 spostamento sotto
 if(comodo==1){
  labirinto[i][j+1]='.';
  generator(labirinto,i,j+1);
 }
 if(comodo==0){
  if((i-1>0)&&(labirinto[i-1][j]!='.')){
   labirinto[i-1][j]='.';
   generator(labirinto,i-1,j);
  }
  else{
   labirinto[i][j+1]='.';
   generator(labirinto,i,j+1);
  }
 }
 if(comodo==-1){
  if((i+1<11)&&(labirinto[i+1][j]!='.')){
   labirinto[i+1][j]='.';
   generator(labirinto,i+1,j);
  }
  else{
   labirinto[i][j+1]='.';
   generator(labirinto,i,j+1);
  }
 }
}

static void mazeTraverse(char labirinto[][12]){
 size_t i=0,j=0;
 for(i=0; (i<12)&&(labirinto[i][0]=='#'); i++);
 traverse(labirinto,i,j);
 printf("Percorso labirinto\n");
 display(labirinto);
}

static void traverse(char labirinto[][12], size_t i, size_t j){
 //caso base
 if(j==11){
  labirinto[i][j]='X';
  return;
 }
 //chiamata ricorsiva
 labirinto[i][j]='X';
 if(labirinto[i][j+1]=='.')
  traverse(labirinto,i,j+1);
 else{
  if(labirinto[i-1][j]=='.')
   traverse(labirinto,i-1,j);
  else{
   if(labirinto[i+1][j]=='.')
    traverse(labirinto,i+1,j);
   else
    traverse(labirinto,i,j-1);
  }
 }
}
