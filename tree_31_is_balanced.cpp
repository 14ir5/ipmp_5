/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//is bst
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
int sum(struct node* root){
    if(root==NULL)
    return 0;
    
    return sum(root->left)+root->key+sum(root->right);
}
int height(struct node* root){
    if (root == NULL)
        return 0;
 
    
    return 1 + max(height(root->left),
                   height(root->right));
}
int max(int a,int b){
    if(a>b)
    return a;
    else
    return b;
}
bool isbalanced(struct node *root)
{
    if(root==NULL)
    return true;
    int lh = height(root->left);
    int rh = height(root->right);
 
    if (abs(lh - rh) <= 1 && isbalanced(root->left) && isbalanced(root->right))
        return true;
 
    
    return false;
}
int main()
{
    cout<<"enter root node";
    struct node *root=buildtree();
    
    if(isbalanced(root))
    cout<<"it is a Balanced tree";
    else
    cout<<"not balanced";
    return 0;
}
