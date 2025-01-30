#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;

    // Constructor to initialize a node
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Insert a node at the beginning
void insert_at_beginning(Node*& head, int value) {
    Node* new_node = new Node(value);
    if (head != nullptr) {
        head->prev = new_node;
    }
    new_node->next = head;
    head = new_node;
}

// Insert a node at the end
void insert_at_end(Node*& head, int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

// Delete a node by value
void delete_node(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node* temp = head;

    // If the head node is to be deleted
    if (temp->data == value) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return;
    }

    // Traverse to find the node
    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }

    // If node not found
    if (temp == nullptr) {
        cout << "Value not found in the list!" << endl;
        return;
    }

    // Update pointers and delete the node
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    delete temp;
}

// Display the list from the beginning
void display_from_beginning(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    cout << "List (from beginning): ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

// Display the list from the end
void display_from_end(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;

    // Move to the last node
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Traverse backward
    cout << "List (from end): ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "nullptr" << endl;
}

// Main function
int main() {
    Node* head = nullptr;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Delete a node\n";
        cout << "4. Display from beginning\n";
        cout << "5. Display from end\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at the beginning: ";
            cin >> value;
            insert_at_beginning(head, value);
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
            display_from_beginning(head);
            break;
        case 5:
            display_from_end(head);
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
