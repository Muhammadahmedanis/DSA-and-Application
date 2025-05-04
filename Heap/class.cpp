#include <iostream>
using namespace std;

class heap{
    public:
    int size;
    int* arr;
    
    heap(int val){
        size = 0;
        arr = new int[val];
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
    heap h(10);
    h.insert(19);
    h.insert(23);
    h.insert(88);
    h.insert(76);
    h.insert(120);
    h.insert(98);
    h.insert(20);
    h.insert(15);
    h.insert(18);
    h.insert(200);
    
    h.print();
    
    h.deleteFromHeap();
    cout<<endl;
    h.print();
}


// output: 200 120 98 19 88 23 20 15 18 76 
//         120 88 98 19 76 23 20 15 18 



// Min head
#include <iostream>
using namespace std;

class heap{
    public:
    int size;
    int* arr;
    
    heap(int val){
        size = 0;
        arr = new int[val];
    }
    
    void insert(int val){
        int index = size;
        arr[index] = val;
        size++;
        while(index > 0){
            int parent = (index - 1) / 2;
            if(arr[parent] > arr[index]){
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
    
            if (LChild < size && arr[LChild] < arr[largest]) {
                largest = LChild;
            }
            if (RChild < size && arr[RChild] < arr[largest]) {
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
    heap h(10);
    h.insert(19);
    h.insert(23);
    h.insert(88);
    h.insert(76);
    h.insert(120);
    h.insert(98);
    h.insert(20);
    h.insert(15);
    h.insert(18);
    h.insert(200);
    
    cout<<"Min heap: ";
    h.print();
    
    h.deleteFromHeap();
    cout<<"\nAfter delete: ";
    h.print();
}

// Mix heap: 15 18 20 19 120 98 88 76 23 200 
// After delete: 18 19 20 23 120 98 88 76 200 