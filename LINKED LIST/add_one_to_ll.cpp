#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val) : data(val),next(NULL) {}
};

int helper(Node* & temp){
    if(temp==NULL) return 1;
    int carry=helper(temp->next);
    temp->data+=carry;
    if(temp->data < 10){
        return 0;
    }
    temp->data=0;
    return 1;
}
Node* add_one(Node* & head){
    int carry=helper(head);

    if(carry){
        Node* new_node=new Node(carry);
        new_node->next=head;
        head=new_node;
    }
    return head;
}