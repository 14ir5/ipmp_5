/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
int findsize(struct node* root){
    if(root==NULL)
    return 0;
    return findsize(root->left)+findsize(root->right)+1;
}
int main()
{
    cout<<"enter root node";
    struct node *root=buildtree();
    int count=findsize(root);
    cout<<"no.of nodes="<<count;
    return 0;
}
