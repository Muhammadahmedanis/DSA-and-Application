// LINEAR-PROBABING

// #include <iostream>
// using namespace std;

// struct Hash{
//     int* arr;
//     int size;
    
//     Hash(int size){
//         this -> size = size;
//         arr = new int[size];
//         for(int i = 0; i < size; i++){
//             arr[i] = -1;
//         }
//     }
    
//     int hashFunc(int data){
//         return data % size;
//     }
    
//     void insert(int data){
//         int index = hashFunc(data);
//         int i = 0; 
//         while(arr[(index + i) % size] != -1){
//             i++;
//             if(i == size){
//                 cout<<"Hash table full";
//                 return;
//             }
//         }
//         arr[(index + i) % size] = data;
//     };
    
//     void deleteH(int data){
//       int index = hashFunc(data);
//       int i = 0;
//       while(arr[(index + i) % size] != -1){
//           if(arr[(index + i) % size] == data){
//               arr[(index + i) % size] = -1;
//               return;
//           }
//           i++;
//           if(i == size){
//                 cout<<"Hash table full and value not found";
//                 return;
//             }
//       }
//       cout<<"given input not fount "<<data;
//     }
    
    
//     void search(int data){
//       int index = hashFunc(data);
//       int i = 0;
//       while(arr[(index + i) % size] != -1){
//           if(arr[(index + i) % size] == data){
//               cout<<"\nValue found "<<arr[(index + i) % size];
//               return;
//           }
//           i++;
//           if(i == size){
//                 cout<<"Hash table full and value not found";
//                 return;
//             }
//       }
//       cout<<"given input not fount "<<data;
//     }
    
//     void display(){
//         for(int i = 0; i < size; i++){
//             if(arr[i] != -1){
//                 cout << "[" << i << "] : " << arr[i] << endl;
//             }else{
//                 cout << "[" << i << "] : Empty" << endl;
//             }
//         }
//     }
// };

// int main() {
//     Hash h(10);
//     h.insert(23);
//     h.insert(28);
//     h.insert(76);
//     h.insert(19);
//     h.insert(34);
//     h.insert(10);
//     h.insert(52);
//     h.deleteH(10);
//     h.display();
//     h.search(44);
//     return 0;
// }




// QUADRATIC-PROBABING

// #include <iostream>
// using namespace std;

// struct Hash{
//     int* arr;
//     int size;
    
//     Hash(int size){
//         this -> size = size;
//         arr = new int[size];
//         for(int i = 0; i < size; i++){
//             arr[i] = -1;
//         }
//     }
    
//     int hashFunc(int data){
//         return data % size;
//     }
    
//     void insert(int data){
//         int index = hashFunc(data);
//         int i = 0; 
//         while(arr[(index + i*i) % size] != -1){
//             i++;
//             if(i == size){
//                 cout<<"Hash table full";
//                 return;
//             }
//         }
//         arr[(index + i*i) % size] = data;
//     };
    
//     void deleteH(int data){
//       int index = hashFunc(data);
//       int i = 0;
//       while(arr[(index + i*i) % size] != -1){
//           if(arr[(index + i*i) % size] == data){
//               arr[(index + i*i) % size] = -1;
//               return;
//           }
//           i++;
//           if(i == size){
//                 cout<<"Hash table full and value not found";
//                 return;
//             }
//       }
//       cout<<"given input not fount "<<data;
//     }
    
    
//     void search(int data){
//       int index = hashFunc(data);
//       int i = 0;
//       while(arr[(index + i*i) % size] != -1){
//           if(arr[(index + i*i) % size] == data){
//               cout<<"\nValue found "<<arr[(index + i*i) % size];
//               return;
//           }
//           i++;
//           if(i == size){
//                 cout<<"Hash table full and value not found";
//                 return;
//             }
//       }
//       cout<<"given input not fount "<<data;
//     }
    
//     void display(){
//         for(int i = 0; i < size; i++){
//             if(arr[i] != -1){
//                 cout << "[" << i << "] : " << arr[i] << endl;
//             }else{
//                 cout << "[" << i << "] : Empty" << endl;
//             }
//         }
//     }
// };

// int main() {
//     Hash h(10);
//     h.insert(23);
//     h.insert(28);
//     h.insert(76);
//     h.insert(19);
//     h.insert(34);
//     h.insert(10);
//     h.insert(52);
//     h.deleteH(10);
//     h.display();
//     h.search(44);
//     return 0;
// }







// DOUBLE-HASHING

// class doubleHashing{
//     int* arr;
//     int size;
    
//     public:
//     doubleHashing(int size){
//         this -> size = size;
//         arr = new int[size];
//         for(int i = 0; i < size; i++){
//             arr[i] = -1;
//         }
//     };
    
    
//     int hash1(int data){
//         return data % size;
//     };
    
//     int hash2(int data){
//         return size - (data % size);
//     };
    
    
//     void insert(int data){
//         int index = hash1(data);
//         if(arr[index] == -1){
//             arr[index] = data;
//             return;
//         }
//         int i = 1;
//         while(i < size){
//             int newIndex = (index + i * hash2(data)) % size;
//             if(arr[newIndex] == -1){
//                 arr[newIndex] = data;
//                 return;
//             }
//             i++;
//         }
//     };
    
    
//     void search(int data){
//         int index = hash1(data);
//         int i = 0;
//         while(arr[(index + i * hash2(data)) % size] != -1){
//             if(arr[(index + i * hash2(data)) % size] == data){
//                 cout<<"Value found";
//                 return;
//             }
//             i++;
//              if(i == size){
//                 cout<<"Hash table is full value not found";
//                 return;
//             }
//         }
//         cout<<"given input not fount"<<data;
//     };
    
    
    
//     void deleteH(int data){
//         int index = hash1(data);
//         int i = 0;
//         while(arr[(index + i * hash2(data)) % size] != -1){
//             if(arr[(index + i * hash2(data)) % size] == data){
//                 arr[(index + i * hash2(data)) % size] = -1;
//                 return;
//             }
//             i++;
//              if(i == size){
//                 cout<<"Hash table is full value not found";
//                 return;
//             }
//         }
//          cout<<"given input not fount"<<data;
//     };
    
    
    
//     void display(){
//         for(int i = 0; i < size; i++){
//             if(arr[i] != -1){
//                 cout << "[" << i << "] : " << arr[i] << endl;
//             }else{
//                 cout << "[" << i << "] : Empty" << endl;
//             }
//         }
//     };
    
// };


// int main() {
//     doubleHashing h(10);
//     h.insert(21);
//     h.insert(28);
//     h.insert(76);
//     h.insert(19);
//     h.insert(34);
//     h.insert(10);
//     h.insert(52);
//     h.deleteH(10);
//     h.display();
//     h.search(34);
//     return 0;
// }



// class DoubleHashing{    
//     void insert(int data){
//         int index =  hash1(data);
//         if(table[index] == -1){
//             table[index] = data;
//             return;
//         }
        
//         int i = 0;
//         while(i < size){
//             int newIndex = (index + i * hash2(data)) % size;
//             if(table[newIndex] == -1){
//                 table[newIndex] = data;
//                 return;
//             }
//             i++;
//         }
//     }    
    
// };