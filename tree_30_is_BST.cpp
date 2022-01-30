/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//is bst
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
int sum(struct node* root){
    if(root==NULL)
    return 0;
    
    return sum(root->left)+root->key+sum(root->right);
}
bool isbst(struct node *root)
{
     if(root==NULL)
     return true;
     if(root->left!=NULL&&root->left->key>root->key)
     return false;
     if(root->right!=NULL&&root->right->key<root->key)
     return false;
     return isbst(root->left)&&isbst(root->right);
}
int main()
{
    cout<<"enter root node";
    struct node *root=buildtree();
    
    if(isbst(root))
    cout<<"it is a BST";
    else
    cout<<"not a BST";
    return 0;
}
