#include <iostream>
using namespace std;

void downHeapify(int arr[], int n, int i){
    int largest = i;
    int LChild = 2 * i + 1;
    int RChild = 2 * i + 2;
    if (LChild < n && arr[LChild] > arr[largest]) {
        largest = LChild;
    }
    if (RChild < n && arr[RChild] > arr[largest]) {
        largest = RChild;
    }
    if (largest != i) {
       swap(arr[i], arr[largest]);
       downHeapify(arr, n, largest);
    }
    
}

int main() {
    int arr[] = {54, 53, 55, 53, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = (n / 2) - 1; i >= 0; i--) {
        downHeapify(arr, n, i);
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}