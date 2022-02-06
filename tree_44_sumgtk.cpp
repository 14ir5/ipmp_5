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
void printInorder(node* Node)
{
    if (Node == NULL)
        return;
    printInorder(Node->left);
    cout<<" "<<Node->key;
    printInorder(Node->right);
}
struct node* sumgtk(node* root,int sum){
    if(root==NULL)
    return NULL;
    root->left=sumgtk(root->left,sum-root->key);
    root->right=sumgtk(root->right,sum-root->key);
    if(root->left==NULL&&root->right==NULL&&(sum-root->key)>0)
    {
        free(root);
        return NULL;
    }
    return root;
}
int main()
{
    int k;
    cout<<"enter root node:";
    struct node *root=buildtree();
    cout<<"enter k"<<endl;
    cin>>k;
    root=sumgtk(root,k);
    printInorder(root);
    return 0;
}
