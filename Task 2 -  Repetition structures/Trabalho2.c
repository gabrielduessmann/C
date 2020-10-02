#include <stdio.h>
#include <stdlib.h>

/* 
 */

int main(int argc, char *argv[]) {
	
	int number1, number2;
	char response;

	do{	
		do {
			printf("--- Calculadora de MMC e MDC ---\n\n");
			
			printf("Digite um numero positivo (A): ");
			scanf("%i", &number1);
			
			printf("Digite outro numero positivo (B): ");
			scanf("%i", &number2);
		
			printf("\n");
			
			if (number1<=0 || number2<=0) {
				printf("Voce nao pode digitar numeros negativos ou zero. Por favor digite novamente. \n \n \n");
			}
		} while (number1<=0 || number2<=0);
		
		int divider = 2;
		int lcm = 1; // Least common multiple / Mínimo múltiplo comum
		int gcd = 1; // Greatest common divisor / Máximo divisor comum
		
		
		while (number1!=1 || number2!=1){
			
			if (number1%divider==0 || number2%divider==0){
					lcm = lcm * divider;
					
					printf("A: %i  B: %i   Divisor: %i \n", number1, number2, divider);
					
				if (number1%divider==0 && number2%divider==0){
					gcd = gcd * divider;
				}
					
				if (number1%divider==0) {
					number1 = number1 / divider; 
					
				}
				if (number2%divider==0) {
					number2 = number2 / divider;
					 	
				}			
			}
			if (number1%divider!=0 && number2%divider!=0 ){
				divider++;
			}	
		}
		
		printf("A: 1  B: 1  ");
		
		printf("\n\n------------\nMMC: %i \nMDC: %i\n------------\n\n\n", lcm, gcd);
		
		fflush(stdin); 
		printf("Voce desejar calcular novamente? Se sim, digite 'S', senao digite qualquer outra letra: ");
		scanf("%c", &response);
		printf("\n\n\n");
	} while (response=='S' || response=='s');
	
	return 0;
}
