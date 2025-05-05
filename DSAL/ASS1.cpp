//============================================================================
// Name        : ass1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. After constructing a binary tree -

// Insert new node,-----------------------------------------------------------------------------done
// Find number of nodes in longest path from root,----------------------------------------------done
// Minimum data value found in the tree,--------------------------------------------------------done
// Change a tree so that the roles of the left and right pointers are swapped at every node,----done
// Search a value.------------------------------------------------------------------------------done

#include <iostream>
using namespace std;

class node{
	int data;
	node* left;
	node* right;
public:
	node(){
		left = nullptr;
		right = nullptr;
		data = 0 ;
	}
	node(int v){
		data = v;
		left= nullptr;
		right = nullptr;
	}
	friend class tree;
};

class tree{
public:
	node *root;
	tree(){
		root = nullptr;
	}
	void insert(int value){
		node *curr = root;
		node *prev = nullptr;
		if (root == nullptr){
			cout<<"Root is being created..."<<endl;
			root = new node(value);
		}
		else{
			while(curr != nullptr){
				prev = curr;
				if(value>curr->data){
					curr = curr->right;
				}
				else if(value<curr->data){
					curr = curr->left;
				}
				else{
					cout<<"Node already exists."<<endl;
				}
			}
			if(value>prev->data){
				curr = new node(value);
				prev->right =  curr;

			}
			else{
				curr = new node(value);
				prev->left = curr;
			}
		}
	}
	void swap(node*root){
		if (root!=nullptr){
			node*temp= root->right;
			root->right = root->left;
			root->left = temp;
			swap(root->left);
			swap(root->right);
		}
	}

	void display_inorder(node *root){
		if(root != nullptr){
			display_inorder(root->left);
			cout<<root->data<<" ";
			display_inorder(root->right);
		}
	}
	int minvalue(node *root){
		node* prev;
		while(root!=nullptr){
			prev = root;
			root = root->left;
		}
		return prev->data;
	}
	int longest_hieght(node *root){
		if (root == nullptr){
			return 0;
		}
		else {
			return 1+(max(longest_hieght(root->left), longest_hieght(root->right)));
		}

	}
	bool search(node* root, int v){
		if (root != nullptr){
		if (root->data == v){
			cout<<"Found!!"<<endl;
			return true;
		}
		else{
			if (v>root->data){
				root = root->right;
				search(root, v);
			}
			else{
				root = root->left;
				search(root, v);
			}
		}
		cout<<"Not Found!!"<<endl;
		return false;
	}}
};
int main() {
	tree m;
	m.insert(10);
	m.insert(20);
	m.insert(5);
	m.insert(30);
	m.insert(0);
	m.insert(40);
	m.insert(2);
	m.insert(11);
	m.insert(50);
	m.insert(60);
	m.insert(70);
	m.display_inorder(m.root);
	int h = m.longest_hieght(m.root);
	cout<<endl;
	cout<<"longest hieght : "<<h <<endl;
	cout<< "Value 77  " << " ";
	cout<<m.search(m.root, 77)<<endl;
	m.swap(m.root);
	m.display_inorder(m.root);
	return 0;
}
