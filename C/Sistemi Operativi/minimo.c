#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

#define N 2
#define M 3

int matrix[N][M] = {{10,2,3},{4,5,-10}};
int minimum;
pthread_mutex_t mutex;

typedef struct tmpStruct {
	int riga;
	int colonna;
} tmpStruct;

void* fun_thread(void* args){
	tmpStruct* argomenti = (tmpStruct*) args;
	int lock_mutex;
	do{
		lock_mutex = pthread_mutex_trylock(&mutex);
	}while(lock_mutex != 0);
	if(minimum)
		minimum = matrix[argomenti->riga][argomenti->colonna]<minimum ? matrix[argomenti->riga][argomenti->colonna] : minimum;
	else
		minimum = matrix[argomenti->riga][argomenti->colonna];
	pthread_mutex_unlock(&mutex);
}

void killer(){
	printf("Comando killato da terminale\n");
	exit(EXIT_SUCCESS);
}

void main(){
	signal(SIGUSR1, killer);
	pthread_t threads[N*M];
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			tmpStruct* argomenti = malloc(sizeof(tmpStruct));
			argomenti->riga = i;
			argomenti->colonna = j; 
			pthread_create(&threads[i+j], NULL, fun_thread, argomenti);	
		}	
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			pthread_join(threads[i+j], NULL);
		}	
	}
	printf("Minimo della matrice %d\n", minimum);
	printf("Il processo deve essere terminato manualmente col comando kill -SIGUSR1 pid da terminale\n");
	while(1);
}
