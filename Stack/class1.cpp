#include <iostream>
using namespace std;

// using array
class Stack {
    int size;
    int top;
    int *arr;
    
    public: 
    Stack(int size){
        this -> size = size;
        this -> top = -1;
        arr = new int [size];
    }
    
    bool isEmpty(){
        return top == -1;
    }
    
    void push(int val){
        if(top == size-1){
            cout <<"stack overflow";
            return;
        }
        arr[++top] = val;
    }
    
    int pop(){
        if(isEmpty()){
            cout<<"stack underflow";
            return -1;
        }
        return arr[top--]; 
    }
    
};


int main() {
    Stack st(2);
    st.push(1);
    st.push(2);
    cout<<st.pop()<< " ";
    
    // while(!st.isEmpty()){
    //     cout<<st.pop()<<" ";
    // }
    st.push(3);
    cout<<st.pop()<<" ";
    cout<<st.pop()<<" ";
}



//  using dynamic
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int val){
        data = val;
        next = NULL;
    }
};

class Stack {
    Node* top;
    
    public:
    Stack(){
        top = NULL;
    }   
    
    bool isEmpty(){
        return top == NULL;
    }
    
    void push(int val){
        Node* newNode = new Node(val);
        if(isEmpty()){
            top = newNode;
            return;
        }
        newNode -> next = top;
        top = newNode;
    }
    
    int pop(){
        if(isEmpty()){
            cout<<"stack underflow";
            return -1;
        }
        Node* toRemove = top;
        int result = toRemove -> data;
        top = top -> next;
        delete toRemove;
        return result;
    }
    
};


int main() {
  Stack st;
    st.push(1);
    st.push(2);
    cout << st.pop() << " "; 
    st.push(3);

    while (!st.isEmpty()) {
        cout << st.pop() << " ";
    }
    return 0;
}



















// #include <iostream>
// using namespace std;

// class Stack {
//     int size;
//     int *arr;
//     int top; 

// public:
//     Stack(int size) {
//         this->size = size;
//         arr = new int[size];
//         top = -1; 
//     }


//     void push(int data) {
//         if (top == size - 1) { 
//             cout << "Stack overflow" << endl;
//             return;
//         }
//         arr[++top] = data; 
//     }

//     int pop() {
//         if (top == -1) { 
//             cout << "Stack underflow" << endl;
//             return -1; 
//         }
//         return arr[top--]; 
//     }

//     void display() {
//         if (top == -1) {
//             cout << "Stack is empty" << endl;
//             return;
//         }
//         cout << "Stack elements: ";
//         for (int i = 0; i <= top; i++) {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
// };

// int main() {
//     Stack st(3);
    
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);

//     st.display();

//     cout << "Popped: " << st.pop() << endl;
//     cout << "Popped: " << st.pop() << endl;
//     cout << "Popped: " << st.pop() << endl;
//     cout << "Popped: " << st.pop() << endl; 

//     return 0;
// }


























// #include <iostream>
// using namespace std;
// class queue{
//     int *arr;
//     int rear = -1;
//     int size;
    
//     public:
//     queue(int size){
//         arr = new int [size];
//         this -> size = size;
//     }
//     bool isEmpty(){
//         return rear == -1;
//     }
    
//     void enqueue(int data){
//         if(rear == size-1){
//             cout<<"Full";
//             return;
//         }
//         rear++;
//         arr[rear] = data;
//     }
    
//     int dequeue(){
//         if(isEmpty()){
//             cout<<"Empty queue";
//             return -1;
//         }
//         int front = arr[0];
//         for(int i = 0; i < rear; i++){
//             arr[i] = arr[i + 1];
//         }
//         rear--;
//         return front;
//     }
    
//     int top(){
//        if(isEmpty()){
//             cout<<"Empty queue";
//             return -1;
//         }
//         return arr[0];
//     }
// };

// int main() {
//     queue q(3);
//     q.enqueue(1);
//     q.enqueue(2);
//     while(!q.isEmpty()){
//         cout<<q.top()<<" ";
//         q.dequeue();
//     }
    
// }




















// #include <iostream>
// using namespace std;
// class Queue{
//     int *arr;
//     int rear = -1;
//     int front = -1;
//     int size;
    
//     public:
//     Queue(int size){
//         arr = new int [size];
//         this -> size = size;
//     }
//     bool isEmpty(){
//         return rear == -1 && front == -1;
//     }
    
//     bool isFull(){
//         return (rear+1) % size == front;
//     }
    
//     void enqueue(int data){
//         if(isFull()){
//             cout<<"Full enqueue";
//             return;
//         }
//         if(front == -1){
//             front = 0;
//         }
//         rear = (rear + 1) % size;
//         arr[rear] = data;
//     }
    
//     int dequeue(){
//         if(isEmpty()){
//             cout<<"Empty queue";
//             return -1;
//         }
//         int result = arr[front];
//         if(rear == front){
//             rear = front = -1;
//         }else{
//             front = (front + 1) % size;
//         }
//         return result;
//     }
    
//     int top(){
//        if(isEmpty()){
//             cout<<"Empty queue";
//             return -1;
//         }
//         return arr[front];
//     }
// };

// int main() {
//     Queue q(3);
//     q.enqueue(1);
//     q.enqueue(2);
//     q.enqueue(3);
//     cout<<q.dequeue()<< " after remove top ";
//     q.enqueue(4);
//     while(!q.isEmpty()){
//         cout<<q.top()<<" ";
//         q.dequeue();
//     }
    
// }