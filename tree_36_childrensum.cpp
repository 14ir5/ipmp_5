/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//check children sum prop
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
bool ischildrensum(node* root){
    if(root==NULL)
    return true;
    if(root->left==NULL&&root->right==NULL)
    return true;
    if(root->left&&root->right&&root->key==(root->left->key+root->right->key))
    return true;
    if((root->right&&root->key==root->right->key)||(root->left&&root->key==root->left->key))
    return true;
    return false;
}


int main()
{
    cout<<"enter root node";
    struct node *root=buildtree();
    
    if(ischildrensum(root))
    cout<<"children property obeyed";
    else
    cout<<"not obeyed";

    return 0;
}
