/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//sumodd and sum even levels
#include <iostream>

using namespace std;
struct node{
    int key;
    struct node*left,*right,*next;
    
};
int max(int a,int b){
    if(a>b)
    return a;
    return b;
}
int findheight(struct node *root){
    if(root==NULL)
    return 0;
    
    return (max(findheight(root->left),findheight(root->right))+1);
}
int sumodd=0,sumeven=0;
void level(node* x,int lvl,bool b);
void levelorder(struct node*root){
    int h=findheight(root);
    bool x=false;
    for(int i=1;i<=h;i++)
    {
    
        level(root,i,x);
        x=!x;
        
    }
    cout<<"sumodd="<<sumodd<<endl;
    cout<<"sumeven"<<sumeven<<endl;
}
void level(node* x,int lvl,bool b){
     
    if(x==NULL)
    return;
    if(lvl==1)
     if(b==false)
     sumodd+=x->key;
    else
    sumeven+=x->key;
    else if(lvl>1)
    {
        
        
           level(x->left,lvl-1,b);  
           level(x->right,lvl-1,b);
            
        
    }
   
}

struct node* buildtree(){
    struct node *root=(struct node*)malloc(sizeof(struct node));
    cout<<"(-1 to end tree)";
    cin>>root->key;
    root->next=NULL;
    if(root->key==-1){
        return NULL;
    }
    cout<<"enter left node key"<<endl;
    root->left=buildtree();
    int left=root->left==NULL?-1:root->left->key;
    if(root->left!=NULL)
    root->left->next=root;
    cout<<"enter ryt node key whose left key is "<<left;
    root->right=buildtree();
    if(root->right!=NULL)
    root->next=root->right;
    
    return root;
}


int main()
{
    struct node*root=buildtree();
    root->next=NULL;
    levelorder(root);
    return 0;
}
