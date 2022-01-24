/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//sumodd and sum even levels
#include <iostream>

using namespace std;
struct node{
    int key;
    struct node*left,*right,*next;
    
};


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
int leaflvl=0;
bool check(node* root,int lvl);
bool check(node* root,int lvl){
    if(root==NULL)
    return true;
    
    if(root->left==NULL&&root->right==NULL){
        if(leaflvl==0){
            leaflvl=lvl;
            return true;
        }
        return (lvl == leaflvl); 
    }
    return check(root->left,lvl+1)&&check(root->right,lvl+1);
}

int main()
{
    struct node*root=buildtree();
    root->next=NULL;
    bool x=check(root,1);
    if(x)
    cout<<"same level";
    else
    cout<<"different levels";
    return 0;
}
