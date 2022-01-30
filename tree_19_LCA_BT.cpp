/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//lowest ancestor in a tree

#include <bits/stdc++.h>

using namespace std;
//storing in vector
struct node
{
	node *left, *right, *parent;
	int key;
};
struct node* anc(struct node* root,struct node* n1,struct node*n2){
    
    vector <struct node*> n1anc;
    while(n1!=NULL){
        n1anc.push_back(n1);
        n1=n1->parent;
    }
    while(n2!=NULL){
        if(find(n1anc.begin(),n1anc.end(),n2)!=n1anc.end())
        return n2;
        n2=n2->parent;
    }
    return NULL;
}
struct  node* buildtree(){
    struct node *root=(struct node*)malloc(sizeof(struct node));
    cout<<"(-1 to end tree)";
    cin>>root->key;
    
    if(root->key==-1){
        return NULL;
    }
    cout<<"enter left node key"<<endl;
    root->left=buildtree();
    if(root->left!=NULL)
    root->left->parent=root;
    cout<<"enter ryt node key whose left key is "<<root->left;
    root->right=buildtree();
    if(root->right!=NULL)
    root->right->parent=root;
    
   
    return root;
}
struct node* ancestor=NULL;

void nodek(struct node* root,int k){
    
    if(root==NULL)
    return;
    if(root->key==k){
        ancestor=root;
        return;
    }
    
        nodek(root->left,k);
        nodek(root->right,k);
    
    
    
}
int main()
{
    int k1,k2;
    struct node *n1=NULL,*n2=NULL;
    struct node * root=buildtree();
    root->parent=NULL;
    cout<<"enter key1"<<endl;
    cin>>k1;
    nodek(root,k1);
    n1=ancestor;
    ancestor=NULL;
    cout<<"enter key2"<<endl;
    cin>>k2;
    nodek(root,k2);
    n2=ancestor;
    
    struct node * anctr=anc(root,n1,n2);
    cout<<"LCA="<<anctr->key;
    return 0;
}
