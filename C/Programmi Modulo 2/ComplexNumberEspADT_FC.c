#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "interfaceComplexNumberADT_FC.h"

typedef struct complex{
 double modulo;
 double fase;
}Complex;

//constructor
ComplexPtr init(double a, double b){
 ComplexPtr obj=malloc(sizeof(Complex));
 if(obj==NULL){
  printf("Spazio nell'heap insufficiente.\n");
  return NULL;
 }
 else{
  obj->modulo=a;
  obj->fase=b;
  return obj;
 }
}

//destructor
void destroy(const ComplexPtr comodo){
 free(comodo);
}

void display(const ComplexPtr const number){
 double a,b;
 a=(number->modulo)*cos(number->fase);
 b=(number->modulo)*sin(number->fase);
 printf("Numero complesso: %3.2f+i%3.2f\n",a,b);
}

ComplexPtr add(ComplexPtr x, ComplexPtr y){
 ComplexPtr obj=malloc(sizeof(Complex));
 double a,b;
 if(obj==NULL){
  printf("Spazio nell'heap insufficiente.\n");
  return NULL;
 }
 else{
  a=(x->modulo*cos(x->fase))+(y->modulo*cos(y->fase));
  b=(x->modulo*sin(x->fase))+(y->modulo*sin(y->fase));
  obj->modulo=sqrt((a*a)+(b*b));
  if((!a)&&(!b)){
   //valore non valido
   obj->fase=0;
   return obj;
  }
  if((!a)&&b){
   if(b>0)
    obj->fase=M_PI/2;
   else
    obj->fase=-1*(M_PI/2);
   return obj;
  }
  if(a>0)
   obj->fase=atan(b/a);
  else{
   if(b>=0)
    obj->fase=atan(b/a)+M_PI;
   else
    obj->fase=atan(b/a)-M_PI;
  }
  return obj;
 }
}

ComplexPtr sub(ComplexPtr x, ComplexPtr y){
 ComplexPtr obj=malloc(sizeof(Complex));
 double a,b;
 if(obj==NULL){
  printf("Spazio nell'heap insufficiente.\n");
  return NULL;
 }
 else{
  a=(x->modulo*cos(x->fase))-(y->modulo*cos(y->fase));
  b=(x->modulo*sin(x->fase))-(y->modulo*sin(y->fase));
  obj->modulo=sqrt((a*a)+(b*b));
  if((!a)&&(!b)){
   //valore non valido
   obj->fase=0;
   return obj;
  }
  if((!a)&&b){
   if(b>0)
    obj->fase=M_PI/2;
   else
    obj->fase=-1*(M_PI/2);
   return obj;
  }
  if(a>0)
   obj->fase=atan(b/a);
  else{
   if(b>=0)
    obj->fase=atan(b/a)+M_PI;
   else
    obj->fase=atan(b/a)-M_PI;
  }
  return obj;
 }
}

ComplexPtr prod(ComplexPtr x, ComplexPtr y){
 ComplexPtr obj=malloc(sizeof(Complex));
 if(obj==NULL){
  printf("Spazio nell'heap insufficiente.\n");
  return NULL;
 }
 else{
  obj->modulo=(x->modulo)*(y->modulo);
  obj->fase=(x->fase)+(y->fase);
  return obj;
 }
}

ComplexPtr cdiv(ComplexPtr x, ComplexPtr y){
 ComplexPtr obj=malloc(sizeof(Complex));
 if(obj==NULL){
  printf("Spazio nell'heap insufficiente.\n");
  return NULL;
 }
 else{
  obj->modulo=(x->modulo)/(y->modulo);
  obj->fase=(x->fase)-(y->fase);
  return obj;
 }
}

void nrad(size_t N){
 double theta,a,b;
 for(int k=0; k<N; k++){
  theta=(2*k);
  a=cos(theta);
  b=sin(theta);
  printf("La radice %d-esima dell'unità e': %3.2f+i%3.2f\n",k+1,a,b);
 }
}