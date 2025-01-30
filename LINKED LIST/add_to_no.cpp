#include<bits/stdc++.h>
using namespace std;
struct Node{
    
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* add(Node* &head1,Node* &head2){
    Node* dummynode=new Node(-1);
    Node* curr=dummynode;
    Node* temp1=head1;
    Node* temp2=head2;
    int carry=0;
    while(temp1 || temp2){
        int sum=carry;
        if(temp1) sum+=temp1->data;
        if(temp2) sum+=temp2->data;

        Node* new_node=new Node(sum%10);
        carry=sum/10;

        curr->next=new_node;
        curr=curr->next;

        if(temp1) temp1=temp1->next;
        if(temp2) temp2=temp2->next;
    }
    if(carry){
        Node* new_node=new Node(carry);
        curr->next=new_node;
    }
}