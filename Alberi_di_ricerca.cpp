#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Funzione per inserire un nodo nell'albero
TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) {
        return new TreeNode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Funzione per cercare un valore nell'albero
bool search(TreeNode* root, int key) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == key) {
        return true;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Funzione per trovare il nodo minimo nell'albero
TreeNode* findMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Funzione per eliminare un nodo dall'albero
TreeNode* remove(TreeNode* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->data) {
        root->left = remove(root->left, key);
    } else if (key > root->data) {
        root->right = remove(root->right, key);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    }

    return root;
}

// Funzione per stampare l'albero in ordine
void inOrderPrint(TreeNode* root) {
    if (root != nullptr) {
        inOrderPrint(root->left);
        cout << root->data << " ";
        inOrderPrint(root->right);
    }
}

// Funzione per trovare il successore di un nodo
TreeNode* findSuccessor(TreeNode* root, int key) {
    TreeNode* current = root;
    TreeNode* successor = nullptr;

    while (current != nullptr) {
        if (key < current->data) {
            successor = current;
            current = current->left;
        } else if (key > current->data) {
            current = current->right;
        } else {
            if (current->right != nullptr) {
                return findMin(current->right);
            }
            break;
        }
    }

    return successor;
}

// Funzione per trovare il predecessore di un nodo
TreeNode* findPredecessor(TreeNode* root, int key) {
    TreeNode* current = root;
    TreeNode* predecessor = nullptr;

    while (current != nullptr) {
        if (key > current->data) {
            predecessor = current;
            current = current->right;
        } else if (key < current->data) {
            current = current->left;
        } else {
            if (current->left != nullptr) {
                return findMax(current->left);
            }
            break;
        }
    }

    return predecessor;
}

// Funzione per verificare se un albero è un BST
bool isBSTUtil(TreeNode* node, int min, int max) {
    if (node == nullptr) {
        return true;
    }

    if (node->data < min || node->data > max) {
        return false;
    }

    return isBSTUtil(node->left, min, node->data - 1) &&
           isBSTUtil(node->right, node->data + 1, max);
}

bool isBST(TreeNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    TreeNode* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "In-order traversal: ";
    inOrderPrint(root);
    cout << endl;

    int key = 40;
    cout << "Search for " << key << ": " << (search(root, key) ? "Found" : "Not found") << endl;

    key = 55;
    cout << "Search for " << key << ": " << (search(root, key) ? "Found" : "Not found") << endl;

    key = 30;
    root = remove(root, key);
    cout << "In-order traversal after removing " << key << ": ";
    inOrderPrint(root);
    cout << endl;

    cout << "Is the tree a binary search tree? " << (isBST(root) ? "Yes" : "No") << endl;

    key = 60;
    TreeNode* successor = findSuccessor(root, key);
    cout << "Successor of " << key << ": " << (successor ? to_string(successor->data) : "N/A") << endl;

    key = 60;
    TreeNode* predecessor = findPredecessor(root, key);
    cout << "Predecessor of " << key << ": " << (predecessor ? to_string(predecessor->data) : "N/A") << endl;

    return 0;
}
