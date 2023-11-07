#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t; // Numero di test cases

    while (t--) {
        int d, i;
        cin >> d >> i; // Lettura dei parametri D e I

        int pos = 1; // Inizia dalla radice (nodo 1)

        for (int depth = 1; depth < d; depth++) {
            // Calcola il numero di nodi nel sottoalbero sinistro
            int numNodes = 1 << (d - depth - 1);

            // Calcola la posizione in base al flag
            if (i % 2 == 1) {
                pos = pos * 2; // Vai al figlio sinistro
            } else {
                pos = pos * 2 + 1; // Vai al figlio destro
            }

            // Ricalcola i in base al numero di nodi nel sottoalbero sinistro
            i = (i + 1) / 2;
        }

        cout << pos << endl; // Stampa la posizione finale
    }

    return 0;
}
