#include <stdio.h>
#include <stdlib.h>

typedef struct employee{
 char name[10];
 char surname[20];
 size_t age;
 size_t idcount;
}Em;

void main(){
 FILE *fd;
 size_t flag=1,dim;
 size_t SIZE=sizeof(Em);
 Em client,*Emp;
 fd=fopen("employees.bin","w+b");
 do{
  printf("Inserisci Nome, Cognome, Età, Conto bancario dell'impiegato\n");
  getchar();
  gets(client.name);
  gets(client.surname);
  scanf("\n%ld %ld",&client.age,&client.idcount);
  fwrite(&client,SIZE,1,fd);
  printf("Inserisci 0 per fermare l'inserimento oppure qualunque numero per continuare\n");
  scanf("\n%ld",&flag);
 }while(flag);
 puts(client.name);
 puts(client.surname);
 printf("%ld %ld\n",client.age, client.idcount);
 dim=ftell(fd)/SIZE;
 printf("%ld",dim);
 Emp=realloc(Emp,dim*sizeof(Em));
 fseek(fd,0,SEEK_SET);
 fread(Emp,SIZE,dim,fd);
 for(int i=0; i<dim; i++){
  puts((Emp[i]).name);
  puts((Emp[i]).surname);
  printf("%ld\n",(Emp[i]).age);
  printf("%ld\n",(Emp[i]).idcount);
 }
 fclose(fd);

}