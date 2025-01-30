#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}

};

// Function to reverse a singly linked list
Node* reverse_singly_linked_list(Node* head) {
    Node* prev = nullptr;   // Pointer to the previous node
    Node* current = head;   // Pointer to the current node
    Node* next = nullptr;   // Pointer to the next node (to avoid losing track of the list)

    while (current != nullptr) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the link
        prev = current;       // Move `prev` one step forward
        current = next;       // Move `current` one step forward
    }

    return prev; // `prev` will be the new head of the reversed list
}


Node* reverse_singly_linked_list(Node* head){
    if(head==NULL || head->next==NULL) return head;

    Node* new_head=reverse_singly_linked_list(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return new_head;
}