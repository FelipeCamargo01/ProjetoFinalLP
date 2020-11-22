#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <locale.h>
#include <string.h>

int totalOfClients = 0;

int verifyIfAlreadyExists(int cpf);
void addInformationsAboutClient(sClient *client);
void initClient();
void allocOneMoreClient();
void printfClientInformations(sClient *client);
sClient *findClientByCPF(int cpf);
sClient *clients;
sClient *aux;

sClient *newClient() {
    sClient *client;
    client = malloc(sizeof(*client));
    if(!client) {
        printf("N�o consegui alocar na mem�ria \n");
        exit(-1);
    }
    return client;
}

void addInformationsAboutClient(sClient *client) {
    cleanScreen();
    int cpf;
    int errorReturn;
    printf(":::::::::Informa��es do cliente::::::::: \n");
    do {
        printf("Digite o cpf \n");
        scanfInt(&cpf);
        errorReturn = verifyIfAlreadyExists(cpf);
        if(errorReturn) printf("CPF J� cadastrado \n");
    }while(errorReturn);
    client->cpf = cpf;
    printf("Digite o nome \n");
    scanfString(&client->name);
}

void initClient() {
    setlocale(LC_ALL, "Portuguese");
    clients = malloc(0 * sizeof(*clients));
}

void allocOneMoreClient() {

    realloc(clients, totalOfClients + 1);
    totalOfClients++;
}

void showAllClients() {
    cleanScreen();
    for(int index = 0; index < totalOfClients; index++) {
        printfClientInformations(&clients[index]);
    }
    pauseScreen();
}

void printfClientInformations(sClient *client) {
    printf(":::::Mostrando informa��es do cliente:::::: \n");
    printf("CPF -> ");
    printf("%d \n", client->cpf);
    printf("Nome -> ");
    printf("%s \n", client->name);
}

void addClient() {
    sClient *client  = newClient();
    addInformationsAboutClient(client);
    allocOneMoreClient();
    clients[totalOfClients-1] = *client;
    printf("Cliente adicionado com sucesso! \n");
    pauseScreen();
}

sClient *findClientByCPF(int cpf) {
    for(int index = 0; index < totalOfClients; index++) {
        if(clients[index].cpf == cpf) {
            return &clients[index];
        }
    }
    return (sClient *) -1;
}

int verifyIfAlreadyExists(int cpf) {
    for(int index = 0; index < totalOfClients; index++) {
        if(clients[index].cpf == cpf) {
            return 1;
        }
    }
    return 0;
}