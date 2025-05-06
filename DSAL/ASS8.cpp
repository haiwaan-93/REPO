// Implement the Heap Sort algorithm demonstrating the Heap / Shell data structure with modularity of programming language.

#include<bits/stdc++.h>
using namespace std;

int* heapify(int a[], int n){
    for (int i = n-1 ; i < 0 ; i--){
        int j = (i-1)/2;
        if (!(a[j]>a[i])){
            swap(a[j],a[i]);
        }
    }
    return a;
}

int* heapsort(int a[], int n){
    int j = n;
    int reta[n];
    int i = 0;
    while(j>0){
    j-=1;
    a = heapify(a);
    reta[i]=a[0];
    swap(a[0], a[j]);
    i+=1;
    }
    return reta;
}


int main(){
    int a[] = {23,54,2,42,113,4,56,7,5,67,34,78,45,67,34};
    a = heapsort(a, 15);
    for(int i = 0 ; i < sizeof(a) ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}



