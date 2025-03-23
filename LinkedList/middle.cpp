#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};


Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
};

Node* middleList(Node* head){
   if (head == NULL) return NULL; // Handle empty list case

    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node* head = convertArr2LL(arr);
    Node* temp = head;
    // while(temp != NULL){
    //     cout<<temp -> data<<" -> ";
    //     temp = temp -> next;
    // }
    
    Node* middle = middleList(head);
     if (middle) {
        cout << "Middle of the Linked List: " << middle->data << endl;
    } else {
        cout << "List is empty.\n";
    }
    
    return 0;
}




Node* middleList(Node* head){
    if (head == NULL) return NULL; // Handle empty list case
 
     Node* slow = head;
     Node* fast = head;
     
     while(fast != NULL && fast -> next != NULL){
         slow = slow -> next;
         fast = fast -> next -> next;
     }
     return slow;
 };
 
 Node* reverse(Node* head){
     Node* prev = NULL;
     Node* curr = head;
     Node* next = NULL;
     while(curr != NULL){
         next = curr -> next;
         curr -> next = prev;
         prev = curr;
         curr = next;
     }
     return prev;
 }
 
 int main() {
     vector<int> arr = {1, 2, 3, 4, 5, 6};
     Node* head = convertArr2LL(arr);
     
     Node* rev = reverse(head);
     Node* temp = rev;
     while(temp != NULL){
         cout<<temp -> data<<" -> ";
         temp = temp -> next;
     }
     
     return 0;
 }