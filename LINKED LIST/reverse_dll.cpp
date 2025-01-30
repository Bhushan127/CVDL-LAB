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
            new_node->prev = tail;  // Link the new node back to the current tail
            tail = new_node;        // Move the tail to the new node
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

// Function to reverse the doubly linked list
Node* reverse_dll(Node* head) {
    if (head == nullptr) return nullptr; // If list is empty, return nullptr

    Node* current = head;
    Node* temp = nullptr;

    // Traverse the DLL and reverse the pointers of each node
    while (current != nullptr) {
        // Swap the 'next' and 'prev' pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node (which is now prev due to reversal)
        current = current->prev;
    }

    // After the loop, the 'temp' will be pointing to the new head (last node)
    if (temp != nullptr) {
        head = temp->prev; // Set the head to the last node
    }

    return head; // Return the new head of the reversed DLL
}

// Main function
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create DLL from the array
    Node* head = create_dll_from_array(arr, size);

    // Display the original DLL
    cout << "Original Doubly Linked List:" << endl;
    display_from_beginning(head);

    // Reverse the DLL
    head = reverse_dll(head);

    // Display the reversed DLL
    cout << "Reversed Doubly Linked List:" << endl;
    display_from_beginning(head);

    return 0;
}
