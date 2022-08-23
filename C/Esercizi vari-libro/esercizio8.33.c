#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct assegno{
 char assegno[10];
 char impiegato[40];
}A;

static void display(FILE *fd);
static void printProtezione(const A employee);

void main(){
 int choose;
 size_t dim;
 FILE *fd=fopen("importi.dat","wb+");
 A employee;
 do{
  printf("Inserisci:\n1 per inserire un assegno\n2 per stampare gli assegni totali\n3 stampa importi protetti\n0 per terminare\n");
  scanf("%d",&choose);
  switch(choose){
   case 1:
    printf("Inserisci l'importo dell'assegno. Massimo 9 caratteri\n");
    getchar();
    gets(employee.assegno);
    printf("Inserisci il nome e cognome dell'impiegato.\n");
    gets(employee.impiegato);
    fseek(fd,0,SEEK_END);
    fwrite(&employee,sizeof(A),1,fd);
    break;
   case 2:
    display(fd);
    break;
   case 3:
    fseek(fd,0,SEEK_END);
    dim=ftell(fd)/sizeof(A);
    fseek(fd,0,SEEK_SET);
    for(int i=0; i<dim; i++){
     fread(&employee,sizeof(A),1,fd);
     printProtezione(employee);
    }
    fseek(fd,0,SEEK_SET);
    break;
   case 0:
    printf("Menu terminato\n");
    break;
   default:
    printf("Valore inserito non corretto\n");
    break;
  }
 }while(choose);
}

static void display(FILE *fd){
 size_t N;
 A employee;
 fseek(fd,0,SEEK_END);
 N=ftell(fd)/sizeof(A);
 fseek(fd,0,SEEK_SET);
 for(int i=0; i<N; i++){
  fread(&employee,sizeof(A),1,fd);
  printf("Impiegato -> %s, importo -> %s\n",employee.impiegato,employee.assegno);
 }
 fseek(fd,0,SEEK_SET);
}

static void printProtezione(const A employee){
 size_t size=strlen(employee.assegno);
 printf("Impiegato -> %s, assegno protetto -> ",employee.impiegato);
 for(int i=9-size; i>0; printf("*"),i--);
 printf("%s\n",employee.assegno);
}
