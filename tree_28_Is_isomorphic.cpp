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
bool Isomorphic(node* n1, node *n2)
{
 if (n1 == NULL && n2 == NULL)
    return true;
 if (n1 == NULL || n2 == NULL)
    return false;
 if (n1->key != n2->key)
    return false;
 return ((Isomorphic(n1->left,n2->left) && Isomorphic(n1->right,n2->right))|| (Isomorphic(n1->left,n2->right) && Isomorphic(n1->right,n2->left)));
}
int main()
{
    cout<<"enter root node";
    struct node *root1=buildtree();
    cout<<"enter root node 2";
    struct node *root2=buildtree();
    if(Isomorphic(root1, root2))
    cout<<"Trees are isomorphic";
    else
    cout<<"not isomorphic"<<endl;
    
    return 0;
}
