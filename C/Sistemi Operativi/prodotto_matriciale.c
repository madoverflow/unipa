#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 2
#define M 3

int matrix1[N][M]={{1,2,3},{4,5,6}};
int matrix2[M][N]={{7,8},{9,10},{11,12}};
int matrix[N][N];

typedef struct argomenti{
    int riga;
    int colonna;
}argomenti;

void* prodotto(void* args){
    int entrata = 0;
    argomenti* indici = (argomenti*) args;
    int riga = indici->riga;
    int colonna = indici->colonna;
    for(int i=0; i<M; i++){
        entrata += matrix1[riga][i]*matrix2[i][colonna];
    }
    matrix[riga][colonna] = entrata;
}

void main(){
    pthread_t threads[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            argomenti* args = malloc(sizeof(argomenti));
            args->riga = i;
            args->colonna = j;
            pthread_create(&threads[i][j], NULL, prodotto, args);
        }
    printf("Matrice del prodotto matriciale:\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            pthread_join(threads[i][j], NULL);
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}