#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val) : data(val) , next(NULL) {}
};

Node* reverse(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* new_node=reverse(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return new_node;
}

bool ispallindrome(Node* &head){
    if(head==NULL || head->next==NULL) return head;

    Node* slow=head;
    Node* fast=head;

    while(fast->next!=NULL || fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }

    Node* New_node=reverse(slow->next);

    Node* first=head;
    Node* second=New_node;

    while(second){
        if(first->next!=second->next){
            reverse(New_node);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverse(second->next);
    return true;
}