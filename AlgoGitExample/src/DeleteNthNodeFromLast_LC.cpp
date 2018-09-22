/*
 * DeleteNthNodeFromLast_LC.cpp
 *
 *  Created on: Jul 8, 2018
 *      Author: RAM
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* deleteNthFromEnd(ListNode* head, int n) {

	ListNode* reachEnd = head;
	if(!head->next) {
		delete head;
		return NULL;
	}

	for(int i=0; i<n+1; ++i){
		reachEnd = reachEnd->next;
		if(!reachEnd) {
			if(i == n-1){
				ListNode* temp = head;
				delete temp;
				return head->next;
			}
			break;
		}
	}
	ListNode* deleteNode = head;
	while(reachEnd != NULL){
		deleteNode = deleteNode->next;
		reachEnd = reachEnd->next;
	}
	ListNode* temp = deleteNode->next;
	deleteNode->next = temp->next;
	delete temp;
	return head;
}

void printNodes(ListNode* head){
	cout << endl << "List : " << endl;
	while(head != NULL){
		cout << head->val << " ";
		head = head->next;
	}
}

int main(){
	ListNode* head = new ListNode(1);
	ListNode* a = new ListNode(2);
	ListNode* b = new ListNode(3);
	ListNode* c = new ListNode(4);
	ListNode* d = new ListNode(5);

	c->next = d;
	b->next = c;
	a->next = b;
	head->next = a;

	printNodes(head);
	head = deleteNthFromEnd(head, 2);
	printNodes(head);

	return 0;
}

