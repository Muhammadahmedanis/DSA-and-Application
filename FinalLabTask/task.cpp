 // you need to implement a double linked listin which you need to implement insert and print operation only.
// other than the start you are also required to store the address of the last elemnt oof the list. also in each code an index need to be maintained that is count of the node of the list. Now you need to implement insertion sort algorithm on double linked list 
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int data) {
        this -> data = data;
        next = nullptr;
        prev = nullptr;
    };
};



Node* convertArr2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    };
    return head;
};



Node* insertAt(Node* head, int val, int pos){
    if(pos < 0 && val < 0) return head;
    Node* newNode = new Node(val);
    if(pos == 0){
        Node* temp = head;
        newNode -> next = temp;
        temp -> prev = newNode;
        temp = newNode;
        return temp;
    };

    Node* temp = head;
    for(int i = 0; i < pos-1; i++){
        temp = temp -> next;
    };
    
    if(temp == NULL) {
        return head;
    };
    newNode -> next = temp -> next;
    newNode -> prev = temp;
    
    if(temp->next != NULL){
        temp->next->prev = newNode;
    };
    
    temp -> next = newNode;
    return head;
};



void printList(Node* head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    };
    cout << "NULL\n";
};



Node* insertionSort(Node* head) {
    if (!head || !head->next) {
        return head;
    };

    Node* sorted = nullptr;
    while (head) {
        Node* curr = head;
        head = head->next;

        if (!sorted || curr->data < sorted->data) {
            curr->next = sorted;
            
            if (sorted){
                sorted->prev = curr;
            };
            sorted = curr;
            sorted->prev = nullptr;

        } else {
            Node* temp = sorted;

            while (temp->next && temp->next->data < curr->data) {
                temp = temp->next;
            };

            curr->next = temp->next;
            
            if (temp->next) { 
                temp->next->prev = curr;
            };
            
            temp->next = curr;
            curr->prev = temp;
        };
    };
    return sorted;
};


int main(){
    vector<int> arr = {9, 3, 7, 1};
    Node* head = convertArr2LL(arr);

    cout<<"Doubly linked list before insert: ";
    printList(head);

    head = insertAt(head, 4, 1);

    cout<<"Doubly linked list before sorting & after insertion: ";
    printList(head);

    head = insertionSort(head);
    cout << "Sorted Doubly linked List: ";
    printList(head);
    
    return 0;
}