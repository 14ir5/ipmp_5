/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//populate inorder successor
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
void inorder(struct node* root){
    if(root==NULL)
    return;
    
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
    
}

void ppltinsuc(struct node* x){
    static struct node*next=NULL;
    if(x){
        ppltinsuc(x->right);
        x->next=next;
        next=x;
        ppltinsuc(x->left);
    }
}
int main()
{
    cout<<"enter root node";
    struct node*root=buildtree();
    inorder(root);
    cout<<endl;
    ppltinsuc(root);
    node *ptr=root;
    while(ptr->left!=NULL){
        ptr=ptr->left;
    }
     
    while(ptr)
    {
        
        cout << "Next of " << ptr->key<< " is "
             << (ptr->next? ptr->next->key: -1)
             << endl;
        ptr = ptr->next;
    }
 
    return 0;
}
