#include <iostream>
#include <queue>
using namespace std;

struct BTNode{
    int data;
    BTNode* LChild;
    BTNode* RChild;
    
    BTNode(int data){
        this -> data = data;
        LChild = RChild = nullptr;
    }
    
};


BTNode* insert(BTNode* node, int val){
    if(node == nullptr){
        return new BTNode(val);
    }
    
    if(val > node -> data){
        node->RChild = insert(node -> RChild, val);
    }else{
        node -> LChild = insert(node -> LChild, val);
    }
    return node;
};


BTNode* search(BTNode* node, int val){
  if(node == nullptr){
        return nullptr;
    }
    
    if(val == node -> data){
        return node;
    }
    
    if(val > node -> data){
        return search(node->RChild, val);
    }else{
        return search(node->LChild, val);
    }
    
    return nullptr;
};

void preorder(BTNode* node){
        if(node != nullptr){
        cout<<node -> data<<" ";
        preorder(node -> LChild);
        preorder(node -> RChild);
    }
    
}


void inorder(BTNode* node){
    if(node != nullptr){
        inorder(node -> LChild);
        cout<<node -> data<<" ";
        inorder(node -> RChild);
    }
}


void postorder(BTNode* node){
    if(node != nullptr){
        postorder(node -> LChild);
        postorder(node -> RChild);
        cout<<node -> data<<" ";
    }
}


void levelOrder(BTNode* node){
    queue<BTNode*> q;
    q.push(node);
    q.push(NULL);
    
    while(q.size() > 0){
        BTNode* curr = q.front();
        q.pop();
        if(curr == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }
        cout<<curr->data<<" ";
        
        if(curr -> LChild != NULL){
            q.push(curr -> LChild);
        }
        
        if(curr -> RChild != NULL){
            q.push(curr -> RChild);
        }
    }
}



int main() {
    BTNode* root = nullptr;
    root = insert(root, 150);
    root = insert(root, 90);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 11);
    root = insert(root, 28);
    root = insert(root, 88);
    root = insert(root, 100);
    root = insert(root, 120);
    root = insert(root, 140);
    root = insert(root, 176);
    root = insert(root, 160);
    root = insert(root, 170);
    
    cout<<"Preorder: ";
    preorder(root);
    
    cout<<"\nInorder: ";
    inorder(root);
    
    cout<<"\nPostorder: ";
    postorder(root);
    
    cout << "\nLevel Order Traversal:" << endl;
    levelOrder(root);
    
    BTNode* result = search(root, 20);
    cout << (result ? "\nFound "  : "\nNot found ");
    
    return 0;
}














// #include <iostream>
// #include <climits>    // For INT_MIN
// #include <algorithm> 
// using namespace std;

// class BSTNode {
// public:
//     int data;
//     BSTNode* LChild;
//     BSTNode* RChild;
    
//     BSTNode(int value) {
//         data = value;
//         LChild = RChild = nullptr;
//     }

 
// };

// BSTNode* insert(BSTNode* node, int value) {
//     if (node == nullptr) {
//         return new BSTNode(value);
//     }

//     if (value > node->data) {
//         node->RChild = insert(node->RChild, value);
//     } else {
//         node->LChild = insert(node->LChild, value);
//     }

//     return node;
// };

// void Preorder(BSTNode* node){
//     if(node != NULL){
//         cout<<node -> data<<" -> ";
//         Preorder(node -> LChild);
//         Preorder(node -> RChild);
//     }
// };

// BSTNode* Search(BSTNode* node, int val) {
//     if (node == nullptr) {
//         cout << "Value " << val << " not found." << endl;
//         return nullptr;  
//     }

//     if (node->data == val) {
//         return node;  
//     }

//     if (val > node->data) {
//         return Search(node->RChild, val);  
//     } else {
//         return Search(node->LChild, val);  
//     }
// };



// int size (BSTNode* node){
//    if (node == nullptr) {
//         return 0;  
//     } 
//     return 1 + size(node -> LChild) + size (node -> RChild);
// };


// int sum (BSTNode* node){
//    if (node == nullptr) {
//         return 0;  
//     } 
//     return node -> data + sum(node -> LChild) + sum (node -> RChild);
// };


// int maxValue(BSTNode* node){
//     if (node == nullptr) {
//         return INT_MIN; 
//     } 
//     int a = node -> data;
//     int b = maxValue(node -> LChild);
//     int c = maxValue(node -> RChild);
//     return max({a, b, c}); 
// }


// BSTNode* findMin(BSTNode* node) {
//     while (node->LChild != nullptr) {
//         node = node->LChild;
//     }
//     return node;
// }


// BSTNode* delNode(BSTNode* node, int val){
//     if (node == nullptr) {
//         return node;  
//     };
    
//     if(val < node -> data){
//         node -> LChild = delNode(node -> LChild, val);
//     }else if (val > node -> data){
//         node -> RChild = delNode(node -> RChild, val);
//     }else{
//         if(node -> LChild == nullptr && node -> RChild == nullptr){
//             delete node;
//             return nullptr;
//         }else if(node -> LChild == nullptr){
//             BSTNode* temp = node -> RChild;
//             delete node;
//             return temp;
//         }else if(node -> RChild == nullptr){
//             BSTNode* temp = node -> LChild;
//             delete node;
//             return temp;
//         }else{
//         BSTNode* temp = findMin(node -> RChild);
//         node -> data = temp -> data;
//         node -> RChild = delNode( node -> RChild, temp -> data);
//         }
//     }
//     return node;
// }



// int main() {
//     // delNode(root, 60);
//     BSTNode* root = nullptr;
//     root = insert(root,150);
//     root = insert(root,90);
//     root = insert(root,20);
//     root = insert(root,60);
//     Preorder(root);
//     // cout<<size(root);
//     // cout<<sum(root);
//     // cout<<maxValue(root);
//     cout<<endl;
//     delNode(root, 90);
//     Preorder(root);
//     // BSTNode*  result = Search(root, 10);
//     //  if (result) {
//     //     cout << "Found: " << result->data << endl;
//     // }
   
//     return 0;
// }