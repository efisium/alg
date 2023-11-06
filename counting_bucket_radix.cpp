/*
countingSort: Questa funzione implementa l'algoritmo Counting Sort. Prima, trova il valore massimo e minimo nell'array per calcolare 
il range di valori possibili. Poi, inizializza un vettore di conteggio (count) per tenere traccia delle occorrenze di ciascun valore nell'array. Successivamente, utilizza questo conteggio per posizionare correttamente ciascun elemento nell'array di output in base alle occorrenze. Alla fine, l'array di output diventa l'array ordinato.

radixSort: Questa funzione implementa l'algoritmo Radix Sort in base 10. Inizia determinando il valore massimo nell'array 
e utilizza la variabile exp per iterare attraverso le cifre dei numeri. Per ciascuna cifra, conta le occorrenze delle cifre correnti in ciascun elemento dell'array e calcola le posizioni finali di queste cifre nell'output. Infine, riordina l'array in base alla cifra corrente. L'iterazione continua finché tutte le cifre sono state considerate.

bucketSort: Questa funzione implementa l'algoritmo Bucket Sort. Distribuisce gli elementi nell'array in "secchi" (bucket) 
in base al loro valore. Ogni secchio contiene elementi con valori in una determinata gamma. Successivamente, ordina ciascun 
secchio separatamente (ad esempio, utilizzando Insertion Sort). Infine, concatena i secchi ordinati per ottenere l'array ordinato finale. Bucket Sort è efficace per dati distribuiti in modo uniforme.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Algoritmo di ordinamento Counting Sort
void countingSort(vector<int>& arr) {
    // Trova il valore massimo e minimo nell'array
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;

    // Inizializza un vettore "count" di dimensione "range" con zeri
    vector<int> count(range, 0);
    vector<int> output(arr.size());

    // Conta le occorrenze di ciascun elemento nell'array originale
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - min_val]++;
    }

    // Calcola le posizioni finali degli elementi nell'output
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Costruisce l'array ordinato "output"
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }

    // Copia gli elementi ordinati in "arr"
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

// Algoritmo di ordinamento Radix Sort (in base 10)
void radixSort(vector<int>& arr) {
    int max_val = *max_element(arr.begin(), arr.end());
    int exp = 1;

    // Esegue l'ordinamento per ciascifra del numero
    while (max_val / exp > 0) {
        vector<int> output(arr.size(), 0);
        vector<int> count(10, 0);

        // Conta le occorrenze delle cifre attuali
        for (int i = 0; i < arr.size(); i++) {
            count[(arr[i] / exp) % 10]++;
        }

        // Calcola le posizioni finali delle cifre nell'output
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Costruisce l'array ordinato "output" basato sulla cifra corrente
        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        // Copia gli elementi ordinati in "arr"
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }

        exp *= 10;
    }
}

// Algoritmo di ordinamento Bucket Sort
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<vector<float>> buckets(n);

    // Distribuisce gli elementi in "buckets" in base al valore
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        buckets[index].push_back(arr[i]);
    }

    // Ordina ciascun bucket separatamente (es. usando Insertion Sort)
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatena i bucket ordinati per ottenere l'array ordinato
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    // Counting Sort
    vector<int> arr1 = {4, 2, 2, 8, 3, 3, 1};
    cout << "Counting Sort: ";
    countingSort(arr1);
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;

    // Radix Sort
    vector<int> arr2 = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "Radix Sort: ";
    radixSort(arr2);
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << endl;

    // Bucket Sort
    vector<float> arr3 = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    cout << "Bucket Sort: ";
    bucketSort(arr3);
    for (float num : arr3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
