/*
Complessità O(n);
*/
#include <iostream>
#include <vector>
using namespace std;
bool findJolly(int *A,vector<int>&sol,int p,int r,int n);
bool checkValue(int *A,vector<int>&sol,int x,int y,int n);
int main()
{
    
    int B[5]={5,1,4,2,3};
    int n=5;
    int C[6]={5,1,4,2,-1,6};
    
    
    int *A = new int[n];
    vector<int> sol;
    for(int k=0;k<n;k++){
        sol.push_back(0);
    }
    A = B;
    
    if(findJolly(A,sol,0,n-1,n)){
        for(int a=1;a<n;a++){
            if(sol[a]==0) return 1;
        }
        cout<<"Jolly\n";
    }
    /*
    else cout<<"Not Jolly\n";
    A=C;
    n=6;
    if(findJolly(A,0,n-1,n)){
        cout<<"Jolly\n";
    else cout<<"Not Jolly\n";
    */
    return 0;
}

bool findJolly(int *A,vector<int> &sol,int p,int r,int n){
    bool checked = 1;
    if(p<r){
        int q=(p+r)/2;
        checked *= findJolly(A,sol,p,q,n);
        checked *= findJolly(A,sol,q+1,r,n);
        if(checked == 1){
            if(p==q){ 
                checked = checkValue(A,sol,p,r,n);
            }else {
                checked = checkValue(A,sol,q,q+1,n);
            }
        }
        return checked;
    }
    return 1;
}

bool checkValue(int *A,vector<int> &sol,int x,int y,int n){
    
    int value = abs(A[x]-A[y]);
    cout<<"Check ("<<x<<","<<y<<") value:"<<value<<"\n";
    if(value<n && value >0){
        sol[value] = 1;
        return true;
    }
    else return false;
}



