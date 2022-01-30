/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//binary to double tree
#include <iostream>
#include<math.h>
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

void dbltree(struct node *root)
{
    struct node* temp=(struct node *)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    struct node *old=NULL;
    if(root==NULL)
    return;
    dbltree(root->left);
    dbltree(root->right);
    old=root->left;
    temp->key=root->key;
    root->left=temp;
    root->left->left=old;
}
void preorder(struct node* root){
    if(root==NULL)
    return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    cout<<"enter root node";
    struct node *root=buildtree();
    dbltree(root);
    preorder(root);
    return 0;
}
