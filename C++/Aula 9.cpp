///////////////////////////////////////////////
// Programa q implementa uma arvore de busca //
///////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///////////////////////////
// Declarando estruturas //
///////////////////////////

struct no {
	int numero;
	struct no *esquerda;
	struct no *direita;
};

///////////////////////////////////////////////
// Funcao q insere um no na arvore//
///////////////////////////////////////////////

struct no *inserir(struct no *raiz, int numero) {
	if (raiz == NULL) {
		raiz = (struct no *) malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
	} else {
		if (numero < raiz -> numero){
			raiz -> esquerda = inserir(raiz -> esquerda, numero);
		} else if (numero > raiz -> numero){
			raiz -> direita = inserir(raiz -> direita, numero);
		}
	}
	return raiz;
}

//////////////////////////////////////
// Funcao que busca um no na arvore //
//////////////////////////////////////

void buscar(struct no *raiz, int numero){
	if (raiz == NULL){
		printf("NÃO ACHEI!\n");
	} else if (raiz -> numero == numero){
		printf("ACHEI!\n");
	} else if (raiz -> numero > numero){
		buscar (raiz ->  esquerda, numero);
	} else {
		buscar (raiz -> direita, numero);
	}
}

////////////////////////
// Funcao que NAVEGAR //
////////////////////////
void navegar(struct no *raiz){
	if (raiz != NULL) {
		navegar(raiz -> esquerda);
		printf("%d\t\n", raiz -> numero);
		navegar(raiz -> direita);
	}
}

/////////////////
// Funcao MAIN //
/////////////////

int main(){
	// declarando variaveis
	struct no *raiz = NULL;
	int opcao = 0;
	int numero = 0;
	int i = 0;
	
	// inicializacao da aleatoriedade
	time_t t;
	srand((unsigned) time(&t));
	
	// Menu de opcoes
	while (opcao != 5) {
		printf("+========================+\n");
		printf("|     MENU DE OPCOES     |\n");
		printf("+========================+\n");
		printf("|    1 - CRIAR ARVORE    |\n");
		printf("|    2 - INSERIR NO      |\n");
		printf("|    3 - BUSCAR NO       |\n");
		printf("|    4 - NAVEGAR A ARVORE|\n");
		printf("|    5 - SAIR            |\n");
		printf("+========================+\n");
		printf("Digite sua opcao: \n");
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1:
				for (i = 0 ; i<100 ; i++){
				raiz = inserir(raiz, rand());
				} 
				break;
			case 2:
				printf("digite um numero: ");
				scanf("%d", &numero);
				raiz = inserir(raiz, numero);
				break;
			case 3:
				printf("Digite numero a er buscado: ");
				scanf("%d", &numero);
				buscar(raiz, numero);
				break;
			case 4:
				navegar(raiz);
				break;
		}
	}      
}
