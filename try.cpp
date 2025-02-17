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
    if(a1==true&&a2==true&&a3==true){
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

void create_bst(node*& root, int val) {
    if (root == nullptr) {
        root = new node(val);
        return;
    }
    if (val < root->data){
        if(root->left==nullptr){
                node* p=new node(val);
                root->left=p;
                return;
        }
        create_bst(root->left,val);
    }
    else{
        if(root->right==nullptr){
                node* p1=new node(val);
                root->right=p1;
                return;
        }
        create_bst(root->right,val);
    }
}

int height(node* root) {
    if (root == nullptr){
        return 0;
    }
    int lt = height(root->left);
    int rt = height(root->right);
    return max(lt, rt) + 1;
}
node* cur;
void dele(node* root,int val){
    if(root==nullptr){
        return;
    }
    if(val<root->data){
        cur=root;
        dele(root->left,val);
    }
    else if (root->data<val){
        cur=root;
        dele(root->right,val);
    }
    else{
        if (root->left==nullptr&&root->right==nullptr){
            delete root;
        }
        else if(root->left==nullptr){
            node* temp=root->right;
            cur->right=temp;
            delete root;
        }
        else if(root->right==nullptr){
            node* temp=root->left;
            cur->left=temp;
            delete root;
        }
        else{
            node* temp2=root->right;
            while(temp2->left!=nullptr){
                temp2=temp2->left;
            }
            root->data=temp2->data;
            delete temp2;
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
                        11. Find height of tree\n\
                        12. Search in BST";
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
                cout << "Making a Clone: ";
                root2 = clone(root);
                break;
            case 6:
                {cout << "Check Equal: ";
                bool equalTrees = equal(root, root2);
                cout <<equalTrees<< endl;
                break;}
            case 7:
                {cout << "Creating a Mirror image\n";
                root2 = mirror(root);
                break;}
            case 8:
                {cout << "Creating a Binary Search Tree\n";
                cout << "Enter Number of Nodes: ";
                int v;
                cin >> v;
                for (int i = 0; i < v; i++) {
                    int r;
                    cout << "Enter Node " << i + 1 << " : ";
                    cin >> r;
                    create_bst(root2, r);
                }
                break;}
            case 9:
                {cout << "Enter value to be deleted: ";
                int gh;
                cin >> gh;
                dele(root2, gh);
                break;}
            case 10:
                break;
            case 11:
                {cout << "Calculating height of tree: ";
                int h1 = height(root);
                cout << "Height of tree is " << h1 << endl;
                break;}
            case 12:
                {cout << "Search in BST\n";
                int v1;
                cout << "Enter value to be searched: ";
                cin >> v1;
                bool ans = searchbst(root2, v1);
                if (ans == true) {
                    cout << "Element Found\n";
                } else {
                    cout << "Element absent\n";
                }
                break;}
        }

        cout<<"Continue ? : ";
        string st;
        cin>>st;
        if(st!="Y"||st!="y"){
            yu=false;
        }
    }
}
