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
int max(int a,int b){
    if(a>b)
    return a;
    return b;
}
int findheight(struct node *root){
    if(root==NULL)
    return 0;
    if(root->left==NULL&&root->right==NULL)
    return 0;
    return max(findheight(root->left),findheight(root->right))+1;
}
int getWidth(node* root, int level);
int getWidth(node* root, int level)
{
 
    if (root == NULL)
        return 0;
 
    if (level == 1)
        return 1;
 
    else if (level > 1)
        return getWidth(root->left, level - 1)
               + getWidth(root->right, level - 1);
}

int findmaxwidth(struct node * root){
    if(root==NULL)
    return 0;
    int maxwidth = 0;
    int width;
    int h = findheight(root);
   
    for(int i=1;i<=h;i++){
        width=getWidth(root,i);
        if(width>maxwidth)
        maxwidth=width;
    }
    return maxwidth;
    
}

int main()
{
    cout<<"enter root node";
    struct node *root=buildtree();
    int count=findmaxwidth(root);
    cout<<"Maxwidth="<<count;
    return 0;
}
