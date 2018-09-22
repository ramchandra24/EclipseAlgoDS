/*
 * IsSameBinaryTree.cpp
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


bool IsSameBinaryTree(NODE* aroot, NODE* broot){
	if(NULL == aroot && NULL == broot){
		return true;
	}

	if(NULL == aroot || NULL == broot)
		return false;

	return((aroot->data == broot->data) && (IsSameBinaryTree(aroot->left, broot->left)) &&
			(IsSameBinaryTree(aroot->right, broot->right)));

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
	NODE * aroot = addNode(4);
	NODE * aa = addNode(2);
	NODE * ab = addNode(3);
	NODE * ac = addNode(5);
	NODE * ad = addNode(6);
	NODE * af = addNode(7);
	aroot->left = ab;
	aroot->right = ad;
	ab->left = aa;
	ad->left = ac;
	ad->right = af;

	NODE * broot = addNode(4);
	NODE * ba = addNode(2);
	NODE * bb = addNode(3);
	NODE * bc = addNode(5);
	NODE * bd = addNode(6);
	NODE * bf = addNode(7);
	broot->left = bb;
	broot->right = bd;
	bb->left = ba;
	bd->left = bc;
	bd->right = bf;

	cout << "IsSameBinaryTree : " << (IsSameBinaryTree(aroot, broot) ? "true" : "false") << endl;

	return 0;
}


