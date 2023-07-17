#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define N 3

int matrix[N][N] = {{7,2,0},{3,-15,0},{6,-4,2}};
int determinante = 0;
sem_t semaphore;
typedef struct argomenti{
    int riga;
    int colonna;
}argomenti;

void* minore(void* args){
    int minore[4];
    int lock;
    int prodotto;
    argomenti* indici = (argomenti*) args;
    do{
        lock = sem_wait(&semaphore);
    }while(lock != 0);
    for(int i=0,k=0; i<N; i++)
        for(int j=0; j<N; j++)
            if((i != indici->riga) && (j != indici->colonna)){
                minore[k] = matrix[i][j];
                k++;
            }
    prodotto = (minore[0]*minore[3]) - (minore[1]*minore[2]);
    prodotto = matrix[indici->riga][indici->colonna]*prodotto;
    if((indici->riga + indici->colonna) % 2)
        prodotto = -1*prodotto;
    determinante = determinante + prodotto;
    sem_post(&semaphore);
    free(indici);
}

void main()
{
    int riga,colonna;
    pthread_t threads[N];
    sem_init(&semaphore,0,1);
    for(int i=0; i<N; i++){
        argomenti* args = malloc(sizeof(argomenti));
        args -> riga = i;
        args -> colonna = 2;
        pthread_create(&threads[i], NULL, minore, args);
    }
    for(int i=0; i<N; i++)
        pthread_join(threads[i], NULL);
    sem_destroy(&semaphore);
    printf("Determinante: %d\n", determinante);
    
}
