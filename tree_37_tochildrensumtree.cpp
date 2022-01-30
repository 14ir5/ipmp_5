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
void printInorder(node* Node)
{
    if (Node == NULL)
        return;
    printInorder(Node->left);
    cout<<" "<<Node->key;
    printInorder(Node->right);
}
void tosumtree(node *root)
{
    
    if(root == NULL)
    return;
    if(root->left==NULL&&root->right==NULL){
        root->key=0;
        return;
    }
    if(root->left==NULL){
        root->key=root->right->key;
        tosumtree(root->right);
        return;
    }
    
    if(root->right==NULL){
        root->key=root->left->key;
         tosumtree(root->left);
        return;
    }
    
    root->key=root->left->key+root->right->key;
    tosumtree(root->left);
    tosumtree(root->right);
    
}

int main()
{
    cout<<"enter root node";
    struct node *root=buildtree();
   
    tosumtree(root);
    printInorder(root);
    return 0;
}
