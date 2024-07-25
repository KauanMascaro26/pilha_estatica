#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

#define TAMANHO_MAX 100 


typedef struct {
    int elementos[TAMANHO_MAX];
    int topo;
} PilhaEstatica;


PilhaEstatica criarPilhaEstatica() {
    PilhaEstatica pilha;
    pilha.topo = -1; 
    return pilha;
}


int pilhaCheia(PilhaEstatica *pilha) {
    return (pilha->topo == TAMANHO_MAX - 1);
}


int pilhaVazia(PilhaEstatica *pilha) {
    return (pilha->topo == -1);
}


void empilhar(PilhaEstatica *pilha, int elemento) {
    if (pilhaCheia(pilha)) {
        printf("Erro: Pilha estática cheia, não é possível empilhar mais elementos.\n");
    } else {
        pilha->topo++;
        pilha->elementos[pilha->topo] = elemento;
        printf("Elemento %d empilhado na pilha.\n", elemento);
    }
}


int desempilhar(PilhaEstatica *pilha) {
    int elemento;

    if (pilhaVazia(pilha)) {
        printf("Erro: Pilha estática vazia, não é possível desempilhar.\n");
        return -1; 
    } else {
        elemento = pilha->elementos[pilha->topo];
        pilha->topo--;
        return elemento;
    }
}


void imprimirPilhaEstatica(PilhaEstatica *pilha) {
	int i;
    printf("Pilha Estática: ");
    if (pilhaVazia(pilha)) {
        printf("pilha vazia\n");
    } else {
        for (i = 0; i <= pilha->topo; i++) {
            printf("%d ", pilha->elementos[i]);
        }
        printf("\n");
    }
}


int main() {
	setlocale(LC_ALL, "portuguese");
    PilhaEstatica pilha = criarPilhaEstatica();
    int opcao, elemento;

    do {
        printf("\nOpções:\n");
        printf("1. Empilhar elemento\n");
        printf("2. Desempilhar elemento\n");
        printf("3. Imprimir pilha\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser empilhado: ");
                scanf("%d", &elemento);
                empilhar(&pilha, elemento);
                break;
            case 2:
                elemento = desempilhar(&pilha);
                if (elemento != -1) {
                    printf("Elemento desempilhado: %d\n", elemento);
                }
                break;
            case 3:
                imprimirPilhaEstatica(&pilha);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
