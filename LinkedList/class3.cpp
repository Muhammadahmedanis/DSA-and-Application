#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;

public:
    
    List() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    
    
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    void pop_front(){
        if(head == NULL){
            cout<<"Head is not exist";
            return;
        }else{
            Node* temp = head;
            head = head -> next;
            temp->next = NULL;
            delete temp;
        }
    }
    
    void pop_back(){
        if(head == NULL){
            cout<<"Head is not exist";
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    
    void insert(int val, int pos){
        if(pos < 0){
            cout<<"Po";
            return;
        }else if(pos == 0){
            push_front(val);
            return;
        }else{
            Node* temp = head;
            for(int i = 0; i < pos -1; i++){
                if(temp != NULL){
                    temp = temp->next;
                }
            }
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    
    int search(int val){
        Node* temp = head;
        while(temp != NULL){
            temp = temp -> next;
            if(temp -> data == val){
                return 1;
            }
        }
        return 0;
    };

    void searchAll(int val){
        vector<int> arr;
        Node* temp = head;
        int index = 0;
        while(temp != NULL){
            if(temp -> data == val){
                arr.push_back(index);
            }
        temp = temp -> next;
        index++;
        }
        for(int i: arr){
            cout<<i<<" ";
        }
    }


    void printLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next; 
        }
        cout << "NULL" << endl; 
    }
};

int main() {
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    
    ll.push_back(4);
    
    ll.pop_front();
    
    ll.pop_back();
    
    ll.insert(4, 1);
    
    cout<<ll.search(2)<<endl;
    
    ll.printLL();
    
    return 0;
}


// 2nd Approach
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    public: 
    int data;
    Node* next;
    
    public: 
    Node(int val, Node* next1){
        data = val;
        next = next1;
    }
    
    public: 
    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* covertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

Node* removeHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head -> next;
    temp -> next = NULL;
    delete temp;
    return head;
}

Node* removeTail(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = NULL;
    delete temp -> next;
    return head;
}

Node* removeK(Node* head, int k){
    if(head == NULL) return head;
    if(k == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
        return head;
    }
    
    int count = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        count++;
        if(count == k){
            prev -> next = prev -> next -> next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}


Node* removeValue(Node* head, int k){
    if(head == NULL) return head;
    if(head -> data == k){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
        return head;
    }
    
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp -> data == k){
            prev -> next = prev -> next -> next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

int main() {
   vector<int> arr = {2, 5, 7, 8};
   Node* head = covertArr2LL(arr);
   
//   head = removeHead(head);
//   head = removeTail(head);
    //  head = removeK(head, 1); // remove from position
     head = removeValue(head, 7); // remove from value you want
     
   
   Node* temp = head;
   while(temp != NULL){
       cout<<temp -> data <<" -> ";
      temp = temp -> next;
   }
   cout<<"NULL\n";
}
