/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <vector>
#include <iostream>
using namespace std;

long int entro = 0;
typedef struct{
    int row;
    int col;
}Node;
/*
int dx[8]={2,1,-1,-2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};*/
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool checkPosition(int **A,int n);
void backtrack();
bool solve(vector<Node> &sol,int **A,int n,int x,int y);
bool isValid(int **A,int n,int new_x,int new_y);
void makeMove(int x,int y,int move,int *new_x,int *new_y);
void showVector(vector<Node> tmp);


int main()
{
    backtrack();

    return 0;
}

void backtrack(){
    int n = 8;
    vector<Node> sol;
    int **A = new int*[n];
    for(int k=0;k<n;k++){
        A[k] = new int[n];
    }
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            A[a][b] = 0;
        }   
    }
    sol.clear();
    cout<<"Vamo\n";
    entro = 0;
    solve(sol,A,n,1,1);
    cout<<"Finito\n";
    showVector(sol);
    /*
    cout<<"Finito\n";
    if(checkPosition(A,n)){
        cout<<"Corretto ("<<i<<","<<j<<")["<<sol.size()<<"]"<<entro<<"\n";
        showVector(sol);
    }*/
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            for(int a=0;a<n;a++){
                for(int b=0;b<n;b++){
                    A[a][b] = 0;
                }   
            }
            sol.clear();
            cout<<"Vamo\n";
            entro = 0;
            solve(sol,A,n,i,j);
            
            cout<<"Finito\n";
            if(checkPosition(A,n)){
                cout<<"Corretto ("<<i<<","<<j<<")["<<sol.size()<<"]"<<entro<<"\n";
                showVector(sol);
            }
        }
    }
    */
}

bool checkPosition(int **A,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]!=1) return false;
        }
    }
    return true;
}

bool solve(vector<Node> &sol,int **A,int n,int x,int y){
    int move = 0;
    Node k;
    int new_x,new_y;
    
    if(sol.empty()){
        A[x][y] = 1;
        k.row = x;
        k.col = y;
        sol.push_back(k);
    }
    
    cout<<"Chiamata:"<<sol.size()<<"\n";
    if(sol.size()==64){
        return true;
    }
    
    while(move<8){
        makeMove(x,y,move,&new_x,&new_y);
        if(isValid(A,n,new_x,new_y)){
            A[new_x][new_y] = 1;
            k.row = new_x;
            k.col = new_y;
            sol.push_back(k);
            
            if(solve(sol,A,n,new_x,new_y)) {
                return true;
            }
            entro++;
            sol.pop_back();
            A[new_x][new_y] = 0;
        }
        move++;
    }
    return false;
    
}

bool isValid(int **A,int n,int new_x,int new_y){
    if(new_x>= 0 && new_x<n && new_y>= 0 && new_y<n){
        if(A[new_x][new_y] == 0)return true;
    }
    return false;
}

void makeMove(int x,int y,int move,int *new_x,int *new_y){
    
    *new_x = x + dx[move];
    *new_y = y + dy[move];
    
}
void showVector(vector<Node> tmp){
    int O[8][8] = {0};
    
    
    //cout<<"New Track: ";
    for(int k=0;k<tmp.size();k++){
        O[tmp[k].row][tmp[k].col] = 1;
        //cout<<"("<<tmp[k].row<<","<<tmp[k].col<<") ";
    }
    cout<<"\n";
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<O[i][j]<<" ";
        }
    
        cout<<"\n";
    }
    cout<<"\n";
    
}
