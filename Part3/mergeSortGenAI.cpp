struct Node {                   //node structure
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

//function to split the list 
Node* getMiddle(Node* head) {
    if (head == nullptr)
        return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // slow is middle node
}
//merge two sorted linked lists
Node* mergeLists(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->data < b->data) {
        a->next = mergeLists(a->next, b);
        return a;
    } else {
        b->next = mergeLists(a, b->next);
        return b;
    }
}
//merge sort function
Node* mergeSort(Node* head) {
    // Base case: 0 or 1 node → already sorted
    if (!head || !head->next)
        return head;

    // 1. Find the middle
    Node* mid = getMiddle(head);
    Node* nextHalf = mid->next;
    mid->next = nullptr;   // Split list into two halves

    // 2. Sort each half
    Node* left = mergeSort(head);
    Node* right = mergeSort(nextHalf);

    // 3. Merge the sorted halves
    return mergeLists(left, right);
}
//helper function to print the list
#include <iostream>
using namespace std;

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void pushFront(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
 //main function
 int main() {
    Node* head = nullptr;

    pushFront(head, 3);
    pushFront(head, 1);
    pushFront(head, 5);
    pushFront(head, 2);
    pushFront(head, 4);

    cout << "Original list: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted list:   ";
    printList(head);

    return 0;
}




