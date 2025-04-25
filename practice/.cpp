// SingleLinkedList

// #include <iostream>
// using namespace std;

// struct Node{
//     Node* next;
//     Node* prev;
//     int data;
    
//     Node(int val){
//         data = val;
//         next = prev = NULL;
//     }
// };

// class DoubleList{
//     Node* head;
//     Node* tail;
    
//     public:
//     DoubleList(){
//         head = tail = NULL;
//     }
    
//     void push_F(int val){
//         Node* newNode = new Node(val);
//         if(head == NULL){
//             head = tail = newNode;
//         }else{
//             newNode -> next = head;
//             head -> prev = newNode;
//             head = newNode;
//         }
//     }
    
//     void push_B(int val){
//         Node* newNode = new Node(val);
//         if(head == NULL){
//             head = tail = newNode;
//         }else{
//             tail -> next = newNode;
//             newNode -> prev = tail;
//             tail = newNode;
//         }
//     }
    
//     void pop_F(){
//         if(head == NULL) cout<<"List not exist";
//         else{
//             Node* temp = head;
//             head = head -> next;
//             temp -> next = NULL;
//             head -> prev = NULL;
//             delete temp;
//         }
//     }
    
//     void pop_B(){
//         if(head == NULL) cout<<"List not exist";
//         else{
//             Node* temp = head;
//             while(temp -> next != tail){
//                 temp = temp -> next;
//             }
//             temp -> next = NULL;
//             tail -> prev = NULL;
//             delete tail;
//             tail = temp;
//         }    
//     }
    
    
//     void print(){
//         if(head == NULL) cout<<"List doesnot exist";
//         Node* temp = head;
//         while(temp != NULL){
//             cout<<temp -> data<<" <=> ";
//             temp = temp -> next;
//         }
//         cout<<"NULL"<<endl;
//     }
// };

// int main() {
//     DoubleList DLL;
    
//     // DLL.push_F(1);
//     // DLL.push_F(2);
//     // DLL.push_F(3);
//     // DLL.push_F(4);
    
//     DLL.push_B(1);
//     DLL.push_B(2);
//     DLL.push_B(3);
//     DLL.push_B(4);
    
//     DLL.print();
    
//     // DLL.pop_F();
//     // DLL.pop_F();
    
//     DLL.pop_B();
//     DLL.pop_B();
     
//     DLL.print();
//     return 0;
// }




// #include <iostream>
// #include <vector>
// using namespace std;

// struct Node{
//     Node* next;
//     Node* prev;
//     int data;
    
//     Node(int val){
//         data = val;
//         next = prev = NULL;
//     }
// };

// Node* convertArr2DLL(vector<int> &arr){
//     Node* head = new Node(arr[0]);
//     Node* mover = head;
    
//     for(int i = 1; i < arr.size(); i++){
//         Node* temp = new Node(arr[i]);
//         mover -> next = temp;
//         temp -> prev = mover;
//         mover = temp;
//     }
//     return head;
// };



// Node* removeAtHead(Node* head){
//     Node* temp = head;
//     head = head -> next;
//     temp -> next = NULL;
//     head -> prev = NULL;
//     delete temp;
//     return head;
// };

// Node* removeAtTail(Node* head){
//     Node* temp = head;
//     while(temp -> next -> next != NULL){
//         temp = temp -> next;
//     }
//     Node* toDelete = temp -> next;
//     temp -> next = NULL;
//     delete toDelete;
    
//     return head;
// };


// Node* removePos(Node* head, int pos){
//     if(head == NULL){
//         cout<<"List doesnot exist";
//         return head;
//     } 
    
//     if(pos == 1){
//         Node* temp = head;
//         head = head -> next;
//         temp -> next = NULL;
//         head -> prev = NULL;
//         delete temp;
//         return head;
//     }
    
//     Node* temp = head;
//     int count = 0;
//     while(temp != NULL && count < pos){
//         temp = temp -> next;
//         count++;
//     }
//     if (temp == NULL) {
//         cout << "Position out of bounds" << endl;
//         return head;
//     }
    
//     if(temp -> prev != NULL){
//         temp -> prev -> next = temp -> next;
//     }
    
//     if(temp -> next != NULL){
//         temp -> next -> prev = temp -> prev;
//     }
//     delete temp;
//     return head;
// };



// Node* removeVal(Node* head, int val){
//      if(head == NULL){
//         cout<<"List doesnot exist";
//         return head;
//     } 
    
//     if(head -> data == val){
//         Node* temp = head;
//         head = head -> next;
//         temp -> next = NULL;
//         delete temp;
//         return head;
//     }
    
