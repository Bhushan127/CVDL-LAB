#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Insert at the beginning
void insert_at_begining(Node*& head,int val){
    Node* new_node=new Node(val);
    new_node->next=head;
    head=new_node;
}

// Insert at the end
void insert_at_end(Node*& head,int val){
    Node* new_node=new Node(val);
    if(head==NULL){
        head=new_node;
        return;
    }
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=new_node;
}

// Delete a node
void delete_node(Node*& head,int key){
    if(head==NULL) return;
    if(head->data==key){
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }
    //traverse
    Node* temp=head;
    while(temp->next && temp->next->data!=key){
        temp=temp->next;
    }

    if(temp->next==NULL){
        cout<<"Node not found"<<endl;
    }
     Node* node_to_delete=temp->next;
     temp->next=temp->next->next;
     delete node_to_delete;
}


// Display the list
void display(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

// Count the number of nodes
int count_nodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Search for a node
bool search_node(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Main function
int main() {
    Node* head = nullptr;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Delete a value\n";
        cout << "4. Display the list\n";
        cout << "5. Count nodes\n";
        cout << "6. Search for a node\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at the beginning: ";
            cin >> value;
            insert_at_begining(head, value);
            break;
        case 2:
            cout << "Enter value to insert at the end: ";
            cin >> value;
            insert_at_end(head, value);
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            delete_node(head, value);
            break;
        case 4:
            display(head);
            break;
        case 5:
            cout << "Number of nodes in the list: " << count_nodes(head) << endl;
            break;
        case 6:
            cout << "Enter value to search: ";
            cin >> value;
            if (search_node(head, value)) {
                cout << "Value found in the list!" << endl;
            } else {
                cout << "Value not found in the list!" << endl;
            }
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
