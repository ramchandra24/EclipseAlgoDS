/*
 * CommonAncestor.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: RAM
 */

#include <iostream>

using namespace std;

typedef struct node{
	int data;
	struct node * left;
	struct node * right;
}NODE;

NODE * addNode(int data){
	NODE * nd = new NODE;
	nd->data = data;
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}


NODE * ShortestCommonAncestor(NODE * root, int a, int b) {

	if(NULL == root)
		return NULL;

	if((a == root->data) || (b == root->data)){
		return root;
	}
	else{
		NODE * leftNodeFound = NULL, *rightNodeFound = NULL;
		if(root->left){
			leftNodeFound = ShortestCommonAncestor(root->left, a, b);
		}
		if(root->right){
			rightNodeFound = ShortestCommonAncestor(root->right, a, b);
		}

		if(leftNodeFound && rightNodeFound)
			return root;

		else if(leftNodeFound)
			return leftNodeFound;

		else if(rightNodeFound)
			return rightNodeFound;

		else
			return NULL;
	}
}

/*
 * 		   4
 * 		 3   6
 * 		2	5  7
 */


int main() {
		NODE * root = addNode(4);
		NODE * a = addNode(2);
		NODE * b = addNode(3);
		NODE * c = addNode(5);
		NODE * d = addNode(6);
		NODE * f = addNode(7);
		root->left = b;
		root->right = d;
		b->left = a;
		d->left = c;
		d->right = f;

	NODE * sca = ShortestCommonAncestor(root, 2, 7);

	cout << "ShortestCommonAncestor : " << sca->data << endl;

	return 0;
}


