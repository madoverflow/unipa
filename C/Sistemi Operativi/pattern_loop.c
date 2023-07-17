#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

#define THREADS_NUMBER 8
#define INTERVAL 10

pthread_t threads[THREADS_NUMBER];

void* carattere(void* arg){
    char* character = (char*) arg;
    printf("%c",*character);
    fflush(stdout);
}

void murder(){
    printf("\nProcesso killato dall'utente.\n");
    for(int i=0; i<THREADS_NUMBER; i++){
        pthread_cancel(threads[i]);
        pthread_detach(threads[i]);
    }
    exit(EXIT_SUCCESS);
}

void main(){
    signal(SIGUSR1, murder);
    char string[]={"abcdedcb"};
    char character;
    while(1){
        for(int i=0; i<THREADS_NUMBER; i++){
            character=string[i];
            pthread_create(&threads[i], NULL, carattere, &character);
            pthread_join(threads[i], NULL);
        }
        sleep(rand()%INTERVAL);
    }
}