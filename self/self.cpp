// convert to bst min heap


// #include <iostream>
// #include <vector>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };


// Node* insertBST(Node* root, int val) {
//     if (root == NULL) return new Node(val);
//     if (val < root->data)
//         root->left = insertBST(root->left, val);
//     else
//         root->right = insertBST(root->right, val);
//     return root;
// }

// void inorder(Node* root) {
//     if (root == NULL) return;
//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }

// int main() {
//     vector<int> bstValues = {4, 2, 6, 1, 3, 5, 7};
//     Node* bst = NULL;

//     for (int val : bstValues) {
//         bst = insertBST(bst, val);
//     }

//     // for (int i = 0; i < bstValues.size(); ++i) {
//     //     bst = insertBST(bst, bstValues[i]);
//     // }
    

//     cout << "Inorder traversal of BST: ";
//     inorder(bst);
//     return 0;
// }



















// mergeSort 


// #include <iostream>
// using namespace std;
// class Node {
// public:
//     int data;
//     Node* next;
//     Node(int val) {
//         data = val;
//         next = nullptr;
//     }
// };

// void printList(Node* head) {
//     while (head) {
//         cout << head->data << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

// Node* merge(Node* left, Node* right) {
//     if (!left) return right;
//     if (!right) return left;

//     Node* result = nullptr;

//     if (left->data <= right->data) {
//         result = left;
//         result->next = merge(left->next, right);
//     } else {
//         result = right;
//         result->next = merge(left, right->next);
//     }

//     return result;
// }

// Node* getMiddle(Node* head) {
//     if (!head) return head;

//     Node* slow = head;
//     Node* fast = head->next;

//     while (fast && fast->next) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     return slow;
// }

// Node* mergeSort(Node* head) {
//     if (!head || !head->next) return head;

//     Node* mid = getMiddle(head);
//     Node* left = head;
//     Node* right = mid->next;
//     mid->next = nullptr; // split the list

//     left = mergeSort(left);
//     right = mergeSort(right);

//     return merge(left, right);
// }

// void insert(Node*& head, int val) {
//     Node* newNode = new Node(val);
//     if (!head) {
//         head = newNode;
//         return;
//     }

//     Node* temp = head;
//     while (temp->next) temp = temp->next;
//     temp->next = newNode;
// }

// int main() {
//     Node* head = nullptr;
//     insert(head, 5);
//     insert(head, 3);
//     insert(head, 8);
//     insert(head, 2);
//     insert(head, 7);

//     cout << "Original List: ";
//     printList(head);

//     head = mergeSort(head);

//     cout << "Sorted List: ";
//     printList(head);

//     return 0;
// }
















// mergeSortedLists(


// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;
//     Node(int val) {
//         data = val;
//         next = nullptr;
//     }
// };

// void printList(Node* head) {
//     while (head) {
//         cout << head->data << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

// Node* mergeSortedLists(Node* l1, Node* l2) {
//     Node* dummy = new Node(0);
//     Node* current = dummy;

//     while (l1 != nullptr && l2 != nullptr) {
//         if (l1->data <= l2->data) {
//             current->next = l1;
//             l1 = l1->next;
//         } else {
//             current->next = l2;
//             l2 = l2->next;
//         }
//         current = current->next;
//     }

//     if (l1 != nullptr) {
//         current->next = l1;
//     } else {
//         current->next = l2;
//     }

//     Node* mergedHead = dummy->next;
//     delete dummy; // Free the dummy node
//     return mergedHead;
// }

// void insert(Node*& head, int val) {
//     Node* newNode = new Node(val);
//     if (!head) {
//         head = newNode;
//         return;
//     }

//     Node* temp = head;
//     while (temp->next) temp = temp->next;
//     temp->next = newNode;
// }

// int main() {
//     Node* list1 = nullptr;
//     insert(list1, 1);
//     insert(list1, 3);
//     insert(list1, 5);
//     insert(list1, 7);

//     Node* list2 = nullptr;
//     insert(list2, 2);
//     insert(list2, 4);
//     insert(list2, 6);
//     insert(list2, 8);

//     cout << "List 1: ";
//     printList(list1);
//     cout << "List 2: ";
//     printList(list2);

//     Node* mergedList = mergeSortedLists(list1, list2);

//     cout << "Merged Sorted List: ";
//     printList(mergedList);

//     return 0;
// }







// palindrome linked list


// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;
//     Node(int val) {
//         data = val;
//         next = nullptr;
//     }
// };

// void insert(Node*& head, int val) {
//     Node* newNode = new Node(val);
//     if (head == nullptr) {
//         head = newNode;  
//         return;
//     }
    
//     Node* temp = head;
//     while (temp->next != nullptr) {
//         temp = temp->next;  // Traverse to the last node
//     }
//     temp->next = newNode;  // Add the new node at the end
// }

