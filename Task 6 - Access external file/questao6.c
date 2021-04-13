#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define CAMINHO_ARQUIVO "arquivo.txt"


int main(int argc, char *argv[]) {

    setlocale(LC_ALL, "Portuguese");


    FILE *arquivo = fopen(CAMINHO_ARQUIVO, "r");

    if (arquivo != NULL) {

        char palavraBusca[50];

        printf("Digite um palavra que você deseja buscar no arquivo: ");
        scanf("%s", palavraBusca);
        fflush(stdin);

        int qtdeVezesPalavraFoiEcontrada = 0;

        char  palavra[255];
        char x;
        do {

            fscanf(arquivo, "%s", palavra);

            if (strcmp(palavra, palavraBusca) == 0) qtdeVezesPalavraFoiEcontrada++;
        

        } while (!feof(arquivo));

        printf("\nA palavra '%s' foi encontrada %i vez(es) no arquivo.\n\n", palavraBusca, qtdeVezesPalavraFoiEcontrada);

    } else {
        printf("Erro ao abrir o arquivo!\n\n");
    }

    return 0;
}