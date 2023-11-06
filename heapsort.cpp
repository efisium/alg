#include <iostream>
#include <vector>

using namespace std;

// Funzione per scambiare due elementi in un vettore
void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Funzione per eseguire il down-heap (Heapify) in un heap
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr, i, largest);
        heapify(arr, n, largest);
    }
}

// Funzione per eseguire l'algoritmo Heap Sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Costruisci un heap (albero binario completo) a partire dai dati
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Estrai gli elementi uno per uno dall'heap e li colloca in fondo all'array
    for (int i = n - 1; i > 0; i--) {
        swap(arr, 0, i); // Scambia il massimo elemento con l'ultimo
        heapify(arr, i, 0); // Chiamata ricorsiva per il resto dell'array
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Array non ordinato: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Esegui l'Heap Sort
    heapSort(arr);

    cout << "Heap Sort: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
