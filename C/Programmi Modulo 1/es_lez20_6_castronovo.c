//Esercizio 6 lezione 20
#include <stdio.h>

void main(){
	unsigned int b,i;
	scanf("%d %d",&b,&i);
	if(!(b>>16)&&(i<=16))
		printf("%d\n",b<<i);
}