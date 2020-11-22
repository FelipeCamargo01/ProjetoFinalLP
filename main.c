#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <locale.h>
void menu();
void menuAccountMovimentations();

int option;
int optionAccountMovimentations;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    initClient();
    initAccount();
    chooseOptions();
    return 0;
}

void chooseOptions() {
    while(option != 6) {
        menu();
        scanfInt(&option);
        switch(option) {
            case 1:
                addClient();
                break;
            case 2:
                addAccount();
                break;
            case 3:
                menuAccountMovimentations();
                scanfInt(&optionAccountMovimentations);
                switch(optionAccountMovimentations) {
                    case 1:
                        addBalance();
                        break;
                    case 2:
                        withdrawValue();
                        break;
                    case 3:
                        seeBalance();
                        break;
                    case 4:
                        break;
                    default:
                        break;
                }
                break;
            case 4:
                showAllClients();
                break;
            case 5:
                showAllAccounts();
                break;
            case 6:
                exit(-1);
            default:
                printf("Opção inválida \n");
                break;
        }
    }
}

void menu() {
    cleanScreen();
    printf("Digite 1 para  - Criar cliente \n");
    printf("Digite 2 para  - Criar conta \n");
    printf("Digite 3 para  - Movimentar conta \n");
    printf("Digite 4 para  - Listar clientes \n");
    printf("Digite 5 para  - Listar contas \n");
    printf("Digite 6 para  - Sair \n");
}
void menuAccountMovimentations() {
    cleanScreen();
    printf("Digite 1 para  - Efetuar um depósito \n");
    printf("Digite 2 para  - Efetuar um saque \n");
    printf("Digite 3 para  - Consultar o saldo \n");
    printf("Digite 4 para  - Voltar ao menu \n");
}
