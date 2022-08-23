#include <stdio.h>
#include "interfacePolyADT_FC.h"

void main(){
 Poly p1,p2,p3,q1,q2,pSum,pMult;
 p1=term(3,2);
 p2=term(2,1);
 p3=term(1,0);
 show(p1);
 show(p2);
 show(p3);
 /*q1=add(p1,p2);
 q1=add(q1,p3);
 p1=term(1,1);
 p2=term(3,0);
 q2=add(p1,p2);
 show(q1);
 show(q2);
 pMult=mult(q1,q2);
 show(pMult);
 printf("%f\n",eval(q2,3));*/
}