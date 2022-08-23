//Esercizio 4 lezione 20
#include <stdio.h>

void main(){
	int a,b,com;
	scanf("%d %d",&a,&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("Scambio dei due interi con la somma %d %d\n",a,b);
	a=(a^b);
	b=a^b;
	a=a^b;
	printf("Scambio dei due interi con xor %d %d\n",a,b);
}