//     Node* temp = head;
//     while(temp != NULL && temp -> data != val){
//         temp = temp -> next;
//     }
//      if (temp == NULL) {
//         cout << "Position out of bounds" << endl;
//         return head;
//     }
//         if(temp -> prev != NULL){
//         temp -> prev -> next = temp -> next;
//     }
    
//     if(temp -> next != NULL){
//         temp -> next -> prev = temp -> prev;
//     }
//     delete temp;
//     return head;
// }



// int main(){
//     vector<int>arr = {12, 6, 9, 5, 21};
//     Node* head = convertArr2DLL(arr);
//     // head = removeAtHead(head);
//     // head = removeAtTail(head);
//     // head = removePos(head, 2);
//     head = removeVal(head, 21);
    
//     Node* temp = head;
//     while(temp != NULL){
//         cout<<temp -> data<<" <=> ";
//          temp = temp -> next;
//     }
//     cout<<"NULL"<<endl;
// }




// DoubleLinkedList






// #include <iostream>
// // using namespace std;

// // struct Node{
// //     Node* next;
// //     Node* prev;
// //     int data;
    
// //     Node(int val){
// //         data = val;
// //         next = prev = NULL;
// //     }
// // };

// // class DoubleList{
// //     Node* head;
// //     Node* tail;
    
// //     public:
// //     DoubleList(){
// //         head = tail = NULL;
// //     }
    
// //     void push_F(int val){
// //         Node* newNode = new Node(val);
// //         if(head == NULL){
// //             head = tail = newNode;
// //         }else{
// //             newNode -> next = head;
// //             head -> prev = newNode;
// //             head = newNode;
// //         }
// //     }
    
// //     void push_B(int val){
// //         Node* newNode = new Node(val);
// //         if(head == NULL){
// //             head = tail = newNode;
// //         }else{
// //             tail -> next = newNode;
// //             newNode -> prev = tail;
// //             tail = newNode;
// //         }
// //     }
    
// //     void pop_F(){
// //         if(head == NULL) cout<<"List not exist";
// //         else{
// //             Node* temp = head;
// //             head = head -> next;
// //             temp -> next = NULL;
// //             head -> prev = NULL;
// //             delete temp;
// //         }
// //     }
    
// //     void pop_B(){
// //         if(head == NULL) cout<<"List not exist";
// //         else{
// //             Node* temp = head;
// //             while(temp -> next != tail){
// //                 temp = temp -> next;
// //             }
// //             temp -> next = NULL;
// //             tail -> prev = NULL;
// //             delete tail;
// //             tail = temp;
// //         }    
// //     }
    
    
// //     void print(){
// //         if(head == NULL) cout<<"List doesnot exist";
// //         Node* temp = head;
// //         while(temp != NULL){
// //             cout<<temp -> data<<" <=> ";
// //             temp = temp -> next;
// //         }
// //         cout<<"NULL"<<endl;
// //     }
// // };

// // int main() {
// //     DoubleList DLL;
    
// //     // DLL.push_F(1);
// //     // DLL.push_F(2);
// //     // DLL.push_F(3);
// //     // DLL.push_F(4);
    
// //     DLL.push_B(1);
// //     DLL.push_B(2);
// //     DLL.push_B(3);
// //     DLL.push_B(4);
    
// //     DLL.print();
    
// //     // DLL.pop_F();
// //     // DLL.pop_F();
    
// //     DLL.pop_B();
// //     DLL.pop_B();
     
// //     DLL.print();
// //     return 0;
// // }




// #include <iostream>
// #include <vector>
// using namespace std;

// struct Node{
//     Node* next;
//     Node* prev;
//     int data;
    
//     Node(int val){
//         data = val;
//         next = prev = NULL;
//     }
// };

// Node* convertArr2DLL(vector<int> &arr){
//     Node* head = new Node(arr[0]);
//     Node* mover = head;
    
//     for(int i = 1; i < arr.size(); i++){
//         Node* temp = new Node(arr[i]);
//         mover -> next = temp;
//         temp -> prev = mover;
//         mover = temp;
//     }
//     return head;
// };



// Node* removeAtHead(Node* head){
//     Node* temp = head;
//     head = head -> next;
//     temp -> next = NULL;
//     head -> prev = NULL;
//     delete temp;
//     return head;
// };

// Node* removeAtTail(Node* head){
//     Node* temp = head;
//     while(temp -> next -> next != NULL){
//         temp = temp -> next;
//     }
//     Node* toDelete = temp -> next;
//     temp -> next = NULL;
//     delete toDelete;
    
//     return head;
// };


