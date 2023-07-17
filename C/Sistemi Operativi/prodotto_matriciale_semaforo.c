#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define N 2
#define M 3

int matrix1[N][M]={{1,2,3},{4,5,6}};
int matrix2[M][N]={{7,8},{9,10},{11,12}};
int matrix[N][N]={{0,0},{0,0}};
sem_t semaphore[N][N];

typedef struct argomenti{
    int riga;
    int colonna;
}argomenti;

typedef struct argomentiEntrate{
    int entrata1;
    int entrata2;
    int riga;
    int colonna;
}argomentiEntrate;

void* entrata(void *args){
    argomentiEntrate* entrate = (argomentiEntrate*) args;
    int lock;
    int riga = entrate->riga;
    int colonna = entrate->colonna;
    int entrata1 = entrate->entrata1;
    int entrata2 = entrate->entrata2;
    do{
        lock = sem_wait(&semaphore[riga][colonna]);
    }while(lock != 0);
    matrix[riga][colonna] += (entrate->entrata1)*(entrate->entrata2);
    sem_post(&semaphore[riga][colonna]);
    free(entrate);
}

void* prodotto(void* args){
    argomenti* indici = (argomenti*) args;
    int riga = indici->riga;
    int colonna = indici->colonna;
    pthread_t threads_entrate[M];
    for(int i=0; i<M; i++){
        argomentiEntrate* args = malloc(sizeof(argomentiEntrate));
        args->entrata1 = matrix1[riga][i];
        args->entrata2 = matrix2[i][colonna];
        args->riga = riga;
        args->colonna = colonna;
        pthread_create(&threads_entrate[i], NULL, entrata, args);
    }
    for(int i=0; i<M; i++)
        pthread_join(threads_entrate[i], NULL);
    free(indici);
}

void main(){
    pthread_t threads[N][N];
    for(int k=0; k<N*N; k++)
        sem_init(&semaphore[k/N][k%N], 0, 1);
    for(int k=0; k<N*N; k++){
        argomenti* args = malloc(sizeof(argomenti));
        args->riga = k/N;
        args->colonna = k%N;
        pthread_create(&threads[k/N][k%N], NULL, prodotto, args);
    }
    printf("Matrice del prodotto matriciale:\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            pthread_join(threads[i][j], NULL);
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for(int k=0; k<N*N; k++)
        sem_destroy(&semaphore[k/N][k%N]);
}