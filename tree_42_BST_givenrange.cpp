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
void Print(node *root, int k1, int k2)
{
    if ( NULL == root )
        return;
    
    if ( k1 < root->key )
        Print(root->left, k1, k2);
     
   
    if ( k1 <= root->key && k2 >= root->key )
        cout<<root->key<<" ";
     
  
   Print(root->right, k1, k2);
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
    int k1,k2;
    cout<<"enter k1(min)"<<endl;
    cin>>k1;
    cout<<"enter k2(max)"<<endl;
    cin>>k2;
    Print(root, k1, k2);
    return 0;
}
