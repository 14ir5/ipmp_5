 /******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
struct node{
    int key;
    struct node *left,*right;
};
struct node* insert(struct node*root,int key){
    if(root==NULL){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->key=key;
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
        return root;
    }
    if(key<root->key){
        root->left=insert(root->left,key);
    }
    else{
        root->right=insert(root->right,key);
    }
    return root;
}
void sumgre(struct node* root){
    static int sum=0;
    if(root==NULL){
       
        return;
    }
    sumgre(root->right);
    sum=sum+root->key;
    root->key=sum;
    sumgre(root->left);
}
void inorder(struct node *root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}
struct node* minValue(struct node* node)
{
    struct node* current = node;
 
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
struct node* in_suc(struct node* root,struct node* n)
{
    if (n->right != NULL)
        return minValue(n->right);
    struct node* succ = NULL;
    while (root != NULL)
    {
        if (n->key < root->key)
        {
            succ = root;
            root = root->left;
        }
        else if (n->key > root->key)
            root = root->right;
        else
            break;
    }
 
    return succ;
}
struct node *x=NULL;
void nodek(struct node* root,int k){
    
    if(root==NULL)
    return;
    if(root->key==k){
        x=root;
        return;
    }
    
        nodek(root->left,k);
        nodek(root->right,k);
    
    
    
}
int main()
{
    int key,k,n;
    cout<<"enter root value"<<endl;
    cin>>key;
    struct node *root=NULL;
    root=insert(root,key);
    cout<<"enter no.of nodes"<<endl;
    cin>>n;
    cout<<"enter other nodes"<<endl;
    for(int i=0;i<n;i++){
        cout<<"enter data"<<endl;
        cin>>key;
        root=insert(root,key);
    }
    cout<<"enter key to find inorder successor"<<endl;
    cin>>k;
    nodek(root,k);
    struct node* nd=x;
    inorder(root);
    cout<<endl;
    struct node *succ=in_suc(root,nd);
    cout<<succ->key;
    return 0;
}
