#include <bits/stdc++.h>
using namespace std;

int rev(int arr[], int start, int end){
    if(start >= end){
        return 0;
    } else{
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        return rev(arr,++start,--end);
    }
}

int main() {
    int arr[]= {1,2,3,4,5};
    cout<<"Before reversal: ";
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        cout << arr[i]<<" ";
    }
    rev(arr,0, sizeof(arr)/sizeof(arr[0]) - 1);
    cout << endl;
    cout<<"After reversal: ";
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        cout << arr[i]<<" ";
    }
}