#include <stdio.h>

void main(){
 size_t flag,val;
 char lettere[10][3]={{'0','0','0'},{'0','0','0'},{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};
 char number[8],str[8];
 FILE *fd=fopen("numbers.dat","wb+");
 printf("Inserisci un numero di 7 cifre cui ciascuna cifra sia compresa tra 2 e 9\n");
 gets(number);
 for(int a=0; a<3; a++)
  for(int b=0; b<3; b++)
   for(int c=0; c<3; c++)
    for(int d=0; d<3; d++)
     for(int e=0; e<3; e++)
	  for(int f=0; f<3; f++)
	   for(int g=0; g<3; g++){
	    str[0]=lettere[number[0]-48][a];
		str[1]=lettere[number[1]-48][b];
		str[2]=lettere[number[2]-48][c];
		str[3]=lettere[number[3]-48][d];
		str[4]=lettere[number[4]-48][e];
		str[5]=lettere[number[5]-48][f];
		str[6]=lettere[number[6]-48][g];
		str[7]='\0';
		fwrite(str,8*sizeof(char),1,fd);
	   }
 fseek(fd,0,SEEK_END);
 val=ftell(fd)/(8*sizeof(char));
 fseek(fd,0,SEEK_SET);
 printf("Generatore di parole\n");
 for(int i=0; i<val; i++){
  fread(str,8*sizeof(char),1,fd);
  puts(str);
 }
}