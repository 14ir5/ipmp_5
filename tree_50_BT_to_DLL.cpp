/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
struct node{
    int key;
    struct node *left,*right;
};

struct node* buildtree(){
    struct node *root=(struct node*)malloc(sizeof(struct node));
    cout<<"(-1 to end tree)";
    cin>>root->key;
    if(root->key==-1){
        return NULL;
    }
    cout<<"enter left node key"<<endl;
        root->left=buildtree();
    int left=root->left==NULL?-1:root->left->key;
    cout<<"enter ryt node key whose left key is "<<left;
    root->right=buildtree();
    
    
    return root;
}
struct node* insert(struct node*root,int key){
    if(root==NULL){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->key=key;
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
        return root;
    }
    if(key<root->key){
        root->left=insert(root->left,key);
    }
    else{
        root->right=insert(root->right,key);
    }
    return root;
}

struct node *head=NULL;

node* BT_To_DLL(node *root){
    static struct node *prev=NULL;
    if(root==NULL)
    return NULL;
    BT_To_DLL(root->left);
    if(head==NULL)
    {
        head=root;
    }
    root->left=prev;
    if(prev!=NULL)
    prev->right=root;
    prev=root;
    BT_To_DLL(root->right);
    return root;
}
void printList(node* node)
{
    while (node != NULL) {
        cout << node->key << " ";
        node = node->right;
    }
}
int main()
{
    int k;
    cout<<"enter root node:";
    struct node *root=buildtree();
    BT_To_DLL(root);
    printList(head);
    return 0;
}
