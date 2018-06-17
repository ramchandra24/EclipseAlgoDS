//============================================================================
// Name        : AlgoGitExample.cpp
// Author      : Ram
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>

using namespace std;

typedef struct node{
	int data;
	struct node * left;
	struct node * right;
}NODE;

bool isBSTUtil(NODE * root, int min, int max){

	if(NULL == root)
		return true;

	// cout << "data: " << root->data << " :: min: " << min << " :: max: " << max << endl;
	if(root->data < min || root->data > max)
		return false;

	return (isBSTUtil(root->left, min, root->data) & isBSTUtil(root->right, root->data, max));
}

bool isBST(NODE * root){
	return isBSTUtil(root, INT_MIN, INT_MAX);
}

NODE * addNode(int data){
	NODE * nd = new NODE;
	nd->data = data;
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

int main(){
	NODE * root = addNode(2);
	root->left = addNode(5);
	root->right = addNode(6);

	cout << "isBST : " << (isBST(root) ? "true" : "false") << endl;

	return 0;
}

