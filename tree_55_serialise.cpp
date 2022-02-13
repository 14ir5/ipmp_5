/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//serialization of tree - writing inorder traversal of a tree to a file
#include <iostream>
#include <fstream>
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
void serialize(node *root, ofstream& fp)
{
   
    if (root == NULL)
    {
        //fprintf(fp, "%d ", -1);
        fp<<-1<<" ";
        return;
    }
 
    fp<<root->key<<" ";
   // fprintf(fp, "%d ", root->key);
    serialize(root->left, fp);
    serialize(root->right, fp);
}
node* newNode(int key)
{
    node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}
void deSerialize(node*&root, ifstream &fp)
{
    
    int val;
    fp>>val;
    if ( /*!fscanf(fp, "%d ", &val)*/ fp.eof()|| val == -1)
       return;
 
   
    root = newNode(val);
    deSerialize(root->left, fp);
    deSerialize(root->right, fp);
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
 
int main()
{
    cout<<"enter root node:";
    struct node *root=buildtree();
    ofstream fout;

    fout.open("sample");
    /*ofstream *fp = fopen("tree.txt", "w");   
    if (fp == NULL)
    {
        puts("Could not open file");
        return 0;
    }*/
    serialize(root, fout);
    fout.close();
    
    node *root1 = NULL;
    ifstream fin;
    fin.open("sample");
    deSerialize(root1, fin);
   /* 
    fp = fopen("tree.txt", "r");
    deSerialize(root1, fp);*/
 
   cout<<"Inorder Traversal of the tree constructed from file:"<<endl;
    inorder(root1);
    
    return 0;
}
