//////////////////////////////////////////
// Programa de liksta encadeada simples //
//////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////
// Definicao da estruturado NO //
/////////////////////////////////

struct no{
	int numero;
		struct no *anterior;
		struct no *proximo;
};

///////////////////////
// Declarar variavel //
///////////////////////

struct no *cabeca = NULL;

//////////////////////////////////////
// Funcao que insere um NO na lista //
//////////////////////////////////////

void inserir(int numero) {
	//Criar um novo NO
		struct no *novoNo = NULL;
		//instanciacao de memoria
		novoNo = (struct no *) malloc(sizeof(struct no *));
		novoNo -> numero = numero;
		novoNo -> anterior= NULL;
		novoNo -> proximo = NULL;
		
	if (cabeca == NULL) {
	    //caso fqcil onde a lista esta fazia
		cabeca = novoNo;
	} else {
		//caso dificil onde a lista nn esta vazia
		struct no *ultimo = cabeca; 
		while (ultimo -> proximo != NULL) { 
			ultimo = ultimo -> proximo;      
		}
		ultimo -> proximo = novoNo;
		novoNo -> anterior = ultimo;
	}
}

////////////////////////////////////////////////
// fUNCAO que da print nos elementos da lista //
////////////////////////////////////////////////

void imprimir() {
    printf("==================\n");
    
	struct no *ponteiro = cabeca;
	
	while (ponteiro != NULL){
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
}

////////////////////////////////////////////
// Funcao que remove um elemento da lista //
////////////////////////////////////////////

void excluir(int numero) {
    struct no *ponteiro = cabeca; {
	
    while (ponteiro != NULL) {
        if (ponteiro -> numero == numero) {
            // Forcar exclusao
            if (ponteiro == cabeca) {
                //excluir o primeiro
                cabeca = cabeca -> proximo;
                cabeca -> anterior = NULL;
            }else if (ponteiro -> proximo == NULL) {
                //excluir o ultimo
                ponteiro -> anterior -> proximo = NULL;
            } else{
                //excluir no primeiro
                ponteiro -> proximo -> anterior = ponteiro -> anterior;
                ponteiro -> anterior -> proximo = ponteiro -> proximo;
            }
            free(ponteiro);
        }
        ponteiro = ponteiro -> proximo;
      }
    }
}
//////////////////////////////////
// fUNCAO PRINCIPAL DE EXECUCAO //
//////////////////////////////////

int main(){
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	inserir(6);
	
	imprimir();
	
	excluir(1);
	excluir(3);
	excluir(3);
	excluir(6);
	
	imprimir();
}
