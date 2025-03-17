#include <stdio.h>
#include <stdbool.h> // Para usar o tipo bool

// Definição da estrutura Senha
typedef struct {
    bool prioridade; // 1 para prioritária, 0 para não prioritária
    int numero;      // Número da senha
} Senha;

// Função para ordenar a lista de senhas usando Insertion Sort
void insertionSort(Senha senhas[], int tamanho) {
    int i, j;
    Senha chave;

    for (i = 1; i < tamanho; i++) {
        chave = senhas[i]; // Elemento atual a ser inserido na posição correta
        j = i - 1;

        // Move os elementos maiores que a chave para a direita
        // Prioriza as senhas com prioridade (1) e ordena pelo número
        while (j >= 0 && (senhas[j].prioridade < chave.prioridade || 
                         (senhas[j].prioridade == chave.prioridade && senhas[j].numero > chave.numero))) {
            senhas[j + 1] = senhas[j];
            j--;
        }
        senhas[j + 1] = chave; // Insere a chave na posição correta
    }
}

int main() {
    // Lista de senhas
    Senha senhas[] = {
        {0, 5},  // Não prioritária, número 5
        {1, 3},  // Prioritária, número 3
        {0, 2},  // Não prioritária, número 2
        {1, 8},  // Prioritária, número 8
        {1, 1},  // Prioritária, número 1
        {0, 7}   // Não prioritária, número 7
    };

    int tamanho = sizeof(senhas) / sizeof(senhas[0]); // Calcula o tamanho da lista

    // Ordena a lista de senhas
    insertionSort(senhas, tamanho);

    // Mostra a lista ordenada
    printf("Lista ordenada (prioritárias primeiro, depois por número):\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Prioridade: %d, Número: %d\n", senhas[i].prioridade, senhas[i].numero);
    }

    return 0;
}