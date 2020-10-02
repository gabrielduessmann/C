#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("*** CALCULADORA IMPOSTO DE RENDA *** \n\n");
	
	float monthlyIncome;
	printf("Digite sua renda mensal (R$): ");
	scanf("%f", &monthlyIncome);
	
	int dependents;
	printf("Digite o número de dependentes: ");
	scanf("%i", &dependents);
	
	float minimumWage;
	printf("Digite o valor atual do salário mínimo (R$): ");
	scanf("%f", &minimumWage);
	
	if (!(monthlyIncome < 0 || dependents < 0 || minimumWage <= 0))
	{
		float minimumWagesEarned = monthlyIncome / minimumWage;
		
		float incomeTaxRate = 0;
		if (minimumWagesEarned > 2 && minimumWagesEarned <= 3) 
		{
			incomeTaxRate = 0.05;
		}
		else if (minimumWagesEarned > 3 && minimumWagesEarned <=5)
		{
			incomeTaxRate = 0.1;
		}
		else if (minimumWagesEarned > 5) 
		{
			incomeTaxRate = 0.2;
		}
		
		int discountByEachDependent = 50;
		int dependentsDiscount = dependents * discountByEachDependent;
		
		float incomeTaxAmount = monthlyIncome * incomeTaxRate - dependentsDiscount;
		if (incomeTaxAmount > 0)
		{
			printf("O seu imposto de renda é de: R$%f.\n", incomeTaxAmount);
		} 
		else 
		{
			printf("Você não precisa pagar imposto de renda.\n");
		}		
	}
	else 
	{
		printf("\nERRO - Valor(es) incorreto(s)\n");
	}
	
	return 0;
}
