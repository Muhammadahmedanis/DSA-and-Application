// POSTFIX EVALUATION USING STACK

// #include <iostream>
// #include <stack>
// using namespace std;

// int getValue(char ch){
//     if(ch == 'a') return 1;
//     if(ch == 'b') return 2;
//     if(ch == 'c') return 4;
//     if(ch == 'd') return 2;
//     if(ch == 'x') return 5;
//     return 0;
// }

// int evaluatePostFix(string expr){
//     stack<int> st;
    
//     for(int i = 0; i < expr.length(); i++){
//         char ch = expr[i];
//         if(ch >= '0' && ch <= '9'){
//             int num = ch - 48;
//             st.push(num);
//         }else if(ch >= 'a' && ch <= 'z'){
//             st.push(getValue(ch));
//         }else{
//             int b = st.top(); st.pop();
//             int a = st.top(); st.pop();
            
//             switch(ch){
//                 case '+': st.push(a + b); break;
//                 case '-': st.push(a - b); break;
//                 case '*': st.push(a * b); break;
//                 case '/': st.push(a / b); break;
//             }
//         }
//     }
//     return st.top();
// }

// int main() {
//     string postFix = "124*2/+125*+5/-";
//     cout<<"PostFix evaluation: "<<evaluatePostFix(postFix);
//     return 0;
// }



//String Infix to Postfix conversion using stack


// int precedence(char op){
//     if(op == '+' || op == '-') return 1;
//     if(op == '*' || op == '/') return 2;
//     return 0;
// }


// string infixToPostfix(string infix){
//     stack<char> opStack;
//     string postFix = "";    
//     for(int i = 0; i < infix.length(); i++){
//         char ch = infix[i];
//         if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || 
//             (ch >= '0' && ch <= '9') ){
//             postFix += ch;
//         }else if(ch == '('){
//             opStack.push(ch);            
//         }else if(ch == ')'){
//             while(!opStack.empty() && opStack.top() != '('){
//                 postFix += opStack.top();
//                 opStack.pop();
//             }
//             if(!opStack.empty()) opStack.pop();
//         }else{
//             while(!opStack.empty() && 
//             precedence(ch) <= precedence(opStack.top())){
//             postFix += opStack.top();
//             opStack.pop();
//          }
//          opStack.push(ch);
//         }
//     }
//     while(!opStack.empty()){
//        postFix += opStack.top();
//        opStack.pop();
//     }
//     return postFix;
// };



// int main(){
//     string infix;
//     cout<<"Enter an infix expression: ";
//     cin>>infix;
//     string postFix = infixToPostfix(infix);
//     cout<<"PostFix expression: "<<postFix;
// }



// Infix expression tree using stack



// struct Node{
//     char value;
//     Node* left;
//     Node* right;
    
//     Node(char v){
//         value = v;
//         left = right = NULL;
//     }
// };


// int precedence(char op){
//     if(op == '+' || op == '-') return 1;
//     if(op == '*' || op == '/') return 2;
//     return 0;
// }


// string infixToPostfix(string infix){
//     stack<char> opStack;
//     string postFix = "";
    
//     for(int i = 0; i < infix.length(); i++){
//         char ch = infix[i];
//         if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || 
//             (ch >= '0' && ch <= '9') ){
//             postFix += ch;
//         }else if(ch == '('){
//             opStack.push(ch);            
//         }else if(ch == ')'){
//             while(!opStack.empty() && opStack.top() != '('){
//                 postFix += opStack.top();
//                 opStack.pop();
//             }
//             if(!opStack.empty()) opStack.pop();
//         }else{
//             while(!opStack.empty() && 
//             precedence(ch) <= precedence(opStack.top())){
//             postFix += opStack.top();
//             opStack.pop();
//          }
//          opStack.push(ch);
//         }
//     }
//     while(!opStack.empty()){
//       postFix += opStack.top();
//       opStack.pop();
//     }
//     return postFix;
// };


// Node* buildExpressionTree(string postFix){
//     stack<Node*> st;
    
//     for(int i = 0; i < postFix.length(); i++){
//         char ch = postFix[i];
//         Node* newNode = new Node(ch);
//         if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || 
//             (ch >= '0' && ch <= '9') ){
//             st.push(newNode);
//         }else{
//             newNode -> right = st.top(); st.pop();
//             newNode -> left = st.top(); st.pop();
//             st.push(newNode);
//         }
//     }
    
//     return st.top();
// }

// void inorder(Node* root){
//     if(root != NULL){
//       bool isOp = (root->value == '+' || root->value == '-' || 
//                     root->value == '*' || root->value == '/');
//         if (isOp) cout << "(";
//         inorder(root->left);
//         cout << root->value;
//         inorder(root->right);
//         if (isOp) cout << ")";
//     }
// }

// int main(){
//     string infix;
//     cout<<"Enter an infix expression: ";
//     cin>>infix;
    
//     string postFix = infixToPostfix(infix);
//     cout<<"PostFix expression: "<<postFix;
    
//     Node* root =buildExpressionTree(postFix);
//     cout<<"\nexpression tree: ";
//     inorder(root);
// }
