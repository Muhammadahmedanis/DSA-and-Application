#include <iostream>
using namespace std;

// class Node{
//     public:
//     int data;
//     Node* next;
//     public:
//     Node(int val){
//         data = val;
//         next = NULL;
//     }
// };

class Queue {
    int* arr;
    int size;
    int rear;
    
    public:
    Queue(int size){
        this -> size = size;
        this -> rear = -1;
        arr = new int [size];
    }
    
    bool isEmpty(){
        return rear == -1;
    }
    
    void enqueue(int val){
        if(rear == size-1){
            cout<<"Full queue";
            return;
        }
        arr[++rear] = val;
    }
    
    int dequeue(){
        if(isEmpty()){
            cout<<"queue is empty";
            return -1;
        }
        int front = arr[0];
        for(int i = 0; i < rear; i++){
            arr[i] = arr[i + 1];
        }
        rear --;
        return front;
    }
    
};


int main() {
  Queue st(3);
    st.enqueue(1);
    st.enqueue(2);
    // cout << st.pop() << " "; 
    st.enqueue(3);

    while (!st.isEmpty()) {
        cout << st.dequeue() << " ";
    }
    return 0;
}