// Node* findMiddle(Node* head) {
//     Node* slow = head;
//     Node* fast = head;
//     while (fast != nullptr && fast->next != nullptr) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     return slow;
// }

// Node* reverseList(Node* head) {
//     Node* prev = nullptr;
//     Node* curr = head;
//     Node* next = nullptr;
    
//     while (curr != nullptr) {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }
//     return prev;
// }

// bool isPalindrome(Node* head) {
//     if (head == nullptr || head->next == nullptr) return true;

//     Node* middle = findMiddle(head);

//     Node* secondHalf = reverseList(middle);
    
//     Node* firstHalf = head;
//     while (secondHalf != nullptr) {
//         if (firstHalf->data != secondHalf->data) {
//             return false; // Lists don't match, not a palindrome
//         }
//         firstHalf = firstHalf->next;
//         secondHalf = secondHalf->next;
//     }
//     return true;
// }

// void printList(Node* head) {
//     Node* temp = head;
//     while (temp != nullptr) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main() {
//     Node* head = nullptr;

//     insert(head, 1);
//     insert(head, 2);
//     insert(head, 3);
//     insert(head, 2);
//     insert(head, 1);

//     cout << "Original List: ";
//     printList(head);

//     if (isPalindrome(head)) {
//         cout << "The linked list is a palindrome." << endl;
//     } else {
//         cout << "The linked list is not a palindrome." << endl;
//     }

//     return 0;
// }












//  remove duplicte from linked list


// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;
//     Node(int val) {
//         data = val;
//         next = nullptr;
//     }
// };

// void insert(Node*& head, int val) {
//     Node* newNode = new Node(val);
//     if (head == nullptr) {
//         head = newNode;  
//         return;
//     }
    
//     Node* temp = head;
//     while (temp->next != nullptr) {
//         temp = temp->next;  
//     }
//     temp->next = newNode;  
// }

// void removeDuplicates(Node*& head) {
//     if (head == nullptr) return;
    
//     Node* current = head;
    
//     while (current != nullptr) {
//         Node* runner = current;
        
//         while (runner->next != nullptr) {
//             if (runner->next->data == current->data) {
//                 Node* temp = runner->next;
//                 runner->next = runner->next->next;
//                 delete temp;  
//             } else {
//                 runner = runner->next; 
//             }
//         }
//         current = current->next;  
//     }
// }

// void printList(Node* head) {
//     Node* temp = head;
//     while (temp != nullptr) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main() {
//     Node* head = nullptr;

//     insert(head, 1);
//     insert(head, 2);
//     insert(head, 3);
//     insert(head, 2);
//     insert(head, 4);
//     insert(head, 3);
//     insert(head, 5);

//     cout << "Original List: ";
//     printList(head);

//     removeDuplicates(head);

//     cout << "List after removing duplicates: ";
//     printList(head);

//     return 0;
// }












// print  nirror if linkedlist

// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// class Node {
// public:
//     float data;
//     Node* left;
//     Node* right;

//     Node(float val) {
//         data = val;
//         left = right = nullptr;
//     }
// };

// Node* buildTreeLikeHeap(const vector<float>& values) {
//     if (values.empty()) return nullptr;

//     Node* root = new Node(values[0]);
//     queue<Node*> q;
//     q.push(root);

//     int i = 1;
//     while (i < values.size()) {
//         Node* current = q.front();
//         q.pop();

//         current->left = new Node(values[i++]);
//         q.push(current->left);

//         if (i < values.size()) {
//             current->right = new Node(values[i++]);
//             q.push(current->right);
//         }
//     }

//     return root;
// }

// void mirrorTree(Node* root) {
//     if (!root) return;

//     swap(root->left, root->right);
//     mirrorTree(root->left);
//     mirrorTree(root->right);
// }

// void printTree(Node* root) {
//     if (!root) return;

//     queue<Node*> q;
//     q.push(root);

//     while (!q.empty()) {
//         Node* current = q.front();
//         q.pop();

//         cout << current->data << " ";

//         if (current->left) q.push(current->left);
//         if (current->right) q.push(current->right);
//     }
// }

// int main() {
//     vector<float> values = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};

//     Node* root = buildTreeLikeHeap(values);

//     mirrorTree(root);

//     printTree(root);

//     return 0;
// }



// 

// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node(int val) {
//         data = val;
//         next = NULL;
//     }
// };

// class SortedLinkedList {
//     Node* head;

// public:
//     SortedLinkedList() {
//         head = NULL;
//     }

//     void insert(int val) {
//         Node* newNode = new Node(val);

//         if (!head || val < head->data) {
//             newNode->next = head;
//             head = newNode;
//             return;
//         }

//         Node* curr = head;
//         while (curr->next && curr->next->data < val) {
//             curr = curr->next;
//         }
//         newNode->next = curr->next;
//         curr->next = newNode;
//     }

