// #include <iostream>
// using namespace std;

// class Queue{
//     int *arr;
//     int size;
//     int rear = -1;
    
//     public:
//     Queue(int size){
//         this -> size = size;
//         arr = new int[size];
//     }
    
//     bool isEmpty(){
//         return rear == -1;
//     };
    
//     void enqueue(int data){
//         if(rear == size-1){
//             cout<<"Stack full";
//             return;
//         }
//         arr[++rear] = data;
//     };
    
//     int dequeue(){
//         if(isEmpty()){
//             cout<<"Empty queue";
//             return 0;
//         }
        
//         int front = arr[0];
//         for(int i = 0; i < rear; i++){
//             arr[i] = arr[i + 1];
//         }
//         rear--;
//         return front;
//     };
    
//     int getTop(){
//         if(isEmpty()){
//             cout<<"Empty queue";
//             return 0;
//         }
//         return arr[0];
//     }
// };


// struct Node{
//     int data;
//     Node* next;
//     Node(int val){
//         data = val;
//         next = NULL;
//     }
// };

// class Queue{
//     Node* front;
//     Node* rear;
    
//     public:
//     Queue(){
//         rear = front = NULL;
//     };
    
//     bool isEmpty(){
//         return front == NULL;
//     }
    
//     void enqueue(int val){
//         Node* newNode = new Node(val);
//         if(isEmpty()){
//             front = rear = newNode;
//         }else{
//             rear -> next = newNode;
//             rear = newNode;
//         }
//     };
    
//     void dequeue(){
//         if(isEmpty()){
//             cout<<"Queue is empty";
//         }
//         Node* temp = front;
//         front = front -> next;
//         delete temp;
//     };
    
//     int getFront(){
//         return front -> data;
//     }
    
// };


// int main() {
//     Queue q(3);
//     q.enqueue(1);
//     q.enqueue(2);
//     q.enqueue(3);
//     cout<<q.getTop()<<endl;
//     cout<<q.dequeue();
//     while(!q.isEmpty()){
//         cout<<q.dequeue()<<" ";
//     }
    
    
//     Queue q;
//     q.enqueue(1);
//     q.enqueue(2);
//     q.enqueue(3);
    
//     while(!q.isEmpty()){
//         cout<<q.getFront()<<" ";
//         q.dequeue();
//     }
    
//     return 0;
// }









// #include <iostream>
// using namespace std;

// class circularQueue {
//     int* arr;
//     int size;
//     int front, rear;

// public:
//     circularQueue(int size) {
//         this->size = size;
//         arr = new int[size];
//         front = rear = -1;
//     }

//     bool isEmpty() {
//         return front == -1;
//     }

//     bool isFull() {
//         return (rear + 1) % size == front;
//     }

//     void enqueue(int data) {
//         if (isFull()) {
//             cout << "CQ is full\n";
//             return;
//         }
//         if (isEmpty()) {
//             front = rear = 0;
//         } else {
//             rear = (rear + 1) % size;
//         }
//         arr[rear] = data;
//     }

//     void dequeue() {
//         if (isEmpty()) {
//             cout << "CQ is empty\n";
//             return;
//         }
//         if (front == rear) {
//             front = rear = -1;  // Reset queue
//         } else {
//             front = (front + 1) % size;
//         }
//     }

//     int getFront() {
//         if (isEmpty()) {
//             cout << "CQ is empty\n";
//             return -1;
//         }
//         return arr[front];
//     }
// };

// int main() {
//     circularQueue cq(3);
//     cq.enqueue(10);
//     cq.enqueue(20);
//     cq.enqueue(30);
//     cq.dequeue();        // removes 10
//     cq.enqueue(40);      // inserts 40 at position 0 (wrap around)

//     while (!cq.isEmpty()) {
//         cout << cq.getFront() << " ";
//         cq.dequeue();
//     }

//     return 0;
// }