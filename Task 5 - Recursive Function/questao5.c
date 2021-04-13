#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define DEFAULT_INITIAL_DIVISION 2

bool isPrimeNumber(int num, int division);


int main(int argc, char *argv[]) {

    setlocale(LC_ALL, "Portuguese");

    int num;

    do {
    
        printf("Digite um número inteiro positivo: ");
        scanf("%i", &num);

        if (num >= 0) {
        
            if (isPrimeNumber(num, DEFAULT_INITIAL_DIVISION) == true) {
                printf("\nNúmero é primo. \n\n");
            } else {
                printf("\nNúmero não é primo. \n\n");
            }

        }

        else {
            printf("Você digitou um número negativo. Por favor, digite apenas números positivos.\n\n");
        }

    } while (num < 0);

    return 0;
}

bool isPrimeNumber(int num, int division) {

    if (num == division) {
        return true;
    } 

    else if (num > division) {

       if (num % division == 0) {
           return false;

       } else {

           division++;
           bool isPrime = isPrimeNumber(num, division);
           return isPrime;

       }
    } 
    else {
        return false;
    }

}