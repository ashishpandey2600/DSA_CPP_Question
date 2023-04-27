#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+10;
int arr[N];


//Time Complexity O(n)
class Node{
public:
	int data;
	Node*right;
	Node*left;
	Node(int val){
		data = val;
		right=NULL;
		left = NULL;
	}
};

Node* insertBST(Node*root, int val){

	if(root ==NULL){
		return new Node(val);
	}
	if(val< root->data){
		root->left = insertBST(root->left,val);
	}else{
		//val->root->data
		root->right = insertBST(root->right,val);
	}
	return root;
}

void inorder(Node* root){
	if(root == NULL){
		return;
	}
	inorder (root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

//Searching
//worst case we travel the height of tree

//height = log(n+1)
//time complexity = O(log n)//search in BSt

Node* searchInBST(Node*root,int key){

	if(root ==NULL){
		return NULL;
	}
	if(root->data==key){
		return root;
	}
	//data > key to search kro left subtree mai
	if(root->data > key){
		return searchInBST(root->left,key);

	}
	//data > key
	
	return searchInBST(root->right,key);
}

//Delete node of Binary search tree
// case 1 delete only leaf node 
//case 2 delete the child node of any node which is not the leaf
//Replace node with child and 

//case 3 node has two children
//step1. find the inorder successor - in binary tree the child after target child; suppose for 3 is four

Node* inorderSucc(Node* root){
	Node* curr = root;
	while(curr && curr->left!=NULL){
		curr = curr->left;


	}
	return curr;
}

Node* deleteInBST(Node*root,int key){
	//key the value to delete

	if(key< root->data){
		root ->left = deleteInBST(root->left,key);

	}
	else if(key> root->data){
		root->right = deleteInBST(root->right,key);
	}
	else {
		if(root->left == NULL){
			Node* temp =root-> right;
			free(root);
			return temp;
		}
		else if(root->right ==NULL){
			Node*temp =root-> left;
			free(root);
			return temp;
		}
		//Case 3
		Node* temp = inorderSucc(root-> right);
		root->data = temp->data;
		root->right = deleteInBST(root->right,temp->data);

	}
	return root;


}

int main()
{
	Node * root =NULL;
	root = insertBST(root,5);
	insertBST(root,1);
	insertBST(root,3);
	insertBST(root,4);
	insertBST(root,2);
	insertBST(root,7);

	Node* k =searchInBST(root,7);
  



	//print inorder
	inorder(root);
	cout<<'\n'<<endl;

    if(k==NULL)
    {
    	cout<<"key doesn't exist"<<endl;
    }
    else{
    	cout<<"key exist"<<k->data<<endl;
    }
     root = deleteInBST(root,5);

     inorder(root);

	
}