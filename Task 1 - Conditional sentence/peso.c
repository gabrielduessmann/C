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
		printf("Digite um n�mero correspondente ao planeta que voc� gostaria de ver seu peso.");
		printf(" \n[1] - Merc�rio \n[2] - V�nus \n[3] - Marte \n[4] - J�piter \n[5] - Saturno \n[6] - Urano\n");
		printf("N�mero do planeta escolhido: ");
		scanf("%i", &planet);
			
		float planetGravity;
		char *planetName;
		
		switch(planet)
		{
			case 1:
				planetName = "Merc�rio";
				planetGravity = 0.37;
				break;
			case 2:
				planetName = "V�nus";
				planetGravity = 0.88;
				break;
			case 3:
				planetName = "Marte";
				planetGravity = 0.38;
				break;
			case 4:
				planetName = "J�piter";
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
				printf("Voc� digitou um n�mero incorreto. Os n�meros poss�veis s�o de 1 a 6 apenas.");	
		}
		
		
		if (planetGravity != 0)
		{
			float planetWeight = earthWeight * planetGravity;
			printf("Com sua massa de %f Kg, seu peso em %s � de %f N", mass, planetName, planetWeight);			
		}
	}
	else
	{
		printf("%f n�o pode ser um peso. Voc� precisa digitar um n�mero positivo.", earthWeight);
	}
	
	return 0;
}
