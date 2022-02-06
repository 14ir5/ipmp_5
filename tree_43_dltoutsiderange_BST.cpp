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
node* removeOutsideRange(node *root, int min, int max)
{
   
   if (root == NULL)
      return NULL;
 
  
   root->left =  removeOutsideRange(root->left, min, max);
   root->right =  removeOutsideRange(root->right, min, max);
 
   if (root->key < min)
   {
       node *rChild = root->right;
       delete root;
       return rChild;
   }
   
   if (root->key > max)
   {
       node *lChild = root->left;
       delete root;
       return lChild;
   }
   
   return root;
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
    root=removeOutsideRange(root, k1, k2);
    inorder(root);
    return 0;
}
