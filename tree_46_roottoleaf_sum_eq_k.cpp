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
void printArray(int ints[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        cout << ints[i] << " ";
    }
    cout<<endl;
}
void printPathsRecur(node* node, int path[], int pathLen,int k,int sum)
{
    if (node == NULL)
        return;
     
  
    path[pathLen] = node->key;
    sum=sum+node->key;
    pathLen++;
    
    if (node->left == NULL && node->right == NULL)
    {
        if(sum==k)
        printArray(path, pathLen);
    }
    else
    {
        printPathsRecur(node->left, path, pathLen,k,sum);
        printPathsRecur(node->right, path, pathLen,k,sum);
    }
}


int main()
{
    int k;
    cout<<"enter root node:";
    struct node *root=buildtree();
    cout<<"enter  "<<endl;
    cin>>k;
    int path[100];
    printPathsRecur(root, path, 0 ,k,0);
    return 0;
}
