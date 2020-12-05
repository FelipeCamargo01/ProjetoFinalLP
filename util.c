#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void scanfInt(int *memoryAddressInt) {
    scanf("%d", memoryAddressInt);
}
void scanfFloat(float *memoryAddressFloat) {
    scanf("%f", memoryAddressFloat);
}
void scanfString(char *arrayAddress) {
    gets(arrayAddress);
}
void cleanScreen() {
    system("cls");
}
void pauseScreen() {
    system("pause");
}
