#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <locale.h>

int totalOfAccounts = 0;

sAccount *accounts;

void printfAccountInformations(sAccount *account);
void addInformationsAboutAccount(sAccount *account);
void printfFindAccountMessages(sClient *client);
void allocOneMoreAccount();
sClient *findAnClient();
sAccount *findTheAccount(sClient *client);

struct Account {
    int numeroDaConta;
    sClient *client;
    float balance;
};

void initAccount() {
    setlocale(LC_ALL, "Portuguese");
    accounts = malloc(0 * sizeof(*accounts));
}

void addAccount() {
    sAccount *account  = newAccount();
    addInformationsAboutAccount(account);
    allocOneMoreAccount();
    accounts[totalOfAccounts-1] = *account;
    printf("Conta adicionada com sucesso! \n");
    pauseScreen();
}

void addInformationsAboutAccount(sAccount *account) {
    cleanScreen();
    sClient *client;
    printf(":::::::::Informações da conta::::::::: \n");
    client = findAnClient();
    if(findTheAccount(client) != (sClient *) - 1) {
        printf("Já existe uma conta cadastrada para este cliente! \n");
        pauseScreen();
        chooseOptions();
    }
    account->balance = 0;
    account->client = client;
    account->numeroDaConta = totalOfAccounts+1;
}

void printfFindAccountMessages(sClient *client) {
    cleanScreen();
    printf("O cliente encontrado foi -> %s \n", client->name);
    printf("Tem certeza que é este o cliente certo? \n");
    printf("Digite 1 para sim e 0 para não \n");
}

sAccount *newAccount() {
    sAccount *account;
    account = malloc(sizeof(*account));
    if(!account) {
        printf("Não consegui alocar na memória \n");
        exit(-1);
    }
    return account;
}

void allocOneMoreAccount() {

    realloc(accounts, totalOfAccounts + 1);

    /* sAccount *ac;
    ac = malloc((totalOfAccounts + 1) * sizeof(*ac));
    for(int index = 0; index < totalOfAccounts; index++) {
        ac[index] = accounts[index];
    }
    free(accounts);
    accounts = ac; */
    totalOfAccounts++;
}

void printfAccountInformations(sAccount *account) {
    printf(":::::Mostrando informações do cliente:::::: \n");
    printf("Número da Conta -> ");
    printf("%d \n", account->numeroDaConta);
    printf("Dono da Conta->");
    printf("%s \n", account->client->name);
    printf("Fundo disponível ->");
    printf("%.2f \n", account->balance);
}

void showAllAccounts() {
    cleanScreen();
    for(int index = 0; index < totalOfAccounts; index++) {
        printfAccountInformations(&accounts[index]);
    }
    pauseScreen();
}

sClient *findAnClient() {
    int cpf;
    int isRightAccount;
    int returnOpt;
    sClient *client;

    do {
        printf("Busque uma conta pelo CPF \n");
        scanfInt(&cpf);
        client = findClientByCPF(cpf);
        if(client == (sClient *) -1) {
            printf("Conta não encontrada\n");
            printf("Digite 1 para pesquisar novo cpf \n");
            printf("Digite 2 para voltar ao menu \n");
            scanfInt(&returnOpt);
            if(returnOpt == 2) chooseOptions();
        };
        if(client != (sClient *) -1) {
            printfFindAccountMessages(client);
            scanfInt(&isRightAccount);
        }
    }
    while(!isRightAccount);

    return client;

}

void addBalance() {
    cleanScreen();
    float moneyQuantity;
    sClient *client = findAnClient();
    sAccount *account = findTheAccount(client);
    if(account == (sAccount *) -1) {
        printf("Não foi encontrado nenhuma conta com este cliente \n!");
        pauseScreen();
        return;
    }
    cleanScreen();
    printf("Quanto você quer adicionar ? \n");
    scanfFloat(&moneyQuantity);
    account->balance += moneyQuantity;
    printf("Saldo adicionado com sucesso! \n");
    pauseScreen();
}

void withdrawValue() {
    cleanScreen();
    float moneyQuantity;
    sClient *client = findAnClient();
    sAccount *account = findTheAccount(client);
    if(account == (sAccount *) -1) {
        printf("Não foi encontrado nenhuma conta com este cliente \n!");
        pauseScreen();
        return;
    }
    cleanScreen();
    printf("Quanto você quer sacar ? \n");
    scanfFloat(&moneyQuantity);
    if(account->balance < moneyQuantity) {
        printf("Não foi possível sacar, você tem apenas %f", account->balance);
        return;
    }
    account->balance -= moneyQuantity;
    printf("Saque efetuado com sucesso! \n");
    pauseScreen();
}

void seeBalance() {
    cleanScreen();
    sClient *client = findAnClient();
    sAccount *account = findTheAccount(client);
    if(account == (sAccount *) -1) {
        printf("Não foi encontrado nenhuma conta com este cliente \n!");
        pauseScreen();
        return;
    }
    cleanScreen();
    printf("Seu saldo é de: R$%.2f \n", account->balance);
    pauseScreen();
}

sAccount *findTheAccount(sClient *client) {
    for(int index = 0; index < totalOfAccounts; index++) {
        if(accounts[index].client->cpf == client->cpf) return &accounts[index];
    }
    return (sAccount *) -1;
}


