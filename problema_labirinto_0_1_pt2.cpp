/*
homeworks_set_2_A2
Labirinto con 0 e 1

Si consideri il seguente problema di minimo percorso vincolato. Sia data una matrice 
rettangolare di 1 e 0, in cui 1 indica una cella che è possibile percorrere e 0 una cella che 
non è possibile percorrere. Inoltre, si assuma che non è possibile percorrere neanche le 
quattro celle adiacenti (sinistra, destra, sopra e sotto) ad una cella che contiene uno 0. 
Calcolare la lunghezza del più breve percorso possibile da qualsiasi cella nella prima 
colonna a qualsiasi cella nell'ultima colonna della matrice. L’obiettivo è evitare le celle 
contrassegnate con 0 e le loro quattro celle adiacenti (sinistra, destra, sopra e sotto). 
Le mosse possibili da una determinata cella sono lo spostamento di una cella adiacente a 
sinistra, destra, sopra o sotto (non sono consentiti spostamenti in diagonale). 

*/
#include <iostream>
#include <vector>

using namespace std;
typedef struct{
    int row;
    int col;
}Node;
void findTrack(int **A,int n,int m);
void solve(int **A,int n,int m,vector<Node> &sol,int x,int y,int *sum,int *tmp_sum,vector<Node> &def_sol);;
void makeMove(int x,int y,int k,int *new_x,int *new_y);
bool isValid(int **A,vector<Node> &sol,int n,int m,int x,int y);

void showVector(vector<Node> def_sol,int tmp_sum,int sum);

int main()
{
    
    int n=10;
    int m=6;
    int **A = new int*[n];
    for(int i=0;i<n;i++){
        A[i] = new int[m];
    }

    int C[10][6]{
                {1,0,1,0,1,0},
                {1,0,1,1,0,0},
                {0,1,1,1,0,0},
                {1,1,1,1,1,0},
                {0,1,1,1,1,1},
                {1,0,1,1,1,1},
                {0,0,1,1,1,1},
                {0,1,1,1,0,0},
                {0,1,1,1,0,0},
                {1,0,1,0,0,0}
    };
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            A[i][j]=C[i][j];
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
    findTrack(A,n,m);

    return 0;
}

void findTrack(int **A,int n,int m){
    vector<Node> sol;
    vector<Node> def_sol;
    int sum = 0;
    int tmp_sum = 0;
    for(int i=0;i<n;i++){
        sol.clear();
        tmp_sum = 0;
        if(A[i][0]==1){
            solve(A,n,m,sol,i,0,&sum,&tmp_sum,def_sol);
            
        }
    }
    cout<<"\n";
    cout<<"Track:";
    for(int k=0;k<def_sol.size();k++){
        cout<<"("<<def_sol[k].row<<","<<def_sol[k].col<<") ";
    }
    cout<<"\n";

}

void solve(int **A,int n,int m,vector<Node> &sol,int x,int y,int *sum,int *tmp_sum,vector<Node> &def_sol){
    Node k;
    int move=0;
    int new_x,new_y;
    
    while(move<4){
        makeMove(x,y,move,&new_x,&new_y);
        if(isValid(A,sol,n,m,new_x,new_y)){
            k.row = new_x;
            k.col = new_y;
            sol.push_back(k);
            *tmp_sum++;
            if(new_y==m-1){
                if(tmp_sum>sum){
                    
                    sum = tmp_sum;
                    def_sol = sol;
                    //showVector(def_sol,*tmp_sum,*sum);
                }
            }
            solve(A,n,m,sol,new_x,new_y,sum,tmp_sum,def_sol);
            *tmp_sum--;
            sol.pop_back();
        }
        move++;
        
    }
}

void makeMove(int x,int y,int k,int *new_x,int *new_y){
    switch(k){
        case 0:
        {
            *new_x = x + 1; 
            *new_y = y;
        }break;
        case 1:
        {
            *new_x = x - 1; 
            *new_y = y;
            
        }break;
        case 2:
        {
            *new_x = x; 
            *new_y = y + 1;

        }break;
        case 3:
        {
            *new_x = x; 
            *new_y = y - 1;
        
            
        }break;
    }
}


bool isValid(int **A,vector<Node> &sol,int n,int m,int x,int y){
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int i,j;
    if(!sol.empty()){
        for(int b=0;b<sol.size();b++)
        if(x==sol[b].row && y==sol[b].col) return false;
    }
    if(x<n && x>=0 && y<m && y>=0){
        if(A[x][y] == 1){
            
            for(int a=0;a<4;a++){
                i=x+dx[a];
                j=y+dy[a];
                if(i>=0 && i<n && j>=0 && j<m){
                    if(A[i][j] == 0)return false;
                }
            }
            
            return true;
        }   
    }
    return false;
}

void showVector(vector<Node> def_sol,int tmp_sum,int sum){
    cout<<"New Track"/*<<"Temp sum:"<<tmp_sum*/<<", Sum:"<<sum/*<<" ("<<i<<","<<j<<") "*/;
    for(int k=0;k<def_sol.size();k++){
        cout<<"("<<def_sol[k].row<<","<<def_sol[k].col<<") ";
    }
    cout<<"\n";
    
}



