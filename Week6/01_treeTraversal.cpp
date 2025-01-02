#include <iostream>
#include <queue>
using namespace std;

// Define a Node for the binary tree
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to build a binary tree from user input
Node* buildTree() {
    cout << "Enter the root value (-1 for NULL): ";
    int rootValue;
    cin >> rootValue;

    if (rootValue == -1) return nullptr; // NULL node

    Node* root = new Node(rootValue);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftValue, rightValue;
        cout << "Enter the left child of " << current->value << " (-1 for NULL): ";
        cin >> leftValue;

        if (leftValue != -1) {
            current->left = new Node(leftValue);
            q.push(current->left);
        }

        cout << "Enter the right child of " << current->value << " (-1 for NULL): ";
        cin >> rightValue;

        if (rightValue != -1) {
            current->right = new Node(rightValue);
            q.push(current->right);
        }
    }

    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->value << " ";
        inorderTraversal(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->value << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->value << " ";
    }
}

int main() {
    cout << "Build your binary tree:\n";
    Node* root = buildTree();

    cout << "\nTree Traversals:\n";
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
