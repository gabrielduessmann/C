#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	
	float earthWeight;
	printf("Digite seu peso na Terra (N): ");
	scanf("%f", &earthWeight);
	
	if (earthWeight > 0) 
	{
		
		float earthGravity = 9.8;
		float mass = earthWeight / earthGravity;
		
		int planet;
		printf("Digite um número correspondente ao planeta que você gostaria de ver seu peso.");
		printf(" \n[1] - Mercúrio \n[2] - Vênus \n[3] - Marte \n[4] - Júpiter \n[5] - Saturno \n[6] - Urano\n");
		printf("Número do planeta escolhido: ");
		scanf("%i", &planet);
			
		float planetGravity;
		char *planetName;
		
		switch(planet)
		{
			case 1:
				planetName = "Mercúrio";
				planetGravity = 0.37;
				break;
			case 2:
				planetName = "Vênus";
				planetGravity = 0.88;
				break;
			case 3:
				planetName = "Marte";
				planetGravity = 0.38;
				break;
			case 4:
				planetName = "Júpiter";
				planetGravity = 2.64;
				break;
			case 5:
				planetName = "Saturno";
				planetGravity = 1.15;
				break;
			case 6:
				planetName = "Urano";
				planetGravity = 1.17;
				break;
			default:
				printf("Você digitou um número incorreto. Os números possíveis são de 1 a 6 apenas.");	
		}
		
		
		if (planetGravity != 0)
		{
			float planetWeight = earthWeight * planetGravity;
			printf("Com sua massa de %f Kg, seu peso em %s é de %f N", mass, planetName, planetWeight);			
		}
	}
	else
	{
		printf("%f não pode ser um peso. Você precisa digitar um número positivo.", earthWeight);
	}
	
	return 0;
}
