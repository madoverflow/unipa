//Esercizio 7 lezione 20
#include <stdio.h>

void main(){
	unsigned int b,i;
	scanf("%d %d",&b,&i);
	if(((b>>31)<=1)&&(i<=31))
		printf("%d",b>>i);
}