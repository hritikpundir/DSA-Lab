#include <iostream>
using namespace std;

// Node structure for the Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert a new node into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Find the minimum value node in the BST (used in delete operation)
Node* findMin(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Delete a node from the BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    // Traverse the tree to find the node to delete
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Search for a key in the BST
bool search(Node* root, int key) {
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

// Inorder traversal of the BST
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int choice, value;

    while (true) {
        cout << "\nBinary Search Tree Operations Menu:";
        cout << "\n1. Insert Element";
        cout << "\n2. Delete Element";
        cout << "\n3. Search Element";
        cout << "\n4. Display (Inorder Traversal)";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;

            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;

            case 3:
                cout << "Enter the value to search: ";
                cin >> value;
                if (search(root, value)) {
                    cout << "Element found in the BST.";
                } else {
                    cout << "Element not found in the BST.";
                }
                break;

            case 4:
                cout << "Inorder Traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;

            case 5:
                cout << "Exiting program.";
                return 0;

            default:
                cout << "Invalid choice. Please try again.";
        }
    }
}
