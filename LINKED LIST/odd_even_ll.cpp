#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


Node* head(Node* &head){
    Node* odd=head;
    Node* even=head->next;
    Node* even_head=head->next;

    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=even_head;
    return head;
}