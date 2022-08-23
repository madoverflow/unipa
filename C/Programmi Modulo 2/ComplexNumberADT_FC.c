#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "interfaceComplexNumberADT_FC.h"

typedef struct complex{
 double re;
 double im;
}Complex;

//constructor
ComplexPtr init(double a, double b){
 ComplexPtr obj=malloc(sizeof(Complex));
 if(obj==NULL){
  printf("Spazio nell'heap insufficiente.\n");
  return NULL;
 }
 else{
  obj->re=a;
  obj->im=b;
  return obj;
 }
}

//destructor
void destroy(const ComplexPtr comodo){
 free(comodo);
}

void display(const ComplexPtr const number){
 printf("Numero complesso: %3.2f+i%3.2f\n",number->re,number->im);
}

ComplexPtr add(ComplexPtr x, ComplexPtr y){
 ComplexPtr obj=malloc(sizeof(Complex));
 if(obj==NULL){
  printf("Spazio nell'heap insufficiente.\n");
  return NULL;
 }
 else{
  obj->re=(x->re)+(y->re);
  obj->im=(x->im)+(y->im);
  return obj;
 }
}

ComplexPtr sub(ComplexPtr x, ComplexPtr y){
 ComplexPtr obj=malloc(sizeof(Complex));
 if(obj==NULL){
  printf("Spazio nell'heap insufficiente.\n");
  return NULL;
 }
 else{
  obj->re=(x->re)-(y->re);
  obj->im=(x->im)-(y->im);
  return obj;
 }
}

ComplexPtr prod(ComplexPtr x, ComplexPtr y){
 ComplexPtr obj=malloc(sizeof(Complex));
 double a,b,c,d;
 if(obj==NULL){
  printf("Spazio nell'heap insufficiente.\n");
  return NULL;
 }
 else{
  a=x->re;
  b=x->im;
  c=y->re;
  d=y->im;
  obj->re=(a*c)-(b*c);
  obj->im=(a*d)+(b*c);
  return obj;
 }
}

ComplexPtr cdiv(ComplexPtr x, ComplexPtr y){
 ComplexPtr obj=malloc(sizeof(Complex));
 double a,b,c,d;
 if(obj==NULL){
  printf("Spazio nell'heap insufficiente.\n");
  return NULL;
 }
 else{
  a=x->re;
  b=x->im;
  c=y->re;
  d=y->im;
  obj->re=((a*c)+(b*d))/((c*c)+(d*d));
  obj->im=((b*c)-(a*d))/((c*c)+(d*d));
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