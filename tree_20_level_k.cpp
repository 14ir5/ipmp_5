/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//nodes at k distance
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
void nodes_k_dist(struct node *root,int k){
    if(root==NULL)
    return;
    if(k==0){
       cout<<root->key<<" "; 
       return;
    }
    
    nodes_k_dist(root->left,k-1);
    nodes_k_dist(root->right,k-1);
}
int main()
{
    cout<<"enter root node";
    struct node *root=buildtree();
    int k;
    cout<<"enter k"<<endl;
    cin>>k;
    nodes_k_dist(root,k);

    return 0;
}
