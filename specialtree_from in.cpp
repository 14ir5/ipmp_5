/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//every node is greater than keys in left and right children
//tree from  inorder
#include <iostream>

using namespace std;
struct node {
    int key;
    node* left,*right;
};
int findmax(int a[],int l,int h){
    int index=0;
    for(int i=l;i<=h;i++){
        if(a[i]>a[index]){
            index=i;
        }
    }
    return index;
}
node* newnode (int data)
{
	node* Node = (struct node*)malloc(sizeof(struct node));
	Node->key = data;
	Node->left = NULL;
	Node->right = NULL;

	return Node;
}


void printInorder (node* node)
{
	if (node == NULL)
		return;

	
	printInorder (node->left);
	cout<<node->key<<" ";
	printInorder (node->right);
}

node* buildtree(int a[],int l,int h){
    if(l>h)
    return NULL;
    int index=findmax(a,l,h);
    node *root=newnode(a[index]);
    
    if(l==h)
    return root;
    
    root->left=buildtree(a,l,index-1);
    root->right=buildtree(a,index+1,h);
    return root;
    
    
}


int main()
{
    int a[]={1, 5, 10, 40, 30, 15, 28, 20};
    int n=8;
    node* root=buildtree(a,0,n-1);
    	cout << "Inorder traversal of the constructed tree is \n";
	printInorder(root);
    return 0;
}