//     SortedLinkedList copyList() {
//         SortedLinkedList newList;
//         Node* temp = head;
//         while (temp) {
//             newList.insertAtEnd(temp->data);
//             temp = temp->next;
//         }
//         return newList;
//     }

//     void insertAtEnd(int val) {
//         Node* newNode = new Node(val);
//         if (!head) {
//             head = newNode;
//             return;
//         }

//         Node* curr = head;
//         while (curr->next)
//             curr = curr->next;
//         curr->next = newNode;
//     }

//     void reverse() {
//         Node* prev = NULL;
//         Node* curr = head;
//         Node* next = NULL;

//         while (curr) {
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }

//         head = prev;
//     }

//     void print() {
//         Node* temp = head;
//         while (temp) {
//             cout << temp->data << " -> ";
//             temp = temp->next;
//         }
//         cout << "NULL\n";
//     }
// };

// int main() {
//     SortedLinkedList list;

//     list.insert(30);
//     list.insert(10);
//     list.insert(40);
//     list.insert(20);
//     list.insert(15);

//     cout << "Sorted Original List:\n";
//     list.print();

//     SortedLinkedList newList = list.copyList();

//     newList.reverse();

//     cout << "Reversed Copied List:\n";
//     newList.print();

//     return 0;
// }












// Sorted doubly linked list

// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node* prev;
//     Node(int val) {
//         data = val;
//         next = prev = nullptr;
//     }
// };

// class SortedDoublyLinkedList {
// private:
//     Node* head;
//     Node* tail;

// public:
//     SortedDoublyLinkedList() {
//         head = tail = nullptr;
//     }

//     void insert(int val) {
//         Node* newNode = new Node(val);

//         if (!head || val < head->data) {
//             newNode->next = head;
//             if (head) head->prev = newNode;
//             else tail = newNode;
//             head = newNode;
//             return;
//         }

//         Node* curr = head;
//         while (curr->next && curr->next->data < val) {
//             curr = curr->next;
//         }

//         newNode->next = curr->next;
//         if (curr->next) curr->next->prev = newNode;
//         else tail = newNode;

//         newNode->prev = curr;
//         curr->next = newNode;
//     }

//     void print() {
//         Node* temp = head;
//         while (temp) {
//             cout << temp->data << " <=> ";
//             temp = temp->next;
//         }
//         cout << "NULL\n";
//     }

//     void reverse() {
//         Node* curr = head;
//         Node* temp = nullptr;

//         while (curr) {
//             temp = curr->prev;
//             curr->prev = curr->next;
//             curr->next = temp;
//             curr = curr->prev;
//         }

//         // Swap head and tail
//         if (temp) {
//             head = temp->prev;
//         }
//     }

//     int findMin() {
//         if (!head) throw runtime_error("List is empty");
//         return head->data;
//     }

//     int findMax() {
//         if (!tail) throw runtime_error("List is empty");
//         return tail->data;
//     }
// };

// int main() {
//     SortedDoublyLinkedList dll;
//     dll.insert(40);
//     dll.insert(20);
//     dll.insert(10);
//     dll.insert(30);
//     dll.insert(50);

//     cout << "Sorted List: ";
//     dll.print();

//     cout << "Min: " << dll.findMin() << endl;
//     cout << "Max: " << dll.findMax() << endl;

//     dll.reverse();
//     cout << "Reversed List: ";
//     dll.print();

//     return 0;
// }







// #include <iostream>
// #include <queue>
// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val) {
//         data = val;
//         left = right = nullptr;
//     }
// };

// Node* insertLevelOrder(Node* root, int val) {
//     Node* newNode = new Node(val);
//     if (!root) return newNode;

//     queue<Node*> q;
//     q.push(root);

//     while (!q.empty()) {
//         Node* temp = q.front();
//         q.pop();

//         if (!temp->left) {
//             temp->left = newNode;
//             return root;
//         } else {
//             q.push(temp->left);
//         }

//         if (!temp->right) {
//             temp->right = newNode;
//             return root;
//         } else {
//             q.push(temp->right);
//         }
//     }
//     return root;
// }

// bool isMirror(Node* t1, Node* t2) {
//     if (!t1 && !t2) return true;
//     if (!t1 || !t2) return false;

//     return (t1->data == t2->data) &&
//            isMirror(t1->left, t2->right) &&
//            isMirror(t1->right, t2->left);
// }

// int main() {
//     Node* root1 = nullptr;
//     root1 = insertLevelOrder(root1, 1);
//     root1 = insertLevelOrder(root1, 2);
//     root1 = insertLevelOrder(root1, 3);

//     Node* root2 = nullptr;
//     root2 = insertLevelOrder(root2, 1);
//     root2 = insertLevelOrder(root2, 3);
//     root2 = insertLevelOrder(root2, 2);

//     cout << "Tree 1 is mirror of Tree 2? " << (isMirror(root1, root2) ? "Yes" : "No") << endl;
//     return 0;
// }
