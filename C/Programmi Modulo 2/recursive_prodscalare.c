//prodotto scalare ricorsivo

#include <stdio.h>
size_t prodscal(int v[], int v1[], size_t pos);

void main(){
 int v[3]={1,3,2},v1[3]={1,1,1};
 printf("Prodotto scalare: %d",prodscal(v,v1,2));
}

size_t prodscal(int v[], int v1[], size_t pos){
 if(!pos)
  return v[0]*v1[0];
 else
  return v[0]*v1[0]+prodscal(&v[1],&v1[1],pos-1);
}

