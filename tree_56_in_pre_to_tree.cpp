/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//serialization of tree - writing inorder traversal of a tree to a file
#include <iostream>
#include <cstring>
using namespace std;
struct node{
    char key;
    struct node*left,*right;
    
};

node* newnode(int key)
{
    node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}


void inorder(node *root)
{
    if (root)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
int index_inorder(char key,string in,int l,int h){
    
    for(int i=l;i<=h;i++){
        if(in[i]==key)
        return i;
    }
    return -1;
}
node* buildtree(string in,string pre,int l,int h){
    static int i=0;
    int k=in.length();
    if(i>k){
        return NULL;
    }
    
    node* root=newnode(pre[i]);
    i++;
    if(l==h)
    return root;
    int index=index_inorder(root->key,in,l,h);
    root->left=buildtree(in,pre,l,index-1);
    root->right=buildtree(in,pre,index+1,h);
    
    return root;
}
int main()
{
    int n=6;
    string in={"DBEAFC"};
    string pre={"ABDECF"};
    node *root=buildtree(in,pre,0,n-1);
   
     cout << "Inorder traversal of the constructed tree is \n";
    inorder(root);
    return 0;
}
