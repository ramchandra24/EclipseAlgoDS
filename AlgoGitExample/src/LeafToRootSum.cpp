/*
 * LeafToRootSum.cpp
 *
 *  Created on: Jun 20, 2018
 *      Author: RAM
 */


#include <iostream>
#include <climits>

using namespace std;

typedef struct node{
	int data;
	struct node * left;
	struct node * right;
}NODE;

bool RootToLeafSumFoundUtil(NODE *root, int sumValue, int currSum){

	if(NULL == root){
		if(sumValue == currSum){
			return true;
		}
		else{
			return false;
		}
	}

	currSum += root->data;
	bool left = RootToLeafSumFoundUtil(root->left, sumValue, currSum);
	bool right = RootToLeafSumFoundUtil(root->right, sumValue, currSum);

	return (left | right);
}

bool RootToLeafSumFound(NODE* root, int sumValue){
	return RootToLeafSumFoundUtil(root, sumValue, 0);
}

NODE * addNode(int data){
	NODE * nd = new NODE;
	nd->data = data;
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

/*
 * 		   4
 * 		 3   6
 * 		2   5  7
 */
int main(){
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

	int sumValue = 9;

	cout << "RootToLeafSum : " << (RootToLeafSumFound(root, sumValue) ? "true" : "false") << endl;

	return 0;
}


