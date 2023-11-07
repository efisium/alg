#include <vector>
#include <iostream>
using namespace std;
void mergeSort(int *A,int n,int p,int r,int *pos);
void merge(int *A,int n,int p,int q,int r,int *pos);

int main(){
    int n;
    cout<<"Inserisci la dimensione:";
    cin>>n;
    int *A = new int[n];
    cout<<"Inserisci gli elementi:";
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int k=0;k<n;k++){
        cout<<A[k]<<" ";
    }
    cout<<"\n";
    
    int *pos = new int[n];
    for(int k=0;k<n;k++){
        pos[k]=k;
    }
    
    mergeSort(A,n,0,n-1,pos);
    
    for(int k=0;k<n;k++){
        cout<<A[k]<<" ";
    }
    cout<<"\n";
 
    for(int k=0;k<n;k++){
        cout<<pos[k]<<" ";
    }
    cout<<"\n";


}


void mergeSort(int *A,int n,int p,int r,int *pos){
    if(p<r){
        int q=(p+r)/2;
        mergeSort(A,n,p,q,pos);
        mergeSort(A,n,q+1,r,pos);
        merge(A,n,p,q,r,pos);
    }
}

void merge(int *A,int n,int p,int q,int r,int *pos){
    //cout<<"Chiamo merge tra "<<p<<" e "<<r<<"\n";
    int dim_left = q-p+1;
    int dim_right = r-q;
    int *L = new int[dim_left];
    int *R = new int[dim_right];
    int *old_pos = new int[r+1-p];
    for(int a=p;a<(r+1);a++){
        old_pos[a-p] = pos[a]; 
    }

    for(int i=0;i<dim_left;i++){
        L[i]=A[p+i];
    }

    for(int i=0;i<dim_right;i++){
        R[i]=A[q+1+i];
    }

    int i=0,j=0,k=p;

    while(i<dim_left && j<dim_right){
        if(L[i]<=R[j]){
            A[k] = L[i];
            pos[k] = old_pos[i];
            i++;
        }else{
            A[k] = R[j];
            pos[k] = old_pos[j+q+1-p];
            j++;
        }
        k++;
    }

    while(i<dim_left){
        A[k] = L[i];
        pos[k] = old_pos[i];
        i++;
        k++;
    }
    while(j<dim_right){
        A[k] = R[j];
        pos[k] = old_pos[j+q+1-p];
        j++;
        k++;
    }
    /*cout<<"New position:";
    for(int k=0;k<n;k++){
        cout<<pos[k]<<" ";
    }
    cout<<"\n";*/

    

}
