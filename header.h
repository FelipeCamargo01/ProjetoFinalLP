#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <locale.h>

//*******defining variables cliente*******//
typedef struct Client {
    char name[256];
    int cpf;
} sClient;
//*******defining variables contas*******//
typedef struct Account sAccount;
//*******Util functions*********//
void scanfInt(int *memoryAddressInt);
void scanfFloat(float *memoryAddressFloat);
void scanfString(char *arrayAddress);
void cleanScreen();
void pauseScreen();
//*******cliente functions*******//
void initClient();
sClient *newClient();
void addClient();
void showAllClients();
sClient *findClientByCPF(int cpf);
//*******conta functions*******//
void initAccount();
sAccount *newAccount();
void addAccount();
void showAllAccounts();
void withdrawValue();
void seeBalance();
void addBalance();
//*******main functions******///
void chooseOptions();
#endif // HEADER_H_INCLUDED
