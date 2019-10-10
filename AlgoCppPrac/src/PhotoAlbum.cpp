#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    struct node * next;
    int n;

    node() {
        n = -1;
        next = NULL;
    }
    node(int num) {
        n = num;
        next = NULL;
    }

} Node;

bool isNodeEmpty(Node* node) {
    return node->n == -1;
}

Node* findEmptyNode(Node* node) {
    while (node->next != NULL) {
        if (isNodeEmpty(node)) {
            return node;
        }
        node = node->next;
    }
}

vector<int> photoAlbum(vector<int> index, vector<int> identity) {
    Node * head = NULL;
    Node * temp = head;
    unordered_map<int, Node*> indexMap;
    for (int i = 0; i < identity.size(); ++i) {
        if (head == NULL) {
            head = new Node();
            temp = head;
        } else {
            temp->next = new Node();
            temp = temp->next;
        }
        indexMap[i] = temp;
    }

    for (int i = 0; i < identity.size(); ++i) {
        Node* insertAt = NULL;
        if (indexMap.find(index[i]) != indexMap.end()) {
            insertAt = indexMap[index[i]];
        }
        if (isNodeEmpty(insertAt)) {
            insertAt->n = identity[i];
        } else {
            // insert this in between
            int temp = identity[i];
            while (insertAt != NULL) {
                swap(temp, insertAt->n);
                insertAt = insertAt->next;
            }
        }

    }

    vector<int> res(identity.size());
    int i = 0;
    while (head != NULL) {
        res[i++] = head->n;
        head = head->next;
    }
    return res;
}

int main(int argc, char **argv) {
    vector<int> index { 0, 1, 2, 1, 2 };
    vector<int> identity { 0, 1, 2, 3, 4 };

    vector<int> res = photoAlbum(index, identity);
    for (auto n : res) {
        cout << n << endl;
    }

}

