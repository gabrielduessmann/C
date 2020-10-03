#include <stdio.h>
#include <stdlib.h>

//Declarando variaveis
#define TAMANHO_MAXIMO_VETOR_100 100
#define TAMANHO_MAXIMO_VETOR_200 200


/* 

FEITO EM DUPLA

ESTUDANTES:
Cristian Eduardo
Gabriel Duessmann

 */


void le_conjunto_vetor(int vetor[], int tamanhoVetor);

int uniao( int vetor1[], int tamanhoVetor1, int vetor2[], int tamanhoVetor2, int vetor3[] );
int intersec( int vetor1[], int tamanhoVetor1, int vetor2[], int tamanhoVetor2, int vetor3[] );
int diferenca( int vetor1[], int tamanhoVetor1, int vetor2[], int tamanhoVetor2, int vetor3[] );

void resultadoVetor(int vetor3[]);

int vetoresPossuemMesmoElemento(int elementoBusca, int vetor[], int tamanhoVetor);

int main(int argc, char *argv[]) {
	
	// Inicilização de vetores
	int vetorA[TAMANHO_MAXIMO_VETOR_100] = {0};
	int vetorB[TAMANHO_MAXIMO_VETOR_100] = {0};
	int vetorC[TAMANHO_MAXIMO_VETOR_200] = {0};
	
	int tamanhoVetorA, tamanhoVetorB;
	
	printf("Digite um tamanho para seu vetor A: ");
	scanf("%i", &tamanhoVetorA);;
	le_conjunto_vetor(vetorA, tamanhoVetorA);
	
	printf("Digite um tamanho para seu vetor B: ");
	scanf("%i", &tamanhoVetorB);
	le_conjunto_vetor(vetorB, tamanhoVetorB);
	

    vetorC[TAMANHO_MAXIMO_VETOR_200] = uniao(vetorA, tamanhoVetorA, vetorB, tamanhoVetorB, vetorC);
    printf("\n\n Uniao entre A e B \n");
    resultadoVetor(vetorC);
  
    vetorC[TAMANHO_MAXIMO_VETOR_200] = intersec(vetorA, tamanhoVetorA, vetorB, tamanhoVetorB, vetorC);
    printf("\n\n Interseccao entre A e B \n");
    resultadoVetor(vetorC);
	
	vetorC[TAMANHO_MAXIMO_VETOR_200] = diferenca(vetorA, tamanhoVetorA, vetorB, tamanhoVetorB, vetorC);
	 printf("\n\n Diferenca entre A e B \n");
	resultadoVetor(vetorC);
		
	
	return 0;
}	

void le_conjunto_vetor(int vetor[], int tamanhoVetor) {
	int i, j;
	int valor;	
	int ehValorRepetido=0;
	for (i=0; i<tamanhoVetor; i++){
		printf("Digite um valor para a posicao %i do vetor: ", i+1);
		scanf("%i", &valor);
		ehValorRepetido=0;
		for (j=i; j>=0; j--) {
			if (valor == vetor[j])
			{
				ehValorRepetido=1;
			}
		}
		if (ehValorRepetido==0){
			vetor[i] = valor;
		} else {
			printf("%i e um numero repetido. Voce nao pode utiliza-lo. \n", vetor[i]);
			i--;
		}
	}
	
}


// FUNÇÃO 
 int uniao( int vetor1[], int tamanhoVetor1, int vetor2[], int tamanhoVetor2, int vetor3[] ) {
	int i;	
	for (i=0; i<tamanhoVetor1; i++){
		vetor3[i] = vetor1[i];
	}		
	int indexVetor3 = tamanhoVetor1 ;
	
	
	int j;
	for (j=0; j<tamanhoVetor2; j++){
		if (vetoresPossuemMesmoElemento(vetor2[j], vetor1, tamanhoVetor2) == -1){
			vetor3[indexVetor3] = vetor2[j];
			indexVetor3++;	
		} 	
	}
	return vetor3;
}


// INTERSECCAO
int intersec( int vetor1[], int tamanhoVetor1, int vetor2[], int tamanhoVetor2, int vetor3[] ){
    int i, maiorVetor;
    
    maiorVetor = tamanhoVetor1;
    
    int indexVetorC = 0;
    
    if(tamanhoVetor1 <= tamanhoVetor2) {
        maiorVetor = tamanhoVetor2;
        
        for (i=0; i<maiorVetor; i++){
            if (vetoresPossuemMesmoElemento(vetor2[i], vetor1, tamanhoVetor1) != -1){
                vetor3[indexVetorC] = vetor2[i];
                indexVetorC++;
            }  
        }
    }else{
        for (i=0; i<maiorVetor; i++){
            if (vetoresPossuemMesmoElemento(vetor1[i], vetor2, tamanhoVetor2) != -1){
                vetor3[indexVetorC] = vetor1[i];
                indexVetorC++;
            } 
        }
    } 
	return vetor3;   
}


// DIFERENCA
int diferenca( int vetor1[], int tamanhoVetor1, int vetor2[], int tamanhoVetor2, int vetor3[] ){
    int i;
    int indexVetor3 = 0;
    
    for (i=0; i<tamanhoVetor1; i++){
        if (vetoresPossuemMesmoElemento(vetor1[i], vetor2, tamanhoVetor2) == -1){
            vetor3[indexVetor3] = vetor1[i];
            indexVetor3++;
        } 
    }   
	return vetor3; 
}


int vetoresPossuemMesmoElemento(int elementoBusca, int vetor[], int tamanhoVetor){
	int i;
	for (i=0; i<tamanhoVetor; i++){
		if (elementoBusca == vetor[i])	
			return i;
	}
	return -1;
}

// PRINTA PARA O USUARIO O VETOR 3
resultadoVetor( int vetor3[]){
    int i;    
    
    for (i=0; i<TAMANHO_MAXIMO_VETOR_200; i++){
        printf("Posicao %i: %i \n", i+1, vetor3[i]); 
    }    
    
    for (i=0; i<TAMANHO_MAXIMO_VETOR_200; i++){
        vetor3[i] = 0; 
    }
}























































































