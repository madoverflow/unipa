#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
 char lastName[15];
 char firstName[15];
 char age[4];
}Person;

static size_t display(FILE *fd);

void main(){
 FILE *fd=fopen("nameage.dat","wb+");
 size_t record,rows;
 Person *generalPtr=malloc(sizeof(Person));
 strcpy(generalPtr->lastName,"unassigned");
 strcpy(generalPtr->firstName,"");
 strcpy(generalPtr->age,"0");
 for(int i=0; i<100; fwrite(generalPtr, sizeof(Person), 1, fd),i++);
 for(int i=0; i<10; i++){
  printf("Inserisci il cognome della persona\n");
  gets(generalPtr->lastName);
  printf("Inserisci il nome della persona\n");
  gets(generalPtr->firstName);
  printf("Inserisci l'eta' della persona\n");
  gets(generalPtr->age);
  fwrite(generalPtr, sizeof(Person), 1, fd);
 }
 printf("Contenuto del file nameage.dat\n");
 rows=display(fd);
 printf("Inserisci il numero del record da aggiornare\n");
 scanf("%ld",&record);
 if(record>rows)
  printf("Il record %d non e' stato trovato\n");
 else{
  printf("Inserisci il cognome della persona\n");
  getchar();
  gets(generalPtr->lastName);
  printf("Inserisci il nome della persona\n");
  gets(generalPtr->firstName);
  printf("Inserisci l'eta' della persona\n");
  gets(generalPtr->age);
  fseek(fd,record*sizeof(Person),SEEK_SET);
  fwrite(generalPtr,sizeof(Person),1,fd);
 }
 printf("Contenuto del file nameage.dat aggiornato\n");
 display(fd);
 fclose(fd);
}

static size_t display(FILE *fd){
 Person *comodoPtr=malloc(sizeof(Person));
 size_t val;
 fseek(fd,0,SEEK_END);
 val=ftell(fd)/sizeof(Person);
 fseek(fd,0,SEEK_SET);
 printf("%d",val);
 for(int i=0; i<val; i++){
  fread(comodoPtr,sizeof(Person),1,fd);
  printf("%s %s %s\n",comodoPtr->lastName,comodoPtr->firstName,comodoPtr->age);
 }
 free(comodoPtr);
 comodoPtr=NULL;
 fseek(fd,0,SEEK_SET);
 return val;
}