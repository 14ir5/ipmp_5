/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//boundary traversal of a tree
#include <iostream>

using namespace std;
struct node{
    int key;
    struct node*left,*right,*next;
    
};
void rtrav(struct node* root){
    if(root==NULL)
    return;
    
    if(root->right){
        rtrav(root->right);
        cout<<root->key<<" ";
        
    }
        
    else if(root->left){
         rtrav(root->left);
        cout<<root->key<<" ";
       
    }
        
    
    
}
void ltrav(struct node* root){
    if(root==NULL)
    return;
    if(root->left){
        cout<<root->key<<" ";
        ltrav(root->left);
    }
    else if(root->right){
        cout<<root->key<<" ";
        ltrav(root->right);
    }
    
   
}
void lvtrav(struct node* root){
    if(root==NULL)
    return;
    if(root->left==NULL&&root->right==NULL)
    cout<<root->key<<" ";
    lvtrav(root->left);
    lvtrav(root->right);
}
void btrav(struct node* root){
    if(root==NULL)
    return;
    cout<<root->key<<" ";
    ltrav(root->left);
    lvtrav(root);
    rtrav(root->right);
}
struct node* buildtree(){
    struct node *root=(struct node*)malloc(sizeof(struct node));
    cout<<"(-1 to end tree)";
    cin>>root->key;
    root->next=NULL;
    if(root->key==-1){
        return NULL;
    }
    cout<<"enter left node key"<<endl;
    root->left=buildtree();
    int left=root->left==NULL?-1:root->left->key;
    if(root->left!=NULL)
    root->left->next=root;
    cout<<"enter ryt node key whose left key is "<<left;
    root->right=buildtree();
    if(root->right!=NULL)
    root->next=root->right;
    
    return root;
}
int main()
{
    cout<<"Hello World";
    struct node*root=buildtree();
    
    btrav(root);
    return 0;
}
