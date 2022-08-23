#include <stdio.h>
static void display(char labirinto[][12]);
static void mazeTraverse(char labirinto[][12]);
static void traverse(char labirinto[][12], size_t i, size_t j);

void main(){
 char labirinto[12][12]={'#','#','#','#','#','#','#','#','#','#','#','#',
                         '#','.','.','.','#','.','.','.','.','.','.','#',
                         '.','.','#','.','#','.','#','#','#','#','.','#',
                         '#','#','#','.','#','.','.','.','.','#','.','#',
                         '#','.','.','.','.','#','#','#','.','#','.','.',
                         '#','#','#','#','.','#','.','#','.','#','.','#',
                         '#','.','.','#','.','#','.','#','.','#','.','#',
                         '#','#','.','#','.','#','.','#','.','#','.','#',
                         '#','.','.','.','.','.','.','.','.','#','.','#',
                         '#','#','#','#','#','#','.','#','#','#','.','#',
                         '#','.','.','.','.','.','.','#','.','.','.','#',
                         '#','#','#','#','#','#','#','#','#','#','#','#',};
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
  if(labirinto[i+1][j]=='.')
   traverse(labirinto,i+1,j);
  else{
   if(labirinto[i-1][j]=='.')
    traverse(labirinto,i-1,j);
   else
    traverse(labirinto,i,j-1);
  }
 }
}
