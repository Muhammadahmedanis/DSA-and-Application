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



// fjdkf

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to convert array to linked list
Node* convertArr2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Merge function to merge two sorted lists
Node* merge(Node* left, Node* right) {
    // If left or right is null, return the other one
    if (!left) return right;
    if (!right) return left;

    // Create a dummy node to simplify the merging process
    Node* dummy = new Node(0);
    Node* current = dummy;

    while (left && right) {
        if (left->data <= right->data) {
            current->next = left;
            left = left->next;
        } else {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }

    // If there are remaining nodes in either list, attach them
    if (left) current->next = left;
    if (right) current->next = right;

    Node* sortedHead = dummy->next;
    delete dummy;
    return sortedHead;
}

// Function to find the middle of the linked list
Node* findMiddle(Node* head) {
    if (!head) return nullptr;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Merge Sort function to sort the linked list
Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    Node* middle = findMiddle(head);
    Node* left = head;
    Node* right = middle->next;
    middle->next = nullptr; // Split the list into two halves

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    vector<int> arr = {9, 3, 7, 1};
    Node* head = convertArr2LL(arr);

    cout << "Before Sorting: ";
    printList(head);

    // Apply Merge Sort
    head = mergeSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}


//  doublt list 


#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Function to convert array to doubly linked list
Node* convertArr2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }
    return head;
}

// Function to print the doubly linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

Node* insertionSort(Node* head) {
    if (!head || !head->next) return head;

    Node* sorted = nullptr;
    while (head) {
        Node* curr = head;
        head = head->next;

        if (!sorted || curr->data < sorted->data) {
            curr->next = sorted;
            if (sorted) sorted->prev = curr;
            sorted = curr;
            sorted->prev = nullptr;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->data < curr->data) {
                temp = temp->next;
            }
            curr->next = temp->next;
            if (temp->next) temp->next->prev = curr;
            temp->next = curr;
            curr->prev = temp;
        }
    }
    return sorted;
}



Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;
    
    Node* dummy = new Node(0);
    Node* current = dummy;
    
    while (left && right) {
        if (left->data <= right->data) {
            current->next = left;
            left->prev = current;
            left = left->next;
        } else {
            current->next = right;
            right->prev = current;
            right = right->next;
        }
        current = current->next;
    }

    if (left) {
        current->next = left;
        left->prev = current;
    }

    if (right) {
        current->next = right;
        right->prev = current;
    }

    Node* sortedHead = dummy->next;
    delete dummy;
    return sortedHead;
}

Node* findMiddle(Node* head) {
    if (!head) return nullptr;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    Node* middle = findMiddle(head);
    Node* left = head;
    Node* right = middle->next;
    middle->next = nullptr; // Split the list into two halves
    
    left = mergeSort(left);
    right = mergeSort(right);
    
    return merge(left, right);
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
            if (cur->next) cur->next->prev = prev;
            Node* tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            cur->prev = tail;
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
        pivot->prev = tmp;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);
    if (pivot->next) pivot->next->prev = pivot;
    return newHead;
}

Node* quickSort(Node* head) {
    Node* tail = getTail(head);
    return quickSortRecur(head, tail);
}







void selectionSort(Node* head) {
    for (Node* i = head; i && i->next; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j; j = j->next) {
            if (j->data < minNode->data)
                minNode = j;
        }
        if (minNode != i) {
            // Swap the data of i and minNode
            int temp = i->data;
            i->data = minNode->data;
            minNode->data = temp;
        }
    }
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
                // Swap the data of curr and next
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                swapped = true;
            }
            curr = curr->next;
        }
        end = curr;
    } while (swapped);
}





int main() {
    vector<int> arr = {9, 3, 7, 1};
    Node* head = convertArr2LL(arr);

    cout << "Before Sorting: ";
    printList(head);

    // Uncomment any of these sorting methods to apply:

    // bubbleSort(head);
    // selectionSort(head);
    // head = insertionSort(head);
    // head = quickSort(head);
    head = mergeSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
