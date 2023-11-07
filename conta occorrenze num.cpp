/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug onli"ne from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
int findOccurrence (int *seq, int p, int r, int k);
int main ()
{
  int n_casi;
  int k, dim;
  int occurrence = 0;
  string input;
  cout << "Inserisci il numero di casi di test:";
  cin >> n_casi;
  string *test_case = new string[n_casi];
  for (int j = 0; j < n_casi; j++)
    {
      cout << "[TEST-CASE " << j <<"]Inserisci i valori nel seguente ordine [elemento-dimensione-array]:\n ";
      cin >> test_case[j];

    }
  for (int j = 0; j < n_casi; j++){
        k = test_case[j][0] - '0';
        dim = test_case[j][1] - '0';
        int *seq = new int[dim];
        for (int i = 2; i < test_case[j].length (); i++){
	        seq[i - 2] = test_case[j][i] - '0';
	    }
        cout << "Value:" << k << " dim:" << dim << " sequence:";
        for (int j = 0; j < dim; j++)
	    {
	        cout << seq[j] << " ";
	    }
        cout << "\n";
        occurrence = findOccurrence (seq, 0, dim - 1, k);
        cout << "[TEST-CASE " << j << "]Occorrenze di " << k << ": " <<
	    occurrence << "\n";
    }


  return 0;
}

int findOccurrence (int *seq, int p, int r, int k)
{
    int occurrence = 0;
    if (p < r){
        int q = (p + r) / 2;
        occurrence += findOccurrence (seq, p, q, k);
        occurrence += findOccurrence (seq, q + 1, r, k);
        return occurrence;
    }
    if (seq[p] == k) return 1;
    else return 0;
}

