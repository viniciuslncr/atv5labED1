#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Busca Sequencial
int busca_sequencial(int arr[], int n, int chave) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == chave)
            return i;
    }
    return -1;
}

// Busca Binária (array deve estar ordenado)
int busca_binaria(int arr[], int n, int chave) {
    int esq = 0, dir = n - 1;
    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        if (arr[meio] == chave)
            return meio;
        else if (arr[meio] < chave)
            esq = meio + 1;
        else
            dir = meio - 1;
    }
    return -1;
}

// Busca de palavra em texto
int busca_palavra(const char *texto, const char *palavra) {
    return strstr(texto, palavra) != NULL;
}

// Função que compara os tempos de busca
void compara_tempos(int tamanho, int chave) {
    int *arr = malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++)
        arr[i] = i;

    clock_t inicio, fim;
    double tempo_seq, tempo_bin;

    // Busca Sequencial
    inicio = clock();
    busca_sequencial(arr, tamanho, chave);
    fim = clock();
    tempo_seq = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Busca Binária
    inicio = clock();
    busca_binaria(arr, tamanho, chave);
    fim = clock();
    tempo_bin = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Array com %d elementos:\n", tamanho);
    printf("Tempo Busca Sequencial: %.6f segundos\n", tempo_seq);
    printf("Tempo Busca Binária: %.6f segundos\n\n", tempo_bin);

    free(arr);
}

void compara_busca_texto(const char *texto, const char *palavra) {
    clock_t inicio, fim;
    double tempo;

    inicio = clock();
    int achou = busca_palavra(texto, palavra);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Busca da palavra \"%s\" no texto: %s\n", palavra, achou ? "Encontrada" : "Não encontrada");
    printf("Tempo de busca: %.6f segundos\n\n", tempo);
}

int main() {
    // a) Array com 1000 elementos
    compara_tempos(1000, 999);

    // b) Array com 100000 elementos
    compara_tempos(100000, 99999);

    // c) Array com 1000000 elementos
    compara_tempos(1000000, 999999);

    // d) Buscando uma palavra em um texto digitado pelo usuário
    char texto[10001];
    char palavra[101];

    printf("Digite um texto: \n");
    fflush(stdin);
    fgets(texto, 10001, stdin);

    printf("Digite a palavra a ser buscada:\n");
    fflush(stdin);
    fgets(palavra, 101, stdin);

    // Remover o '\n' do final, se houver
    texto[strcspn(texto, "\n")] = 0;
    palavra[strcspn(palavra, "\n")] = 0;

    compara_busca_texto(texto, palavra);

    return 0;
}