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