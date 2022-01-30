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

int countNodes(struct node* root)
{
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}
int isComplete (struct node* root, int index,
                 int number_nodes)
{
   
    if (root == NULL)
        return (1);
 
    
    if (index >= number_nodes)
        return (0);
 
    
    return (isComplete(root->left, 2*index + 1, number_nodes) &&
            isComplete(root->right, 2*index + 2, number_nodes));
}

int main()
{
    cout<<"enter root node";
    struct node *root=buildtree();
    int node_count = countNodes(root);
    int index = 0;
    if(isComplete(root,index,node_count))
    cout<<"it is a complete tree";
    else
    cout<<"not complete";
    return 0;
}
