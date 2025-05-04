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

Node* convertArr2LL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
};


void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(Node* head) {
    if (!head) return;
    bool swapped;
    Node* end = nullptr;

    do {
        swapped = false;
        Node* curr = head;

        while (curr->next != end) {
            if (curr->data > curr->next->data) {
                swap(curr, curr->next);
                swapped = true;
            }
            curr = curr->next;
        }
        end = curr;
    } while (swapped);
}



void selectionSort(Node* head) {
    for (Node* i = head; i && i->next; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j; j = j->next) {
            if (j->data < minNode->data)
                minNode = j;
        }
        if (minNode != i) {
            swap(i, minNode);
        }
    }
}



Node* insertionSort(Node* head) {
    if (!head || !head->next) return head;

    Node* sorted = nullptr;

    while (head) {
        Node* curr = head;
        head = head->next;

        if (!sorted || curr->data < sorted->data) {
            curr->next = sorted;
            sorted = curr;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->data < curr->data)
                temp = temp->next;
            curr->next = temp->next;
            temp->next = curr;
        }
    }
    return sorted;
}



Node* getTail(Node* curr) {
    while (curr && curr->next) curr = curr->next;
    return curr;
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if (!(*newHead)) *newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            Node* tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if (!(*newHead)) *newHead = pivot;
    *newEnd = tail;
    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end) return head;

    Node* newHead = nullptr, *newEnd = nullptr;
    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot) tmp = tmp->next;
        tmp->next = nullptr;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

Node* quickSort(Node* head) {
    Node* tail = getTail(head);
    return quickSortRecur(head, tail);
}


int main() {
    vector<int> arr = {9, 3, 7, 1};
    Node* head = convertArr2LL(arr);
    
    cout << "before Sorted List: ";
    printList(head);
    
    // bubbleSort(head);
    // selectionSort(head);
    // head = insertionSort(head);
    // head = quickSort(head);

    cout << "Sorted List: ";
    printList(head);
    return 0;
}