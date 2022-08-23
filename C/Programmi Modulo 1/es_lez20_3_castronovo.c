//Esercizio 3 lezione 20
#include <stdio.h>
#include <math.h>

void main(){
	int a,b,c;
	float delta;
	scanf("%d %d %d",&a,&b,&c);
	delta=(b*b)-(4*a*c);
	if (a)
		if (delta>=0)
			printf("Prima soluzione %f seconda soluzione %f",((-1*b)+sqrt(delta))/2*a,((-1*b)-sqrt(delta))/2*a);
			
}