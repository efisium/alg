/*
problema 2 - 4 novembre
Queens problem

Complessita temporale O(n!)
*/
#include <vector>
#include <iostream>
using namespace std;
typedef struct{
    int row;
    int column;
}Node;


int solve(int n,vector<Node> &sol,int x,int y);
bool isValid(vector<Node> sol,int x,int y,int n);
void showVector(vector<Node>sol);
void newMove(int x,int y,int k,int *new_x,int *new_y);

int main()
{
    
    vector<Node> sol;
    int n = 4;
    cout<<"N. modi:"<<solve(n,sol,0,0);
    return 0;
}



int solve(int n,vector<Node> &sol,int x,int y){
    Node c;
    int sum = 0;
    int k=0;
    int new_x,new_y;
    
    while(k<n){
        newMove(x,y,k,&new_x,&new_y);
        if(isValid(sol,new_x,new_y,n)){
            c.row = new_x;
            c.column = new_y;
            sol.push_back(c);
            if(sol.size()==n){ /*isCompleted()*/
                sum++;
                showVector(sol);
            }
            sum += solve(n,sol,0,new_y+1);
            sol.pop_back();
        }
        k++;
    }
    return sum;
}

void newMove(int x,int y,int k,int *new_x,int *new_y){
    *new_x = x+k;
    *new_y = y;
}

bool isValid(vector<Node> sol,int x,int y,int n){
    if(sol.empty())return true;
    for(int k=0;k<sol.size();k++){
        if(sol[k].row == x /*|| sol[k].column == y*/) return false;
        
        for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
            if (sol[k].row == i && sol[k].column == j)return false;
        }
        
        for (int i = x, j = y; i < n && j>=0/*j < n*/; i++, j--) {
            if (sol[k].row == i && sol[k].column == j)return false;
        }
        
    }
    return true;
    
}

void showVector(vector<Node>sol){
    for(int i=0;i<sol.size();i++){
        cout<<"("<<sol[i].row<<","<<sol[i].column<<") ";
    }
    cout<<"\n";
}



