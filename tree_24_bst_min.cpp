/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
struct node{
    int key;
    struct node *left,*right;
};
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
void findmin(struct node* root){
    if(root->left==NULL){
        cout<<"min value="<<root->key;
        return;
    }
    findmin(root->left);
}
int main()
{
    int key,n;
    cout<<"enter root value"<<endl;
    cin>>key;
    struct node *root=NULL;
    root=insert(root,key);
    cout<<"enter no.of nodes"<<endl;
    cin>>n;
    cout<<"enter other nodes"<<endl;
    for(int i=0;i<n;i++){
        cout<<"enter data"<<endl;
        cin>>key;
        root=insert(root,key);
    }
    findmin(root);
    return 0;
}
