// Beginning with an empty binary tree, Construct binary search tree by inserting the values in the order given. After constructing a binary tree, perform the following operations on it -

// Perform inorder, preorder and postorder traversal-----done
// Change a tree so that the roles of the left and right pointers are swapped at every node-----------------------done
// Find the height of the tree---------------------------done
// Copy this tree to another tree (operator =)-----------done
// Count number of leaves, number of internal nodes------done
// Erase all nodes in a binary tree----------------------done
// (implement both recursive and iterative methods)


#include<bits/stdc++.h>
using namespace std;

class node
{
    int data;
    node *left, *right;
    public:
        node(){
            left = right = nullptr;
        }
        node(int value){
            data = value;
            left = right = nullptr;
        }
    friend class tree;
};

class tree 
{
    public:
        node *root;
    tree(){
        root = nullptr;
    }
    tree operator=(tree &a){
        tree m1; 
        vector<int> a1234 = a.preorder_a();
        for(int i = 0 ; i < a1234.size(); i++){
            m1.insert(a1234[i]);
        }
        return m1;
    }
    void insert(int v){
        node *curr = root, *prev = nullptr;
        if(curr == nullptr){
            curr = new node(v);
            root = curr;
        } 
        else{
            while(curr != nullptr){
                prev = curr;
                if (v > curr->data){
                    curr = curr->right;
                }
                else if (v < curr->data){
                    curr = curr->left;
                }
                else {
                    cout<<"Node already exist"<<endl;
                }
            }
            if (v > prev-> data){
                prev->right = new node(v);
            }
            else if(v < prev-> data){
                prev -> left = new node(v);
            }
            else {
                cout<<"Node already exist"<<endl;
            }
        }
    }
    void preorder(){
        stack<node*> po;
        node* curr = root;
        po.push(curr);
        while(!(po.empty())){
            node* temp = po.top();
            po.pop();
            cout<<temp->data<<" ";
            if (temp->right!=nullptr) {
            po.push(temp->right);}
            if (temp->left!=nullptr){
            po.push(temp->left); }          
        }

    }
    vector<int> preorder_a(){
        vector<int> a111;
        stack<node*> po;
        node* curr = root;
        po.push(curr);
        while(!(po.empty())){
            node* temp = po.top();
            po.pop();
            a111.push_back(temp->data);
            if (temp->right!=nullptr) {
            po.push(temp->right);}
            if (temp->left!=nullptr){
            po.push(temp->left); }          
        }
        return a111;
    }
    void postorder(){
        stack<node*> po;
        stack<node*> po2;
        node* curr = root;
        po.push(curr);
        while(!(po.empty())){
            node* temp = po.top();
            po.pop();
            po2.push(temp);
            if (temp->left!=nullptr){
            po.push(temp->left); }          
            if (temp->right!=nullptr) {
            po.push(temp->right);}
        }
        while(!po2.empty()){
            cout<<po2.top()->data<<" ";
            po2.pop();
        }
    }
    void nodes(){
        int internal  = 0;
        int leave = 0;
        stack<node*> po;
        stack<node*> po2;
        node* curr = root;
        po.push(curr);
        while(!(po.empty())){
            node* temp = po.top();
            po.pop();
            po2.push(temp);
            if (temp->left!=nullptr){
            po.push(temp->left); }          
            if (temp->right!=nullptr) {
            po.push(temp->right);}
        }
        while(!po2.empty()){
            node* temp = po2.top();
            po2.pop();
            if(temp->right == nullptr && temp->left == nullptr){
                leave+=1;
            }
            else {
                internal+=1;
            }   
        }
        cout<<"No. of internal nodes : "<<internal<<endl;
        cout<<"No. of leaf nodes : "<<leave<<endl;

    }
    void inorder(){
        stack<node*> io;
        node* curr = root;
        while(curr != nullptr || !io.empty()){
        while(curr!=nullptr){
            io.push(curr);
            curr = curr->left;
        }
        curr = io.top();
        io.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
        }
    }
    int hieght(){
        queue<node*> q;
        int hieght1 = 0; 
        node *curr = root;
        q.push(curr);
        while(!q.empty()){
            int temp = q.size();
            for(int i = 0 ; i < temp ; i++){
                node* temp1 = q.front();
                q.pop();
                if (temp1->left!=nullptr){
                    q.push(temp1->left); }          
                if (temp1->right!=nullptr) {
                    q.push(temp1->right);}
            }
            hieght1 +=1;
        }
        return hieght1-1;
    }


};

int main(){
    tree m;
    m.insert(7);
    m.insert(4);
    m.insert(10);
    m.insert(2);
    m.insert(6);
    m.insert(8);
    m.insert(12);
    m.insert(1);
    m.insert(0);
    m.insert(-12);
    m.insert(-112);
    m.inorder();
    m.preorder();
    m.postorder();
    m.nodes();
    tree m2 = m;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    m2.inorder();
    m2.preorder();
    m2.postorder();
    m2.nodes();
    cout << endl<<"Hieght of the tree : "<<m.hieght()<< endl;
}