#include <bits/stdc++.h>
using namespace std;
 
class node {
public:
    int data;
    node* left;
    node* right;
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
    } else {
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
                } else {
                    temp = temp->left;
                }
            } else if (c == 2) {
                if (temp->right == nullptr) {
                    temp->right = p;
                    break;
                } else {
                    temp = temp->right;
                }
            } else {
                cout << "Invalid choice! Please choose either 1 or 2." << endl;
            }
        }
    }
}

void inorder(node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void preorder(node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void levelorder(node* root) {
    queue<node*> q;
    if (root) {
        q.push(root);
        while (!q.empty()) {
            node* y = q.front();
            q.pop();
            cout << y->data << " ";
            if (y->left) q.push(y->left);
            if (y->right) q.push(y->right);
        }
    }
}

node* clone(node* root) {
    if (!root) return nullptr;
    node* p1 = new node(root->data);
    p1->left = clone(root->left);
    p1->right = clone(root->right);
    return p1;
}

bool equal(node* root1, node* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    return (root1->data == root2->data) &&
           equal(root1->left, root2->left) &&
           equal(root1->right, root2->right);
}

node* mirror(node* root) {
    if (!root) return nullptr;
    node* p1 = new node(root->data);
    p1->left = mirror(root->right);
    p1->right = mirror(root->left);
    return p1;
}

void create_bst(node*& root, int val) {
    if (!root) {
        root = new node(val);
        return;
    }
    if (val < root->data) {
        create_bst(root->left, val);
    } else {
        create_bst(root->right, val);
    }
}
 
int height(node* root) {
    if (root == nullptr){
        return 0;
    }
    int lt = height(root->left);
    int rt = height(root->right);
    int m2=max(lt,rt)+1;
    return m2;
}

void dele(node* &root, int val) {
    if (root == nullptr) {
        return;
    }
    if (val < root->data) {
        dele(root->left, val);
    } else if (val > root->data) {
        dele(root->right, val);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->left == nullptr) {
            node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            node* temp = root;
            root = root->left;
            delete temp;
        } else {
            node* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            root->data = temp->data;
            dele(root->right, temp->data); 
        }
    }
}

bool searchbst(node* root, int val) {
    node* temp = root;
    while (temp != nullptr) {
        if (temp->data == val) {
            return true;
        }
        else if (temp->data > val) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    return false;
}

node* constructBSTFromPreorder(vector<int>& preorder, int& index, int minVal, int maxVal) {
    if (index >= preorder.size()) return nullptr;
 
    int key = preorder[index];
    if (key < minVal || key > maxVal) return nullptr;
 
    node* root = new node(key);
    index++;
    root->left = constructBSTFromPreorder(preorder, index, minVal, key);
    root->right = constructBSTFromPreorder(preorder, index, key, maxVal);
    return root;
}

node* constructBSTFromPreorder(vector<int>& preorder) {
    int index = 0;
    return constructBSTFromPreorder(preorder, index, INT_MIN, INT_MAX);
}

int main() {
    node* root = nullptr;
    node* root2 = nullptr;
 
    bool yu = false;
    while (true) {
        cout << "\n          Menu\n"
                "0.  Create a Tree\n"
                "1.  Preorder\n"
                "2.  Postorder\n"
                "3.  Inorder\n"
                "4.  Level Order\n"
                "5.  Make a clone\n"
                "6.  Check if two trees are equal\n"
                "7.  Create mirror image\n"
                "8.  Create Binary Search Tree\n"
                "9.  Delete node from BST\n"
                "10. Construct BST from Preorder\n"
                "11. Find height of tree\n"
                "12. Search in BST\n";
 
        int ch;
        cout << "\nEnter your choice: ";
        cin >> ch;
 
        switch (ch) {
            case 0:
                int n;
                cout << "Enter the number of nodes to insert: ";
                cin >> n;
            
                for (int i = 0; i < n; i++) {
                    int value;
                    cout << "Enter node value: ";
                    cin >> value;
                    insert(root, value);
                }
            case 1:
                preorder(root);
                cout << endl;
                break;
            case 2:
                postorder(root);
                cout << endl;
                break;
            case 3:
                inorder(root);
                cout << endl;
                break;
            case 4:
                levelorder(root);
                cout << endl;
                break;
            case 5:
                root2 = clone(root);
                cout << "Clone created." << endl;
                break;
            case 6:
                cout << (equal(root, root2) ? "Trees are equal" : "Trees are not equal") << endl;
                break;
            case 7:
                root2 = mirror(root);
                cout << "Mirror image created." << endl;
                break;
            case 8:
                int v;
                cout << "Enter the number of nodes : ";
                cin >> v;
                for(int i=0;i<v;i++){
                    cout<<"Enter Node : ";
                    int j;cin>>j;
                    create_bst(root2, j);
                }
                break;
            case 9:
                int delVal;
                cout << "Enter value to delete: ";
                cin >> delVal;
                dele(root2, delVal);
                break;
            case 10:
                {int m;
                cout << "Enter size of Preorder: ";
                cin >> m;
                vector<int> preorderVals(m);
                for (int i = 0; i < m; i++) cin >> preorderVals[i];
                root2 = constructBSTFromPreorder(preorderVals);
                break;}
            case 11:
                {cout<<"Calculating height of the tree...";
                int g=height(root2);
                cout<<"Height is : "<<g<<endl;
                break;}
            case 12:
                {cout<<"Enter Value : ";
                int u;cin>>u;
                bool rtut=searchbst(root2,u);
                cout<<rtut<<endl;
                break;}
        }
 
        cout << "Continue? (Y/N): ";
        char st;
        cin >> st;
        yu = (st == 'Y' || st == 'y');
    }
}
