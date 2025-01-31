#include <iostream>
#include <vector>
using namespace std;

// void selectionSort(int arr[], int n){
//     for(int i = 0; i < n-1; i++){
//         for(int j = i; j < n; j++){
//             if(arr[j] < arr[i]){
//                 int temp = arr[j];
//                 arr[j] = arr[i];
//                 arr[i] = temp;
//             }
//         }
//     }
// }
// int main() {
//     int arr[] = {13, 46, 24, 52, 20, 9};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     selectionSort(arr, n);
//     cout<<"Selection Sorted Array: ";
//     for(int i = 0; i < n; i++){
//         cout<<arr[i]<<" ";
//     }
// }





// void bubbleSort(int arr[], int n){
//     for(int i = n-1; i > 0; i--){
//         for(int j = 0; j < i; j++){
//             if(arr[j] > arr[j + 1]){
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
// }
// int main() {
//     int arr[] = {13, 46, 24, 52, 20, 9};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     bubbleSort(arr, n);
//     cout<<"Bubble Sorted Array: ";
//     for(int i = 0; i < n; i++){
//         cout<<arr[i]<<" ";
//     }
// }





// void insertionSort(int arr[], int n){
//     for(int i = 1; i < n; i++){
//         int j = i;
//         while(j > 0 && arr[j-1] > arr[j]){
//             int temp = arr[j];
//             arr[j] = arr[j-1];
//             arr[j-1] = temp;
//             j--;
//         }
//     }
// }
// int main() {
//     int arr[] = {13, 46, 24, 52, 20, 9};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     insertionSort(arr, n);
//     cout<<"Insertion Sorted Array: ";
//     for(int i = 0; i < n; i++){
//         cout<<arr[i]<<" ";
//     }
// }




// void mergeSort(vector<int> &arr, int low, int mid, int high){
//     vector<int> temp;
//     int left = low;
//     int right = mid + 1;
//     while(left <= mid && right <= high){
//         if(arr[left] <= arr[right]){
//             temp.push_back(arr[left]);
//             left++;
//         }else{
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }
//     while(left <= mid){
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while(right <= high){
//         temp.push_back(arr[right]);
//         right++;   
//     }
//     for(int i = low; i <= high; i++){
//         arr[i] = temp[i - low];
//     }
// }




// int partition(vector<int> &arr, int start, int end){
//     int mid = (start + end) / 2;
//     int index = start -1;
//     int pivot = arr[mid]; 
//     swap(arr[mid], arr[end]);
//     for(int j = start; j < end; j++){
//         if(arr[j] <= pivot) {
//             index++;
//             swap(arr[index], arr[j]);
//         }
//     }
//     index++;
//     swap(arr[end], arr[index]);
//     return index;
// }

// void quickSort(vector<int> &arr, int start, int end){
//     if(start < end){
//         int pivotIndex = partition(arr, start, end);
//         quickSort(arr, start, pivotIndex-1);
//         quickSort(arr, pivotIndex+1, end);
//     }
// }

// int main() {
//     vector<int> arr = {5, 2, 6, 4, 1, 3};
//     quickSort(arr, 0, arr.size()-1);
//     cout << "Sorting Array: ";
//     for(int num : arr){
//         cout << num <<" ";
//     }
// }





// void ms(vector<int> &arr, int low , int high){
//     if(low == high) return;
//     int mid = (low + high) / 2;
//     ms(arr, low, mid);
//     ms(arr, mid+1, high);
//     mergeSort(arr, low, mid, high);
// }

// int main() {
//     vector<int> arr = {3, 1, 2, 4, 1, 5, 2, 6, 4};
//     ms(arr, 0, arr.size()-1);
//     cout << "Sorting Array: ";
//     for(int num : arr){
//         cout << num <<" ";
//     }
// }
