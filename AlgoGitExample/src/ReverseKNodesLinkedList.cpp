/*
 * ReverseKNodesLinkedList.cpp
 *
 *  Created on: Jun 23, 2018
 *      Author: RAM
 */
#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};



ListNode* reverseGroup(ListNode* headAttach, ListNode* &head, ListNode* &nextHead, int k){

	stack<ListNode* >stck;
	ListNode* tempNode = nextHead;
	for(int i=0; i<k; ++i){
		cout << "push data : " << tempNode->val << endl;
		stck.push(tempNode);
		tempNode = tempNode->next;
	}
	nextHead = tempNode;

	ListNode* tempHead = stck.top();
	cout << "head pop : " << tempHead->val << endl;
	stck.pop();
	if(headAttach)
		headAttach->next = tempHead;
	else
		head = tempHead;

	for(int i=1; i<k; ++i){
		ListNode *temp = stck.top();
		cout << "pop data : " << temp->val << endl;
		stck.pop();
		tempHead->next = temp;
		if(tempHead->next)
			tempHead = tempHead->next;
	}

	return tempHead;
}


ListNode* reverseKGroup(ListNode* head, int k) {

	ListNode *temp = head;
	int size = 0;
	for(; temp != NULL; ++size){
		temp = temp->next;
	}

    if((size < 2) || (k < 2)){
        return head;
    }

	int times = size / k;
	cout << "times : " << times << endl;
	ListNode* headAttach = NULL;
	ListNode* nextHead = head;
	for(int i=0; i<times; ++i){
		ListNode* tail = reverseGroup(headAttach, head, nextHead, k);
		headAttach = tail;
	}
	if(times > 0)
		headAttach->next = nextHead;
	return head;
}

ListNode* newNode(int data){
	ListNode* temp = new ListNode(data);
	return temp;
}

void printNodes(ListNode* head){
	ListNode* tempNode = head;
	cout << "List" << endl;
	while(tempNode){
		cout << tempNode->val << " " ;
		tempNode = tempNode->next;
	}
	cout << endl;
}

/*
 * Input array : 1->2->3->4->5
 * k : 2
 * Output array : 2->1->4->3->5
 */

int main(){
	ListNode* head = newNode(1);
	ListNode* a = newNode(2);
	ListNode* b = newNode(3);
	ListNode* c = newNode(4);
	ListNode* d = newNode(5);

	head->next = a;
	a->next = b;
	b->next = c;
	c->next = d;

	printNodes(head);
	head = reverseKGroup(head, 2);
	printNodes(head);

	return 0;
}

