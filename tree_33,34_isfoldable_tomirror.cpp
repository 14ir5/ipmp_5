/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//check if 
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
bool structure(struct node*n1,struct node* n2){
    if(n1==NULL&&n2==NULL)
    return true;
    
    if(n1!=NULL&&n2!=NULL&&structure(n1->left,n2->left)&&structure(n1->right,n2->right))
    return true;
    return false;
}
void mirror(struct node* x){
    if(x==NULL)
    return;
    
    mirror(x->left);
    mirror(x->right);
    struct node* temp=x->left;
    x->left=x->right;
    x->right=temp;
}
bool isfoldable(struct node* root){
    if(root==NULL)
    return true;
    mirror(root->right);
    
    bool res=structure(root->left,root->right);
    
    mirror(root->right);
    return res;
}

int main()
{
    cout<<"enter root node";
    struct node *root=buildtree();
    
    if(isfoldable(root))
    cout<<"it is a foldable tree";
    else
    cout<<"not foldable";

    return 0;
}
