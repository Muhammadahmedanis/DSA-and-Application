#include <iostream>
using namespace std;

void downHeapify(int arr[], int n, int i){
    int parent = i;
    int LChild = 2*i + 1;
    int RChild = 2*i + 2;
    
    if(LChild < n && arr[LChild] < arr[parent]){
        parent = LChild;
    }
    if(RChild < n && arr[RChild] < arr[parent]){
        parent = RChild;
    }
    
    if(parent != i){
        swap(arr[parent], arr[i]);
        downHeapify(arr, n, parent);
    }
}

void heapSort(int arr[], int n){
    int t = n -1;
    while( t > 0){
        swap(arr[0], arr[t]);
        t--;
        downHeapify(arr, t, 0);
    }
}


// Output: Max heap: 200 98 120 88 76 23 20 19 18 15 

int main() {
    int arr[] = {19, 23, 88, 76, 120, 98, 20, 15, 18, 200};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = (n / 2)-1; i >= 0; i--){
        downHeapify(arr, n, i);
    }
    
    heapSort(arr, n);
    cout<<"Max heap: ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";    
    }
    
    return 0;
}







#include <iostream>
using namespace std;

void downHeapify(int arr[], int n, int i){
    int parent = i;
    int LChild = 2*i + 1;
    int RChild = 2*i + 2;
    
    if(LChild < n && arr[LChild] > arr[parent]){
        parent = LChild;
    }
    if(RChild < n && arr[RChild] > arr[parent]){
        parent = RChild;
    }
    
    if(parent != i){
        swap(arr[parent], arr[i]);
        downHeapify(arr, n, parent);
    }
}

void heapSort(int arr[], int n){
    int t = n -1;
    while( t > 0){
        swap(arr[0], arr[t]);
        t--;
        downHeapify(arr, t, 0);
    }
}

// output: Min heap: 15 18 19 20 23 76 88 98 120 200 

int main() {
    int arr[] = {19, 23, 88, 76, 120, 98, 20, 15, 18, 200};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = (n / 2)-1; i >= 0; i--){
        downHeapify(arr, n, i);
    }
    
    heapSort(arr, n);
    cout<<"Min heap: ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";    
    }
    
    return 0;
}









// #include <iostream>
// using namespace std;

// void downHeapify(int arr[], int n, int i){
//     int largest = i;
//     int LChild = 2 * i + 1;
//     int RChild = 2 * i + 2;
//     if (LChild < n && arr[LChild] > arr[largest]) {
//         largest = LChild;
//     }
//     if (RChild < n && arr[RChild] > arr[largest]) {
//         largest = RChild;
//     }
//     if (largest != i) {
//        swap(arr[i], arr[largest]);
//        downHeapify(arr, n, largest);
//     }
// }

// void heapSort(int arr[], int n){
//     int t = n-1;
//     while(t > 0){
//         swap(arr[t], arr[0]);
//         t--;
//         downHeapify(arr, t, 0);
//     }
// }

// int main() {
//     int arr[] = {19, 23, 88, 76, 120, 98, 20, 15, 18, 200};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     for (int i = (n / 2) - 1; i >= 0; i--) {
//         downHeapify(arr, n, i);
//     }
//      for(int i = 0; i < n; i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     heapSort(arr, n);
//     for(int i = 0; i < n; i++){
//         cout<<arr[i]<<" ";
//     }
    
//     return 0;
// }