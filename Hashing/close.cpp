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