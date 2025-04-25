// #include <iostream>
// using namespace std;

// // using array
// class Stack {
//     int size;
//     int top;
//     int *arr;
    
//     public: 
//     Stack(int size){
//         this -> size = size;
//         this -> top = -1;
//         arr = new int [size];
//     }
    
//     bool isEmpty(){
//         return top == -1;
//     }
    
//     void push(int val){
//         if(top == size-1){
//             cout <<"stack overflow";
//             return;
//         }
//         arr[++top] = val;
//     }
    
//     int pop(){
//         if(isEmpty()){
//             cout<<"stack underflow";
//             return -1;
//         }
//         return arr[top--]; 
//     }
    
// };

// int main() {
//     Stack st(2);
//     st.push(1);
//     st.push(2);
//     cout<<st.pop()<< " ";
    
//     while(!st.isEmpty()){
//         cout<<st.pop()<<" ";
//     }
//     st.push(3);
//     cout<<st.pop()<<" ";
//     cout<<st.pop()<<" ";
// }




// //  Using Linked list
// struct Node{
//     int data;
//     Node* next;
    
//     public:
//     Node(int val){
//         data = val;
//         next = NULL;
//     }
// };

// class Stack {
//     Node* top;
    
//     public:
//     Stack(){
//         top = NULL;
//     }
    
//     bool isEmpty(){
//         return top == NULL;
//     }
    
//     void push(int val){
//         Node* newNode = new Node(val);
//         if(isEmpty()){
//             top = newNode;
//             return;
//         };
//         newNode -> next = top;
//         top = newNode;
//     };
    
//     int pop(){
//         if(isEmpty()){
//             cout<<"Stack is underflow";
//             return -1;
//         };
//         int value = top -> data;
//         top = top -> next;
//         return value;
//     };
    
//     int getTop(){
//         if(isEmpty()){
//             cout<<"Stack is underflow";
//             return -1;
//         };
//         return top -> data;
//     }
    
// };


// int main() {
//     Stack st;
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     cout<<st.pop()<<endl;
//     cout<<st.getTop();
//     while(!st.isEmpty()){
//         cout<<st.pop()<<" ";
//     }
//     return 0;
// }











// int pop(){
//     if(isEmpty()){
//         cout<<"stack underflow";
//         return -1;
//     }
//     Node* toRemove = top;
//     int result = toRemove -> data;
//     top = top -> next;
//     delete toRemove;
//     return result;
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