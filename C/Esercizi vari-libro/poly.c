#include <stdio.h>
#include <stdlib.h>
#include "interfacePoly.h"

void main(){
 Poly p1,p2,p3;
 p1=polyInit(0,1);
 p2=polyInit(1,1);
 p1=sum(p1,p2);
 p2=polyInit(2,1);
 p1=sum(p1,p2);
 printPoly(p1);
 p2=polyInit(0,-1);
 p3=polyInit(1,1);
 p2=sum(p2,p3);
 printPoly(p2);
 p3=mul(p1,p2);
 printPoly(p3);
 horner(p3,-1);
}
