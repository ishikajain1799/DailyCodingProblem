#include<bits/stdc++.h>
using namespace std;

void go(int *a, int n){

    // find till negative index then merge them
    int temp[100], i = 0;
    while(i < n && a[i] < 0){
        a[i] = -a[i];
        ++i;
    }

    int j = i, k = 0, mid = i;
    for(int i = 0; i < j/2; i++){
        swap(a[i], a[j-i-1]);
    }

    i = 0;
    // that's why I need to reverse the array because 
    // it's not sorted


    while(j < n && i < mid){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        }
        else    temp[k++] = a[j++];
    }

    while(i < mid){
        temp[k++] = a[i++];
    }
    while(j < n){
        temp[k++] = a[j++];
    }

    for(int i = 0; i < n; i++){
        a[i] = temp[i]*temp[i];
    }

}

int main(){

    int a[] = {-9,-2,0,2,3};
    int n = 5;

    go(a,n);
    
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    

}