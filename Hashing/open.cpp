// linear probing
#include <iostream>
using namespace std;

class Hash{
    private:
    int *arr;
    int size;
    
    public:
    Hash(int size){
        this -> size = size;
        arr = new int[size];
        for(int i = 0; i < size; i++){
            arr[i] = -1;
        }
    };
    
    int hashFunc(int data){
        return data % size;
    }
    
    void insert(int data){
        int index = hashFunc(data);
        int i = 0;
        while(arr[(index + i) % size] != -1){
            i++;
            if(i == size){
                cout<<"Hash table is full";
                return;
            }
        }
        arr[(index + i) % size] = data;
    };
    
    void deleteH(int data){
        int index = hashFunc(data);
        int i = 0;
        while(arr[(index + i) % size] != -1){
            if(arr[(index + i) % size] == data){
               arr[(index + i) % size] = -1;
               return;
            }
            i++;
            if(i == size){
                cout<<data<<" Not found";
                return;
            }
        }
        cout << "Element " << data << " not found in the hash table.\n";
    };
    
        void search(int data){
        int index = hashFunc(data);
        int i = 0;
        while(arr[(index + i) % size] != -1){
            if(arr[(index + i) % size] == data){
               cout<<"value found: "<<arr[(index + i) % size];
               return;
            }
            i++;
            if(i == size){
                cout<<data<<" Not found";
                return;
            }
        }
    };
    
    void display(){
        for(int i = 0; i < size; i++){
            if(arr[i] != -1){
                cout << "[" << i << "] : " << arr[i] << endl;
            }else{
               cout << "[" << i << "] : Empty" << endl;
            }
        }
    };
    
     ~Hash() {
        delete[] arr; // Frees allocated memory
    }
    
};

int main() {
    Hash h(10);
    h.insert(23);
    h.insert(57);
    h.insert(33);
    h.insert(51);
    h.insert(29);
    h.insert(91);
    h.deleteH(91);
    h.display();
    cout<<endl;
    h.search(33);

   return 0;
}



// Quadratic Probabing
#include <iostream>
using namespace std;

class Hash{
    private:
    int *arr;
    int size;
    
    public:
    Hash(int size){
        this -> size = size;
        arr = new int[size];
        for(int i = 0; i < size; i++){
            arr[i] = -1;
        }
    };
    
    int hashFunc(int data){
        return data % size;
    }
    
    void insert(int data){
        int index = hashFunc(data);
        int i = 0;
        while(arr[(index + i*i) % size] != -1){
            i++;
            if(i == size){
                cout<<"Hash table is full";
                return;
            }
        }
        arr[(index + i*i) % size] = data;
    };
    
    void deleteH(int data){
        int index = hashFunc(data);
        int i = 0;
        while(arr[(index + i*i) % size] != -1){
            if(arr[(index + i*i) % size] == data){
               arr[(index + i*i) % size] = -1;
               return;
            }
            i++;
            if(i == size){
                cout<<data<<" Not found";
                return;
            }
        }
        cout << "Element " << data << " not found in the hash table.\n";
    };
    
        void search(int data){
        int index = hashFunc(data);
        int i = 0;
        while(arr[(index + i*i) % size] != -1){
            if(arr[(index + i*i) % size] == data){
               cout<<"value found: "<<arr[(index + i*i) % size];
               return;
            }
            i++;
            if(i == size){
                cout<<data<<" Not found";
                return;
            }
        }
    };
    
    void display(){
        for(int i = 0; i < size; i++){
            if(arr[i] != -1){
                cout << "[" << i << "] : " << arr[i] << endl;
            }else{
               cout << "[" << i << "] : Empty" << endl;
            }
        }
    };
    
     ~Hash() {
        delete[] arr; // Frees allocated memory
    }
    
};

int main() {
   Hash h(10);
   h.insert(23);
   h.insert(56);
   h.insert(33);
   h.insert(51);
   h.insert(29);
   h.insert(43);
   h.deleteH(91);
   h.display();
//   cout<<endl;
//   h.search(43);
    return 0;
}