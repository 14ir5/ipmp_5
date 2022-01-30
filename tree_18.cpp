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
int cnt=0;
void trav(struct node* root){
    if(root==NULL)
    return;
    
    if(root->left==NULL&&root->right==NULL){
        cout<<root->key<<" ";
        cnt++;
    }
   
    else{
        trav(root->left);
        trav(root->right);
    }
    
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
    cout<<"enter root";
    struct node*root=buildtree();
    
    trav(root);
    cout<<endl;
    cout<<cnt;
    return 0;
}
