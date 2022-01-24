/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
struct node{
    int key;
    struct node*left,*right;
    
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

void preorder(struct node*root){
    if(root==NULL)
    return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node*root){
    if(root==NULL)
    return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";
}
void inorder(struct node* root){
    if(root==NULL)
    return;
    
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
    
}


int main()
{
    cout<<"enter root node";
    struct node *root=buildtree();
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}
