/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
struct node{
    int data;
    node*left=NULL,*right=NULL;
};
node* newnode(int k){
    node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=k;
    return newnode;
}
node* arr_to_bal_BST(int a[],int s,int e){
    if(s>e)
    return NULL;
    int mid=(s+e)/2;
    node* root=newnode(a[mid]);
    root->left=arr_to_bal_BST(a,s,mid-1);
    root->right=arr_to_bal_BST(a,mid+1,e);
    return root;
}

void inorder(node* root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    int a[]={1,2,3,4,5,6};
    int n=sizeof(a)/sizeof(a[0]);
    node* root=arr_to_bal_BST(a,0,n-1);
    inorder(root);
    return 0;
}
