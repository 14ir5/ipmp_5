/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//every node has either 0 or 2 children. 
//tree from  inorder
#include <iostream>

using namespace std;
struct node {
    int key;
    node* left,*right;
};

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


struct node* buildtree(int pre[], char preLN[],int n)
{
    static int index = 0;
 
    if (index == n){
        
        return NULL;
    }
    int i=index;
    
     struct node *temp = newnode ( pre[index] );
      index++;
    if (preLN[i] == 'N')
    {
        cout<<index<<"hi";
      temp->left  = buildtree(pre,preLN,n);
      cout<<index<<"helo";
      
      temp->right = buildtree(pre,preLN,n);
    }
 
    return temp;
}

int main()
{
    int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int n = sizeof(pre)/sizeof(pre[0]);
 
    node* root=buildtree(pre,preLN,n);
    	cout << "Inorder traversal of the constructed tree is \n";
	printInorder(root);
    return 0;
}
