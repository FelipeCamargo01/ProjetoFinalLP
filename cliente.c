#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <locale.h>
#include <string.h>

#define MAX_CPF 12

int totalOfClients = 0;

int verifyIfAlreadyExists(char* cpf);
int showReturnOption();
void addInformationsAboutClient(sClient *client);
void initClient();
void allocOneMoreClient();
void printfClientInformations(sClient *client);
sClient *findClientByCPF(char* cpf);
sClient *clients;
sClient *aux;

sClient *newClient() {
    sClient *client;
    client = malloc(sizeof(*client));
    if(!client) {
        printf("Não consegui alocar na memória \n");
        exit(-1);
    }
    return client;
}

void addInformationsAboutClient(sClient *client) {
    cleanScreen();
    char cpf[MAX_CPF];
    int errorReturn;
    printf(":::::::::Informações do cliente::::::::: \n");
    do {
        printf("Digite o cpf (somente números) \n");
        fflush(stdin);
        scanfString(&cpf);
        errorReturn = verifyIfAlreadyExists(cpf);
        if(errorReturn) {
            printf("CPF Já cadastrado \n");
            if(showReturnOption() == 2) {
            free(client);
            chooseOptions();
            }
        }
    }while(errorReturn);
    strcpy(client->cpf, cpf);

    char nome[255];

    cleanScreen();
    printf("Digite o nome \n");
    fflush(stdin);
    scanfString(&nome[0]);
    strcpy(client->name, nome);
}

int showReturnOption() {
    int option;
    printf("Digite 1 para cadastrar outro cpf e 2 para voltar \n");
    scanfInt(&option);
    return option;
}

void initClient() {
    setlocale(LC_ALL, "Portuguese");
    clients = malloc(0 * sizeof(*clients));
}

void allocOneMoreClient() {

    int novoTamanho = totalOfClients + 1;
    sClient *newClients;

    newClients = malloc(novoTamanho * sizeof(newClients));
    if(!newClients)
    {
        printf("Erro na alocacao de memoria!");
        exit(-1);
    }

    for(int i = 0; i < totalOfClients; i++) {
        strcpy (newClients[i].cpf,clients[i].cpf);
        strcpy (newClients[i].name,clients[i].name);
    }

    free(clients);
    clients = newClients;

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
    printf(":::::Mostrando informações do cliente:::::: \n");
    printf("CPF -> ");
    printf("%s \n", client->cpf);
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

sClient *findClientByCPF(char* cpf) {
    for(int index = 0; index < totalOfClients; index++) {
        if (!strcmp(cpf, clients[index].cpf )) {
            return &clients[index];
        }
    }
    return (sClient *) -1;
}

int verifyIfAlreadyExists(char* cpf) {
    for(int index = 0; index < totalOfClients; index++) {
        if (!strcmp(cpf, clients[index].cpf )) {
            return 1;
        }
    }
    return 0;
}
