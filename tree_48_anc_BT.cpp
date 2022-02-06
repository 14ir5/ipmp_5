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
bool printAncestors(struct node *root, int target)
{
 
  if (root == NULL)
     return false;
 
  if (root->key == target)
     return true;
 
  
  if ( printAncestors(root->left, target) || printAncestors(root->right, target) )
  {
    cout << root->key << " ";
    return true;
  }
 
  
  return false;
}


int main()
{
    int k;
    cout<<"enter root node:";
    struct node *root=buildtree();
    cout<<"enter key "<<endl;
    cin>>k;
   
    printAncestors(root,k);
    return 0;
}
