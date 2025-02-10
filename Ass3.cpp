#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node() {
        left = nullptr;
        right = nullptr;
        data = 0;
    }
    node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

void insert(node*& root, int val) {
    node* p = new node(val);
    if (root == nullptr) {
        root = p;
    }
    else {
        node* temp = root;
        while (true) {
            cout << "1. For Left Insert of " << temp->data << endl;
            cout << "2. For Right Insert of " << temp->data << endl;
            int c;
            cout << "Enter your choice: ";
            cin >> c;

            if (c == 1) {
                if (temp->left == nullptr) {
                    temp->left = p;
                    break;
                }
                else {
                    temp = temp->left;
                }
            }
            else if (c == 2) {
                if (temp->right == nullptr) {
                    temp->right = p;
                    break;
                }
                else {
                    temp = temp->right;
                }
            }
            else {
                cout << "Invalid choice! Please choose either 1 or 2." << endl;
            }
        }
    }
}

void inorder(node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    cout << endl;
}

void postorder(node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    cout << endl;
}

void preorder(node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    cout << endl;
}

void levelorder(node* root) {
    queue<node*> q;
    if (root != nullptr) {
        q.push(root);
        while (!q.empty()) {
            node* y = q.front();
            q.pop();
            cout << y->data << " ";
            if (y->left != nullptr) {
                q.push(y->left);
            }
            if (y->right != nullptr) {
                q.push(y->right);
            }
        }
    }
    cout << endl;
}

node* clone(node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    node* p1 = new node(root->data);
    p1->left = clone(root->left);
    p1->right = clone(root->right);
    return p1;
}

bool equal(node* root1, node* root2){
    bool a1;
    bool a2;
    bool a3;
    if(root1==nullptr&&root2==nullptr){
        return true;
    }
    if(root1==nullptr||root2==nullptr){
        return false;
    }
    
    else{
        a1=root1->data==root2->data;
        a2=equal(root1->left,root2->left);
        a3=equal(root1->right,root2->right);
    }
    if(a1==true&&a2==true&a3==true){
        return true;
    }
    else{
        return false;
    }
}

node* mirror(node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    node* p1 = new node(root->data);
    p1->left = mirror(root->right);
    p1->right = mirror(root->left);
    return p1;
}

int main() {
    node* root = nullptr;
    node* root2 = nullptr;
    int n;
    cout << "Enter the number of nodes to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter node value: ";
        cin >> value;
        insert(root, value);
    }

    bool yu = true;
    while (yu) {
        const char* str = "          Menu\n\
                        0.  Create Binary Tree\n\
                        1.  Preorder (Recursive & Non-Recursive)\n\
                        2.  Postorder (Recursive & Non-Recursive)\n\
                        3.  Inorder (Recursive & Non-Recursive)\n\
                        4.  Level Order\n\
                        5.  Make a clone\n\
                        6.  Check if two trees are equal\n\
                        7.  Create mirror image\n\
                        8.  Create Binary Search Tree\n\
                        9.  Delete node from BST\n\
                        10. Construct BST from preorder & postorder\n\
                        11. Find height of tree";
        int ch;
        cout << str;
        cout << "\nEnter your choice : ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Preorder traversal: ";
                preorder(root);
                break;
            case 2:
                cout << "Postorder traversal: ";
                postorder(root);
                break;
            case 3:
                cout << "Inorder traversal: ";
                inorder(root);
                break;
            case 4:
                cout << "Level order traversal: ";
                levelorder(root);
                break;
            case 5:
                cout<<"Making a Clone: ";
                clone(root);
                break;
            case 6:
                cout<<"Check Equal: ";
                equal(root,root2);
                break;
            case 7:
                cout<<"Creating a Mirror image";
                mirror(root);
                break;
            case 8:
                
            case 9:
                
            case 10:
                
            case 11:
                
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

        cout << "Continue ? ";
        string st;
        cin >> st;
        if (st != "Y" && st != "y") {
            yu = false;
        }
    }

    return 0;
}
