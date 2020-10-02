#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 200000


int main(int argc, char *argv[]) {
	
	int arraySize, numberOfCommands;
	printf("[INSTRUCOES]\n\n-Digite um numero inteiro para ser o tamanho do seu array: \n[Aperte ENTER]\n-Digite o numero de comandos que voce quer dar:\n[Aperte ENTER]\n\n*Comandos:\n");
	scanf("%i", &arraySize);
	scanf("%i", &numberOfCommands);
	int array[MAX_ARRAY_SIZE];
	
	int i;
	
	// Inicializa todos os index do array com o valor 0
	for (i=0; i<MAX_ARRAY_SIZE; i++) {
		array[i] = 0;
	}
		
	printf("\n[INSTRUCOES]\n\n-Digite o comando que voce deseja executar \n[1 - Frente] [2 - Tras] [3 - Imprimir] \n[Aperte ENTER] \n-Digite uma posicao no array (entre os valores 1 e %i)\n[Aperte ENTER] \n-Digite um valor inteiro positivo \n[Aperte ENTER] \n", arraySize);
	int command, index, number;
	
	for (i=1;  i <= numberOfCommands; i++)
	{	
			
			/* 
			TESTE - Testa os números populados no array; Basta remover o cometário do código abaixo.
			*/
			
			/*  
			
				int x;
				printf("\n\n[ ");
				for (x=0; x<arraySize; x++){
					if (x != (arraySize-1)) {
						printf("%i,  ", array[x]);
					} else {
					 printf("%i ]\n\n", array[x]);	
					}
				}
				
			*/
		    
			
			printf("\n*COMANDOS:\n");
			scanf("%i", &command);
			scanf("%i", &index);
			if (command != 3) {
				scanf("%i", &number);
			}
			index--;
			int j;
			
			switch(command){
				case 1:
					for (j=index; number>0 && j <= arraySize; j++){
						array[j] = array[j] + number; 
						number--;
					}
					break;
				case 2:
					for (j=index; number>0 && j>=0; j--){
						array[j] = array[j] + number; 
						number--;
					}
					break;
				case 3:
					if (index < arraySize || index < 0){
						printf("\nNumero encontrado: %i\n", array[index]);
					} else {
						printf("\nComo a posicao do array nao condiz com o tamanho do array que voce inicializou, nao pode ser encontrado nenhum valor nessa posicao. ");
					}
					break;
				default:
					printf("Por favor digite um numero que seja valido para o primeiro comando!\n");
			}
	
	}
	return 0;
}
