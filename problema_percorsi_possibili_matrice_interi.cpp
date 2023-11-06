/*
problema 1 - 4 novembre

PROBLEMA 1
Stampare tutti i possibili percorsi dall'alto a sinistra in basso a destra di una matrice mXn con il 
vincolo che da ogni cella puoi spostarti solo a destra o in basso.

Complessita O(n!) dato che bisogna visitare ogni percorso possibile
*/


#include <iostream>
#include <vector>
using namespace std;
void solve(int **A,int n,int m,vector<int> &sol,int x,int y);
void printVector(vector<int> A);
bool isValid(int x,int y,int n,int m);
bool isComplete(int x,int y,int n,int m);
void nextMove(int x,int y,int k,int *new_x,int *new_y);

int n_dir = 2;
int dx[2] = {1,0};
int dy[2] = {0,1};
int main()
{
    int row,column;
    vector<int> sol;
    int **A;
    cout<<"Inserisci il numero di righe:";
    cin>>row;
    cout<<"Inserisci il numero di colonne:";
    cin>>column;
    A = new int*[row];
    for(int i=0;i<row;i++){
        A[i] = new int[column];
    }
    cout<<"Inserisci gli elementi:\n";
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
             cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    solve(A,row,column,sol,0,0);

    return 0;
}

void solve(int **A,int n,int m,vector<int> &sol,int x,int y){
    int new_x,new_y;
    sol.push_back(A[x][y]);
    int k=0;
    if(isComplete(x,y,n,m)) printVector(sol);
    while(k<2){
        nextMove(x,y,k,&new_x,&new_y);
        if(isValid(new_x,new_y,n,m)){
            solve(A,n,m,sol,new_x,new_y);
            sol.pop_back();
        }
        k++;
    }
}
void nextMove(int x,int y,int k,int *new_x,int *new_y){
    if(k==0){
        *new_x = x+1;
        *new_y = y;
    }else{
        *new_x = x;
        *new_y = y+1;
    }
}
    
bool isComplete(int x,int y,int n,int m){
    if(x == n-1 && y == m-1) return true;
    else return false;
}

bool isValid(int x,int y,int n,int m){
    if(x<n && y<m) return true;
    else return false;
}

void printVector(vector<int> A){
    cout<<"\n";
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}

