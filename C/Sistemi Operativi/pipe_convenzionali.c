#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

#define INTERVALLO 10

int tube[2];
pthread_t t_client;
pthread_t t_server;

void murder(){
    printf("Sto per killare client e server\n");
    printf("Killo il client...\n");
    pthread_cancel(t_client);
    pthread_detach(t_client);
    printf("Killo il server...\n");
    pthread_cancel(t_server);
    pthread_detach(t_server);
}

void* client(void* args){
    FILE* stream;
    int c;
    stream = fdopen(tube[0], "r");
    printf("Client in ascolto sul server\n");
    sleep(rand()%INTERVALLO);
    while( (c = fgetc(stream)) != EOF){
        putchar(c);
    }
    fclose(stream);
    return NULL;
}

void* server(void* args){
    FILE* stream;
    stream = fdopen(tube[1], "w");
    while(1){
        fprintf(stream, "Server in scrittura\n");
        fflush(stream);
        sleep(rand()%INTERVALLO);
    }
    fclose(stream);
    return NULL;
}

void main(){
    signal(SIGUSR1, murder);
    if(pipe(tube)){
        printf("Errore nella creazione della pipe\n");
        exit(EXIT_FAILURE);
    }
    printf("Creo il client e server\n");
    pthread_create(&t_client, NULL, client, NULL);
    pthread_create(&t_server, NULL, server, NULL);
    pthread_join(t_client, NULL);
    pthread_join(t_server, NULL);
    printf("Processo concluso.\n");
    exit(EXIT_SUCCESS);
}