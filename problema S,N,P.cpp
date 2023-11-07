/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
int sumElement(vector<int> sol);
bool isComplete(vector<int> sol,int N);
bool solve(vector<int> &sol, int S, int N, int P);
void showVector(vector<int> sol);
bool isPrime(int num);
int findPrime(int num);
int call = 0;
int main()
{
    vector<int> sol;
    int S,N,P;
    cout<<"Inserisci i valori:\n";
    cin>>S;
    cin>>N;
    cin>>P;
    cout<<"Chiamo solve("<<S<<","<<N<<","<<P<<")\n";
    if(solve(sol,S,N,P)) showVector(sol);
    else cout<<"Impossibile trovare la sequenza\n";
    return 0;
}

bool solve(vector<int> &sol, int S, int N, int P){
    call = call + 1;
    int x = findPrime(P+1);
    int sum_elem = sumElement(sol);
    //cout<<"valore P:"<<P<<" n.primo:"<<x<<"\n";
    while(x<=(S-/*((P+1)*sol.size())*/sum_elem)){
        sol.push_back(x);
        //showVector(sol);
        if(isComplete(sol,N) && sum_elem+x==S) return true;
        else if(solve(sol,S,N,P)) return true;
        else if(sum_elem+x>S) return false;
        sol.pop_back();
        x = findPrime(x+1);
    }
    return false;
}

bool isComplete(vector<int> sol,int N){
   if(sol.size()==N) return true;
   else return false;
    
}
int sumElement(vector<int> sol){
    int sum=0;
    if(!sol.empty()){
        for(int i=0;i<sol.size();i++){
            sum  = sum + sol[i];
        }
    }
    return sum;
}

void showVector(vector<int> sol){
    cout<<"Sequenza: ";
    cout<<"\n";
    for(int i=0;i<sol.size();i++){
        cout<<sol[i]<<" ";
    }
    cout<<"\n";
}

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }

    return true;
}

int findPrime(int num){
    int value = num;
    while(1){
        if(isPrime(value)) return value;
        else value++;
    }
}
