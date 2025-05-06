// Create an inordered threaded binary tree. Perform inorder, preorder traversals without recursion and deletion of a node. Analyze time and space complexity of algorithm.
#include<bits/stdc++.h>
using namespace std;

class node{
    int data;
    bool rthread;
    node *left, *right;
    public:
    friend class tree;
    node(){
        rthread = false;
        left = right = nullptr;
    }
    node(int v ){
        rthread = false;
        left = right = nullptr;
        data = v;

    }
};

class tree{

}







































































































































































































// class tree{
//     public:
//         node* root;
//     void insert(int v){
//         node* curr;
//         curr = root;
//         node *prev = nullptr, *temp=nullptr;
//         if(curr==nullptr){
//             curr = new node(v);
//             root = curr;
//         }
//         else{
//             bool rthread1 = false;
//             while(curr!=nullptr){
//                 prev = curr;
//                 if(v<curr->data){
//                     temp=curr;
//                     curr=curr->left;
//                     bool rthread1 = true;
//                 }
//                 else if(v>curr->data){
//                     curr=curr->right;
//                 }
//                 else{
//                     cout<<"node already exists"<<endl;
//                 }
//             }
//             if(v>prev->data){
//                 curr = new node(v);
//                 prev->right = curr;
//                 if(rthread1){
//                     curr->right=temp;
//                     curr->rthread = true;
//                 }
//             }
//             else if(v<prev->data){
//                 curr = new node(v);
//                 prev->left=curr;
//                 curr->right=prev;
//             }
//         }
//     }
//     void display(){
//         node *curr = root;
//         if (curr!=nullptr)
//         {        
//             while(curr->right != nullptr){
//             while(curr->left!=nullptr){
//                 cout<<curr->data<<" ";
//                 curr = curr->left;
//                 }
//                 curr = curr->right;
//             }
//         }
//     }    

// };
// int main(){
//     tree m;
//     m.insert(50);
//     m.insert(25);
//     m.insert(75);
//     m.insert(12);
//     m.insert(37);
//     m.insert(62);
//     m.insert(87);
//     m.insert(6);
//     m.insert(18);
//     m.insert(31);
//     m.insert(43);
//     m.insert(56);
//     m.insert(68);
//     m.insert(81);
//     m.insert(93);
//     m.display();
// }