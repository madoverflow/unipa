//Esercizio 5 lezione 20
#include <stdio.h>

void main(){
	int a,b,c;
	scanf("%d %d",&a,&b);
	if(b>a){
		a=a+b;
		b=a-b;
		a=a-b;
	}
	printf("%d",(b*b)==a||(b*b*b)==a);
}
