#include <stdio.h>
#include "interfaceStackADT.h"

void main(){
 const size_t N=81;
 size_t i=0;
 float a,b;
 char str[N];
 printf("Inserisci un'espressione postfissa di %ld elementi\n",N-1);
 gets(str);
 while(str[i]!='\n'){
 if((str[i]>='0')&&(str[i]<='9'))
  stackPush(str[i]-48);
 if(str[i]=='+')
  stackPush(stackPop()+stackPop());
 if(str[i]=='*')
  stackPush(stackPop()*stackPop());
 if(str[i]==':'){
  a=stackPop();
  b=stackPop();
  stackPush(b/a);
 }
 if(str[i]=='-'){
  a=stackPop();
  b=stackPop();
  stackPush(b-a);
 }
 i++;
 }
 printf("Risultato espressione postfissa -> %3.4f \n",stackPop());
}