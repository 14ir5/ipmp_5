/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Leftview
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
void leftview(struct node *root,int level)
{
    static int maxlvl=0;
    
    if (root == NULL) return;
    if ( maxlvl < level )
    {
        cout << root->key << " ";
        maxlvl = level;
    }
    leftview(root->left, level + 1);
    leftview(root->right, level + 1);
     
}
int main()
{
    cout<<"enter root node";
    struct node *root=buildtree();
    leftview(root,1);

    return 0;
}
