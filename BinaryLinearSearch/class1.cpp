#include <iostream>
using namespace std;

// Linear Search
int main() {
    int arr[] = {75, 90, 25, 98, 23, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int toSearch;
    bool flag = false;
    cout<<"Enter a number you want to search: ";
    cin>>toSearch;
    for(int i = 0; i < n; i++){
        if(arr[i] == toSearch){
            flag = true;
            break;
        }
    }
    if(flag == true){
        cout<<"Value found";
    }else{
        cout<<"value not found";
    }
}


// Linear Search and Find all occurence



#include <iostream>
using namespace std;

// Binary Search
int main() {
    int arr[] = {11, 23, 25, 75, 90, 98};  // Sorted array for binary search
    int n = sizeof(arr) / sizeof(arr[0]);
    int toSearch;
    bool flag = false;

    cout << "Enter a number you want to search: ";
    cin >> toSearch;

    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the element is present at mid
        if (arr[mid] == toSearch) {
            flag = true;
            break;
        }

        // If the element is greater, ignore the left half
        if (arr[mid] < toSearch)
            left = mid + 1;

        // If the element is smaller, ignore the right half
        else
            right = mid - 1;
    }

    if (flag) {
        cout << "Value found";
    } else {
        cout << "Value not found";
    }

    return 0;
}
