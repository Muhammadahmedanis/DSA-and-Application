#include <iostream>
using namespace std;

class heap{
    public:
    int size;
    int arr[10];
    
    heap(){
        size = 0;
    }
    
    void insert(int val){
        int index = size;
        arr[index] = val;
        size++;
        while(index > 0){
            int parent = (index - 1) / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else {
                return;
            }
        }
    };
    
    
    void deleteFromHeap(){
        if(size <= 0){
            cout<<"Cannot delete node";
            return;
        };
        arr[0] = arr[size-1];
        size--;
         int i = 0;
        while (i < size) {
            int LChild = 2 * i + 1;
            int RChild = 2 * i + 2;
            int largest = i;
    
            if (LChild < size && arr[LChild] > arr[largest]) {
                largest = LChild;
            }
            if (RChild < size && arr[RChild] > arr[largest]) {
                largest = RChild;
            }
    
            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }
    
    void print(){
        for(int i = 0; i < size; i++){
            cout<<arr[i]<<" ";
        }
    }
    
};

int main() {
    heap h;
    h.insert(54);
    h.insert(53);
    h.insert(55);
    h.insert(52);
    h.insert(50);
    h.print();
    h.deleteFromHeap();
    cout<<endl;
    h.print();
}