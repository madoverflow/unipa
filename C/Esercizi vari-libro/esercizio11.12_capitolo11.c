#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hardware{
 size_t record;
 char attrezzo[40];
 size_t ammount;
 float price;
}Hardware;

static size_t display(FILE *fd);

void main(){
 FILE *fd=fopen("hardware.dat","wb+");
 size_t val,record;
 int choose,choose2;
 Hardware *generalPtr=malloc(sizeof(Hardware));
 Hardware *comodoPtr;
 strcpy(generalPtr->attrezzo,"Mancante");
 generalPtr->ammount=0;
 generalPtr->price=0.0;
 for(int i=1; i<=100; i++){
  generalPtr->record=i;
  fwrite(generalPtr,sizeof(Hardware),1,fd);
 }
 printf("File attrezzi in magazzino\n");
 display(fd);
 do{
  printf("Insersci:\n1 inserire un nuovo attrezzo\n2 cancellare un attrezzo\n3 aggiornare un attrezzo\n");
  scanf("%d",&choose);
  switch(choose){
   case 1:
    fseek(fd,0,SEEK_END);
	val=ftell(fd)/sizeof(Hardware);
    comodoPtr=malloc(sizeof(Hardware));
	comodoPtr->record=val+1;
	printf("Inserisci il nome dell'oggetto (massimo 39 caratteri)\n");
	getchar();
	gets(comodoPtr->attrezzo);
	printf("Inserisci la quantita' dell'oggetto\n");
	scanf("%ld",&(comodoPtr->ammount));
	printf("Inserisci il costo dell'oggetto\n");
	scanf("%f",&(comodoPtr->price));
	fwrite(comodoPtr,sizeof(Hardware),1,fd);
	printf("File magazzino aggiornato\n");
	display(fd);
    break;
  case 2:
   printf("Inserisci il numero dell'oggetto da cancellare\n");
   scanf("%ld",&record);
   fseek(fd,0,SEEK_END);
   val=ftell(fd)/sizeof(Hardware);
   if(record>val)
    printf("L'oggetto non e' stato trovato. Impossibile eseguire la cancellazione.\n");
   else{
	generalPtr->record=record;
    fseek(fd,(record-1)*sizeof(Hardware),SEEK_SET);
	fwrite(generalPtr,sizeof(Hardware),1,fd);
	printf("File magazzino aggiornato\n");
	display(fd);
   }
   break;
  case 3:
   printf("Inserisci il numero dell'oggetto da aggiornare\n");
   scanf("%ld",&record);
   fseek(fd,0,SEEK_END);
   val=ftell(fd)/sizeof(Hardware);
   if(record>val)
	printf("L'oggetto non e' stato trovato\n");
   else{
	 comodoPtr=malloc(sizeof(Hardware));
	 fseek(fd,(record-1)*sizeof(Hardware),SEEK_SET);
	 fread(comodoPtr,sizeof(Hardware),1,fd);
	 do{
	  printf("Quale informazione dell'oggetto vuoi modificare?");
	  printf("\n1 il nome\n2 la quantita'\n3 il costo\n4 tutte\n");
	  scanf("%ld",&choose2);
	  switch(choose2){
	   case 1:
	    printf("Inserisci il nome dell'oggetto\n");
		getchar();
		gets(comodoPtr->attrezzo);
		fseek(fd,(record-1)*sizeof(Hardware),SEEK_SET);
		fwrite(comodoPtr,sizeof(Hardware),1,fd);
		printf("File magazzino aggiornato\n");
		display(fd);
		choose2=0;
	    break;
	   case 2:
	   	printf("Inserisci la quantita' dell'oggetto\n");
		scanf("%ld",&(comodoPtr->ammount));
		fseek(fd,(record-1)*sizeof(Hardware),SEEK_SET);
		fwrite(comodoPtr,sizeof(Hardware),1,fd);
		printf("File magazzino aggiornato\n");
		display(fd);
		choose2=0;
	    break;
	   case 3:
	    printf("Inserisci il prezzo dell'oggetto\n");
		scanf("%f",&(comodoPtr->price));
		fseek(fd,(record-1)*sizeof(Hardware),SEEK_SET);
		fwrite(comodoPtr,sizeof(Hardware),1,fd);
		printf("File magazzino aggiornato\n");
		display(fd);
		choose2=0;
		break;
	   case 4:
	   	printf("Inserisci il nome dell'oggetto\n");
		getchar();
		gets(comodoPtr->attrezzo);
	    printf("Inserisci la quantita' dell'oggetto\n");
		scanf("%ld",&(comodoPtr->ammount));
	    printf("Inserisci il prezzo dell'oggetto\n");
		scanf("%f",&(comodoPtr->price));
		fseek(fd,(record-1)*sizeof(Hardware),SEEK_SET);
		fwrite(comodoPtr,sizeof(Hardware),1,fd);
		printf("File magazzino aggiornato\n");
		display(fd);
		choose2=0;
	    break;
	   default:
	    printf("Valore inserito non corretto. Riprovare\n");
		choose2=1;
	    break;
	  }
	 }while(choose2);
   }
   break;
  }
 }while(choose);
}

static size_t display(FILE *fd){
 size_t val;
 Hardware *comodoPtr=malloc(sizeof(Hardware));
 fseek(fd,0,SEEK_END);
 val=ftell(fd)/sizeof(Hardware);
 fseek(fd,0,SEEK_SET);
 for(int i=0; i<val; i++){
  fread(comodoPtr,sizeof(Hardware),1,fd);
  printf("%ld %s %ld %3.4f\n",comodoPtr->record,comodoPtr->attrezzo,comodoPtr->ammount,comodoPtr->price);
 }
 free(comodoPtr);
 fseek(fd,0,SEEK_SET);
 return val;
}