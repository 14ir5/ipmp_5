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
struct node* ancestor=NULL;

void nodek(struct node* root,int k){
    
    if(root==NULL)
    return;
    if(root->key==k){
        ancestor=root;
        return;
    }
    
        nodek(root->left,k);
        nodek(root->right,k);
    
    
    
}
struct node* anc(struct node* root,struct node* n1,struct node* n2){
    if(root==NULL)
    return NULL;
    if (root->key > n1->key && root->key > n2->key)
        return anc(root->left, n1, n2);
 
    if (root->key < n1->key&& root->key < n2->key)
        return anc(root->right, n1, n2);
    
    return root;
}
int main()
{
    int key,n;
    int k1,k2;
    struct node *n1=NULL,*n2=NULL;
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
     cout<<"enter key1"<<endl;
    cin>>k1;
    nodek(root,k1);
    n1=ancestor;
    ancestor=NULL;
    cout<<"enter key2"<<endl;
    cin>>k2;
    nodek(root,k2);
    n2=ancestor;
    
    struct node * anctr=anc(root,n1,n2);
    cout<<"LCA="<<anctr->key;
    return 0;
}
