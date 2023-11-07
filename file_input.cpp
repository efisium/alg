#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Funzione per leggere caratteri da un file
string leggiCaratteriDaFile(const string& nomeFile) {
    string caratteri;
    ifstream file(nomeFile);
    if (file.is_open()) {
        char carattere;
        while (file.get(carattere)) {
            caratteri.push_back(carattere);
        }
        file.close();
    } else {
        cout << "Impossibile aprire il file '" << nomeFile << "'" << endl;
    }
    return caratteri;
}

// Funzione per leggere una matrice di interi da un file
vector<vector<int>> leggiMatriceDaFile(const string& nomeFile) {
    vector<vector<int>> matrice;
    ifstream file(nomeFile);
    if (file.is_open()) {
        string riga;
        while (getline(file, riga)) {
            istringstream stream(riga);
            vector<int> rigaMatrice;
            int numero;
            while (stream >> numero) {
                rigaMatrice.push_back(numero);
            }
            matrice.push_back(rigaMatrice);
        }
        file.close();
    } else {
        cout << "Impossibile aprire il file '" << nomeFile << "'" << endl;
    }
    return matrice;
}

int main() {
    string caratteriFile = "caratteri.txt";
    string matriceFile = "matrice.txt";

    string caratteri = leggiCaratteriDaFile(caratteriFile);
    vector<vector<int>> matrice = leggiMatriceDaFile(matriceFile);

    // Esempi di utilizzo dei dati letti dai file
    cout << "Caratteri letti da '" << caratteriFile << "': " << caratteri << endl;
    cout << "Matrice letta da '" << matriceFile << "':" << endl;
    for (const auto& riga : matrice) {
        for (int numero : riga) {
            cout << numero << ' ';
        }
        cout << endl;
    }

    return 0;
}
