#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
        node(){
                    left=nullptr;
                    right=nullptr;
                    data=0;
            }
        node(int d){
            data=d;
            left=nullptr;
            right=nullptr;
        }
};

void insert(node* root,int val){
    node* p=new node(val);

    if(root==nullptr) 
        root=p;
    else {
        node* temp=root;
        while(true) {
            cout<<"1.For Left Insert of "<<temp->data<<endl;
            cout<<"2.For Right Insert of "<<temp->data<<endl;
            int c;
            cout<<"Enter your choice: ";
            cin>>c;

            if(c==1) {
                if(temp->left==nullptr){
                    temp->left=p;
                    break;
                } 
                else
                temp=temp->left;
            } 
            else if(c==2){
                if(temp->right==nullptr){
                    temp->right=p;
                    break;
                } 
                else{
                    temp=temp->right;
                }
            } 
            else{
                cout<<"Invalid choice! Please choose either 1 or 2."<<endl;
            }
        }
    }
}
void inorder(node* root) {
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void postorder(node* root){
    if(root!=nullptr){
        inorder(root->left);
        inorder(root->right);
        cout<<root->data<<" ";
    }
}
// void preorder(node* root){

// }


int main(){
    node* root=nullptr;
    int n;
    cout<<"Enter the number of nodes to insert: ";
    cin>>n;
    while(true){
        const char *str="          Menu\n\
                    1.  Create Binary Tree\n\
                    2.  Preorder (Recursive & Non-Recursive)\n\
                    3.  Postorder (Recursive & Non-Recursive)\n\
                    4.  Inorder (Recursive & Non-Recursive)\n\
                    5.  Level Order\n\
                    6.  Make a clone\n\
                    7.  Check if two trees are equal\n\
                    8.  Create mirror image\n\
                    9.  Create Binary Search Tree\n\
                    10. Delete node from BST\n\
                    11. Construct BST from preorder & postorder\n\
                    12. Find height of tree";
        int ch;
        cout<<str;
        cout<<"\nEnter your choice : ";
        cin>>ch;
    }
}