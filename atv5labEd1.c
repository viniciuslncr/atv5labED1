#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Merge Sort - funções auxiliares
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort - funções auxiliares
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para imprimir o vetor
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Comparar Sorts
void compararSorts(int n) {
    int *arr = malloc(n * sizeof(int));
    int *copy = malloc(n * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand();

    clock_t ini, fim;
    double tempo;

    printf("\nComparando para n = %d\n", n);

    // Bubble Sort
    for (int i = 0; i < n; i++) copy[i] = arr[i];
    ini = clock();
    bubbleSort(copy, n);
    fim = clock();
    tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("BubbleSort: %.4fs\n", tempo);

    // Insertion Sort
    for (int i = 0; i < n; i++) copy[i] = arr[i];
    ini = clock();
    insertionSort(copy, n);
    fim = clock();
    tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("InsertionSort: %.4fs\n", tempo);

    // Merge Sort
    for (int i = 0; i < n; i++) copy[i] = arr[i];
    ini = clock();
    mergeSort(copy, 0, n-1);
    fim = clock();
    tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("MergeSort: %.4fs\n", tempo);

    // Quick Sort
    for (int i = 0; i < n; i++) copy[i] = arr[i];
    ini = clock();
    quickSort(copy, 0, n-1);
    fim = clock();
    tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("QuickSort: %.4fs\n", tempo);

    free(arr);
    free(copy);
}

// Bubble Sort para char
void bubbleSortChar(char arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                char temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Insertion Sort para char
void insertionSortChar(char arr[], int n) {
    for (int i = 1; i < n; i++) {
        char key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Merge Sort para char
void mergeChar(char arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    char L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortChar(char arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortChar(arr, l, m);
        mergeSortChar(arr, m+1, r);
        mergeChar(arr, l, m, r);
    }
}

// Quick Sort para char
int partitionChar(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    char temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSortChar(char arr[], int low, int high) {
    if (low < high) {
        int pi = partitionChar(arr, low, high);
        quickSortChar(arr, low, pi - 1);
        quickSortChar(arr, pi + 1, high);
    }
}

// Função para comparar sorts com char
void compararSortsChar(int n) {
    char *arr = malloc(n * sizeof(char));
    char *copy = malloc(n * sizeof(char));
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = 'A' + rand() % 26; // Letras maiúsculas aleatórias

    clock_t ini, fim;
    double tempo;

    printf("\nComparando (char) para n = %d\n", n);

    // Bubble Sort
    for (int i = 0; i < n; i++) copy[i] = arr[i];
    ini = clock();
    bubbleSortChar(copy, n);
    fim = clock();
    tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("BubbleSort: %.4fs\n", tempo);

    // Insertion Sort
    for (int i = 0; i < n; i++) copy[i] = arr[i];
    ini = clock();
    insertionSortChar(copy, n);
    fim = clock();
    tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("InsertionSort: %.4fs\n", tempo);

    // Merge Sort
    for (int i = 0; i < n; i++) copy[i] = arr[i];
    ini = clock();
    mergeSortChar(copy, 0, n-1);
    fim = clock();
    tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("MergeSort: %.4fs\n", tempo);

    // Quick Sort
    for (int i = 0; i < n; i++) copy[i] = arr[i];
    ini = clock();
    quickSortChar(copy, 0, n-1);
    fim = clock();
    tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("QuickSort: %.4fs\n", tempo);

    free(arr);
    free(copy);
}

int main() {
    compararSorts(1000);
    compararSorts(100000);
    compararSorts(1000000);
    
    compararSortsChar(10);
    compararSortsChar(100);
    compararSortsChar(150);
    return 0;
}