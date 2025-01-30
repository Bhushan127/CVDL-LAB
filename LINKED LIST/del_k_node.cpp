#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* delete_k_node(Node*& head, int k) {
    Node* fast = head;
    Node* slow = head;

    // Move `fast` k steps ahead
    for (int i = 0; i < k; i++) {
        if (fast == NULL) return head; // k is greater than the length of the list
        fast = fast->next;
    }

    // If `fast` is NULL, remove the head node
    if (fast == NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Move both `fast` and `slow` pointers until `fast` reaches the last node
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete the `k`-th node from the end
    Node* node_to_delete = slow->next;
    slow->next = slow->next->next;
    delete node_to_delete;

    return head;
}
