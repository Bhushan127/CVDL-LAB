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

// Function to create a doubly linked list from a given array
Node* create_dll_from_array(int arr[], int size) {
    if (size == 0) return nullptr; // If array is empty, return nullptr

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < size; i++) {
        Node* new_node = new Node(arr[i]); // Create a new node

        if (head == nullptr) {
            // First node becomes the head and tail
            head = new_node;
            tail = new_node;
        } else {
            // Append the new node to the DLL
            tail->next = new_node;  // Link the current tail to the new node
            new_node->prev = tail; // Link the new node back to the current tail
            tail = new_node;       // Move the tail to the new node
        }
    }

    return head; // Return the head of the doubly linked list
}

// Function to display the list from the beginning
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

// Function to display the list from the end
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

// Function to validate the prev and next pointers of head and tail
void validate_pointers(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    // Validate head's prev
    cout << "First node's prev: " << (head->prev == nullptr ? "nullptr" : "not null") << endl;

    // Move to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Validate tail's next
    cout << "Last node's next: " << (temp->next == nullptr ? "nullptr" : "not null") << endl;
}

// Main function
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create DLL from the array
    Node* head = create_dll_from_array(arr, size);

    // Display the DLL from beginning
    cout << "Doubly Linked List:" << endl;
    display_from_beginning(head);

    // Display the DLL from the end
    display_from_end(head);

    // Validate the prev and next pointers of the head and tail
    validate_pointers(head);

    return 0;
}