// Node* removePos(Node* head, int pos){
//     if(head == NULL){
//         cout<<"List doesnot exist";
//         return head;
//     } 
    
//     if(pos == 1){
//         Node* temp = head;
//         head = head -> next;
//         temp -> next = NULL;
//         head -> prev = NULL;
//         delete temp;
//         return head;
//     }
    
//     Node* temp = head;
//     int count = 0;
//     while(temp != NULL && count < pos){
//         temp = temp -> next;
//         count++;
//     }
//     if (temp == NULL) {
//         cout << "Position out of bounds" << endl;
//         return head;
//     }
    
//     if(temp -> prev != NULL){
//         temp -> prev -> next = temp -> next;
//     }
    
//     if(temp -> next != NULL){
//         temp -> next -> prev = temp -> prev;
//     }
//     delete temp;
//     return head;
// };



// Node* removeVal(Node* head, int val){
//      if(head == NULL){
//         cout<<"List doesnot exist";
//         return head;
//     } 
    
//     if(head -> data == val){
//         Node* temp = head;
//         head = head -> next;
//         temp -> next = NULL;
//         delete temp;
//         return head;
//     }
    
//     Node* temp = head;
//     while(temp != NULL && temp -> data != val){
//         temp = temp -> next;
//     }
//      if (temp == NULL) {
//         cout << "Position out of bounds" << endl;
//         return head;
//     }
//         if(temp -> prev != NULL){
//         temp -> prev -> next = temp -> next;
//     }
    
//     if(temp -> next != NULL){
//         temp -> next -> prev = temp -> prev;
//     }
//     delete temp;
//     return head;
// }



// int main(){
//     vector<int>arr = {12, 6, 9, 5, 21};
//     Node* head = convertArr2DLL(arr);
//     // head = removeAtHead(head);
//     // head = removeAtTail(head);
//     // head = removePos(head, 2);
//     head = removeVal(head, 21);
    
//     Node* temp = head;
//     while(temp != NULL){
//         cout<<temp -> data<<" <=> ";
//          temp = temp -> next;
//     }
//     cout<<"NULL"<<endl;
// }



// circular linked list


// #include <iostream>
// using namespace std;

// struct Node{
//     int data;
//     Node* next;
    
//     Node(int val){
//         data = val;
//         next = NULL;
//     }
// };

// class circularList{
//     Node* head;
//     Node* tail;
    
//     public:
//     circularList(){
//         head = tail = NULL;
//     }
    
//     void insertAtHead(int val){
//         Node* newNode = new Node(val);
//         if(head == NULL){
//             head = tail = newNode;
//             tail -> next = newNode;
//         }else{
//             newNode -> next = head;
//             head = newNode;
//             tail -> next = newNode;
//         }
//     };
    
//     void insertAtTail(int val){
//       Node* newNode = new Node(val);
//         if(head == NULL){
//             head = tail = newNode;
//             tail -> next = newNode;
//         }else{
//             tail -> next = newNode;
//             tail = newNode;
//             newNode -> next = head; 
//         }  
//     };
    
//     void deleteAtHead(){
//         if(head == NULL) cout<<"list doesnot exist";
//         else if(head == tail){
//             delete head;
//             head = tail = NULL;
//         }else{
//             Node* temp = head;
//             head = head -> next;
//             temp -> next = NULL;
//             tail -> next = head;
//             delete temp;
//         }
//     };
    
//     void deleteAtTail() {
//         if (head == NULL) {
//             cout << "List does not exist" << endl;
//         } else if (head == tail) {
//             delete head;
//             head = tail = NULL;
//         } else {
//             Node* temp = head;
//             while (temp->next != tail) {
//                 temp = temp->next;
//             }
//             delete tail;
//             tail = temp;
//             tail->next = head; 
//         }
//     }

    
//     void print(){
//         Node* temp = head;
//         if(temp == NULL) cout<<"List not exist";
//         do{
//             cout<<temp -> data<<" -> ";
//              temp = temp -> next;
//         }while(temp != head);
//         cout<<endl;
//     }
// };

// int main() {
//     circularList CLL;
//     // CLL.insertAtHead(1);
//     // CLL.insertAtHead(2);
//     // CLL.insertAtHead(3);
//     // CLL.insertAtHead(4);
    
//     CLL.insertAtTail(1);
//     CLL.insertAtTail(2);
//     CLL.insertAtTail(3);
//     CLL.insertAtTail(4);
    
//     CLL.print();
    
//     // CLL.deleteAtHead();
//     // CLL.deleteAtHead();
    
//     CLL.deleteAtTail();
//     CLL.deleteAtTail();
    
//     CLL.print();
    
    
    
//     return 0;
// }
