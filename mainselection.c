#include <stdio.h>
#include <string.h>

// DefiniÃ§Ã£o da estrutura Carta
typedef struct {
    char simbolo[10]; // Ex: "Copas", "Ouros", "Espadas", "Paus"
    int valor;        // Ex: 1 (Ãs), 2, 3, ..., 10, 11 (Valete), 12 (Dama), 13 (Rei)
} Carta;

int main() {
    // Array de estruturas Carta
    Carta cartas[] = {
        {"Copas", 10},
        {"Ouros", 7},
        {"Espadas", 1}, // Ãs
        {"Paus", 12},   // Dama
        {"Copas", 4},
        {"Ouros", 11}   // Valete
    };

    int tamanho = sizeof(cartas) / sizeof(cartas[0]); // Calcula o tamanho do array
    int i, j, indice_menor;
    Carta temp;

    // Selection Sort para ordenar do menor valor para o maior
    for (i = 0; i < tamanho - 1; i++) {
        indice_menor = i; // Assume que o menor valor estÃ¡ na posiÃ§Ã£o atual
        for (j = i + 1; j < tamanho; j++) {
            if (cartas[j].valor < cartas[indice_menor].valor) {
                indice_menor = j; // Atualiza o Ã­ndice do menor valor
            }
        }
        // Troca a posiÃ§Ã£o do menor valor encontrado com a posiÃ§Ã£o atual
        if (indice_menor != i) {
            temp = cartas[i];
            cartas[i] = cartas[indice_menor];
            cartas[indice_menor] = temp;
        }
    }

    // Mostra a lista ordenada
    printf("Lista ordenada por valor (do menor para o maior):\n");
    for (i = 0; i < tamanho; i++) {
        printf("SÃ­mbolo: %s, Valor: %d\n", cartas[i].simbolo, cartas[i].valor);
    }

    return 0;
}