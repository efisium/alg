#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Funzione per inserire un nuovo nodo in testa alla linked list
Node* insertAtHead(Node* head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;
}

// Funzione per inserire un nuovo nodo in coda alla linked list
Node* insertAtTail(Node* head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        return newNode;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Funzione per eliminare il primo nodo con un valore specifico
Node* deleteNode(Node* head, int val) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->data == val) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return head;
        }
        current = current->next;
    }

    return head;
}

// Funzione per cercare un valore nella linked list
bool search(Node* head, int val) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == val) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Funzione per stampare la linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    head = insertAtHead(head, 5);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 8);
    head = insertAtTail(head, 1);
    head = insertAtTail(head, 6);

    cout << "Linked List: ";
    printLinkedList(head);

    int searchValue = 8;
    cout << "Ricerca " << searchValue << ": " << (search(head, searchValue) ? "Trovato" : "Non trovato") << endl;

    int deleteValue = 2;
    head = deleteNode(head, deleteValue);
    cout << "Dopo l'eliminazione di " << deleteValue << ": ";
    printLinkedList(head);

    return 0;
}
