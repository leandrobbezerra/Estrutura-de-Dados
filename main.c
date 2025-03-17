#include <stdio.h>
#include <string.h>

// Definição da estrutura Pessoa
typedef struct {
    char nome[50];
    int idade;
} Pessoa;

int main() {
    // Lista de pessoas
    Pessoa pessoas[] = {
        {"João", 25},
        {"Maria", 30},
        {"Pedro", 20},
        {"Ana", 35},
        {"Carlos", 28}
    };

    int n = 5; // Número de pessoas na lista

    // Bubble Sort para ordenar do mais velho para o mais novo
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pessoas[j].idade < pessoas[j + 1].idade) {
                // Troca as posições
                Pessoa temp = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = temp;
            }
        }
    }

    // Mostra a lista ordenada
    printf("Lista ordenada por idade (do mais velho para o mais novo):\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s, Idade: %d\n", pessoas[i].nome, pessoas[i].idade);
    }

    return 0;
}