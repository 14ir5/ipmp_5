/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//kth smallest element in BST
//using inorder travesal and array
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
void inorder(node* root,int k)
{
    static int count=0;
    if(root==NULL)
    return;
    inorder(root->left,k);
    count++;
    if(count==k)
    cout<<root->key;
    inorder(root->right,k);
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
    int k;
    cout<<"enter k"<<endl;
    cin>>k;
    
    inorder(root,k);

    return 0;
}
