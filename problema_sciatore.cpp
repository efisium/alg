/*
problema 3 - 4 novembre
problema sciatore
Longest Run on a Snowboard
complessità O(4^(n*m))
*/
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int row;
    int column;
    int value;
}Node;

void findLongestTrack(int **A,int n,int m);
void showVector(vector<Node> tmp,int tmp_sum,int sum);
void nextNode(int x,int y,int k,int *new_x,int *new_y);
bool isValid(int **A,int n,int m,int x,int y,int new_x,int new_y);
void solve(vector<Node> &sol,vector<Node> &tmp,int **A,int n,int m,int *sum,int *tmp_sum,int x,int y);



int main()
{
    int sum=0;
    int tmp_sum=0;
    vector<Node> tmp;
    int n=10;
    int m=5;
    int **A = new int*[n];
    for(int i=0;i<n;i++){
        A[i] = new int[m];
    }
    /*
    A[5][5]={
               {1,2,3,4,5},
                {16,17,18,19,6},
                {15,24,25,20,7},
                {14,23,22,21,8},
                {13,12,11,10,9}
    */
    int B[5][5]={
            {1,2,3,4,5},
            {16,17,18,19,6},
            {15,24,25,20,7},
            {14,23,22,21,8},
            {13,12,11,10,9}
    };
    int C[10][5]{
                {56,14,51,58,88},
                {26,94,24,39,41},
                {24,16,8,51,51},
                {76,72,77,43,10},
                {38,50,59,84,81},
                {5,23,37,71,77},
                {96,10,93,53,82},
                {94,15,96,69,9},
                {74,0,62,38,96},
                {37,54,55,82,38}
    };
    srand(time(NULL));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            A[i][j]=/*rand()%30;*/C[i][j];
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    findLongestTrack(A,n,m);
    return 0;
}

void findLongestTrack(int **A,int n,int m){
    int sum=0;
    int tmp_sum=0;
    vector<Node> tmp;
    vector<Node> sol;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tmp.clear();
            tmp_sum = 0;
            solve(sol,tmp,A,n,m,&sum,&tmp_sum,i,j);
            
        }
    }
    showVector(sol,0,sum);
}



void solve(vector<Node> &sol,vector<Node> &tmp,int **A,int n,int m,int *sum,int *tmp_sum,int x,int y){
    Node a;
    int choice = 0;
    int new_x, new_y;
    while(choice<4){
        nextNode(x,y,choice,&new_x,&new_y);
        if(isValid(A,n,m,x,y,new_x,new_y)){
            a.row = new_x;
            a.column = new_y;
            a.value = A[new_x][new_y];
            tmp.push_back(a);
            *tmp_sum = *tmp_sum+1;
            solve(sol,tmp,A,n,m,sum,tmp_sum,new_x,new_y);
            *tmp_sum = *tmp_sum-1;
            tmp.pop_back();
        }
        choice++;
    }
    if(*sum<*tmp_sum){ 
        *sum = *tmp_sum;
        sol = tmp;
    }
    //showVector(tmp,*tmp_sum,*sum);
}

void nextNode(int x,int y,int k,int *new_x,int *new_y){
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

bool isValid(int **A,int n,int m,int x,int y,int new_x,int new_y){
    if(new_x<n && new_y<m && new_x >= 0 && new_y >= 0){
        if(A[x][y] > A[new_x][new_y]){
            return true;
        }
    }
    return false;
}

void showVector(vector<Node> tmp,int tmp_sum,int sum){
    cout<<"New Track"/*<<"Temp sum:"<<tmp_sum*/<<", Sum:"<<sum/*<<" ("<<i<<","<<j<<") "*/;
    for(int k=0;k<tmp.size();k++){
        cout<<"("<<tmp[k].value<<")";
    }
    cout<<"\n";
    
}










