#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "interfaceLCRSADT.h"

void main(){
 srand(time(NULL));
 lcrsInit();
 for(int i=0; i<10; i++)
  lcrsInsert(rand()%100);
 lcrsPrint();
 lcrsToBst();
 bstPrint();
}