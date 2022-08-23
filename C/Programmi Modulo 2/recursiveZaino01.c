//Problema zaino 0-1 ricorsivo
#include <stdio.h>
typedef struct{
 int valore;
 int peso;
}oggetto;
int zaino(oggetto lista[], int capacità, size_t dim);
int max(int a, int b);
void main(){
 size_t size=4;
 oggetto listaOggetti[]={{3,3},{3,2},{1,1},{1,1}};
 int capacità,valore;
 printf("Inserisci la capacità dello zaino\n");
 scanf("\n%d",&capacità);
 valore=zaino(listaOggetti,capacità,size);
 printf("%d ",valore);
}

int zaino(oggetto lista[], int capacità, size_t dim){
 //casi base
 if((!dim)||(capacità<=0))
  return 0;
 if(lista[dim-1].peso>capacità)
  return zaino(lista,capacità,dim-1);
 //chiamata ricorsiva
 return max(zaino(lista,capacità-lista[dim-1].peso,dim-1)+lista[dim-1].valore,zaino(lista,capacità,dim-1));
}

int max(int a, int b){
 return (a>b) ? a : b;
}