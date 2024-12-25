#include <iostream>
using namespace std;

int main() {
    int arr[]= {5,2,3,4,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<n; i++){
        int minIndex = i;
        for(int j = i; j< n; j++){
            if(arr[minIndex] > arr[j]) minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    
    
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}

