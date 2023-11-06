/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int chiamata = 0;

bool checkRange(int x,int y,int n,int m);
bool isValid(vector<vector<int>> &lab, int x,int y);
bool findTrack(vector<vector<int>> &lab,int n,int m,vector<vector<int>> &sol,int x, int y);
void showLab(vector<vector<int>> &sol,int n,int m);

int main()
{
    int n=6;
    int m=6;
    vector<vector<int>> sol;
    /*vector<vector<int>> lab = {
                              {1,1,1,0},
                              {1,0,1,0},
                              {0,1,1,1},
                              {1,1,0,1}
    };*/
    vector<vector<int>> lab = {
                              {1,1,1,1,1,1},
                              {1,1,1,1,0,1},
                              {1,1,1,1,0,1},
                              {1,1,1,1,0,1},
                              {1,1,1,1,0,1},
                              {1,1,1,1,0,1}
    };
    sol = lab;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sol[i][j] = 0;
        }
    }
    showLab(lab,n,m);
    showLab(sol,n,m);
    findTrack(lab,n,m,sol,0,0);
    showLab(sol,n,m);
    cout<<"\nChiamate: "<<chiamata<<"\n";
    
    
    return 0;
}

bool findTrack(vector<vector<int>> &lab,int n,int m,vector<vector<int>> &sol,int x, int y){
    chiamata++;
    bool isSol = 0;    
    int new_x = 0;
    int new_y = 0;
    if(x == 0 && y == 0) sol[0][0] = 1;
    for(int dir=0;dir<2;dir++){
        if(dir == 0){
            new_x = x+1;
            new_y = y;
        }else{
            new_x = x;
            new_y = y+1;
        }
        
        if(checkRange(new_x,new_y,n,m)){
            if(isValid(lab,new_x,new_y)){
                sol[new_x][new_y] = 1;
                isSol = findTrack(lab,n,m,sol,new_x,new_y);
                if(new_x==n-1 && new_y==m-1){ 
                    isSol=1;
                }else if(!isSol)sol[new_x][new_y] = 0;
            }else{
                sol[new_x][new_y] = 0;
            }
        }
        
    }
    return isSol;
}

bool isValid(vector<vector<int>> &lab, int x,int y){
    if(lab[x][y]==1) return true;
    else return false;
}
bool checkRange(int x,int y,int n,int m){
    if(x<n && y<m) return true;
    else return false;
}

void showLab(vector<vector<int>> &sol,int n,int m){
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }
}


