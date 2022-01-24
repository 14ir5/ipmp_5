/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Connect nodes at same level using constant extra space
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
void level(node* x,int lvl);
void levelorder(struct node*root){
    int h=findheight(root);
    for(int i=1;i<=h;i++)
    {
        level(root,i);
        
    }
    
}
void level(node* x,int lvl){
    if(x==NULL)
    return;
    if(lvl==1){
        if(x->next!=NULL)
        cout<<x->key<<"-->"<<x->next->key<<endl;
        else
        cout<<x->key<<"-->-1"<<endl;
        
    }
    
    else if(lvl>1)
    {
        level(x->left,lvl-1);  
        level(x->right,lvl-1);
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

node* getryt(node* y){
    node * temp=y->next;
    while(temp!=NULL){
        if(temp->left!=NULL)
        return temp->left;
        if(temp->right!=NULL)
        return temp->right;
        temp=temp->next;
    }
    return NULL;
}
void connectsamelvl(struct node*nd){
    if (!nd)
       return;
    if(nd->next!=NULL)
    connectsamelvl(nd->next);
    if(nd->left){
        if(nd->right){
            nd->left->next=nd->right;
            nd->right->next=getryt(nd);
        }
        else
        nd->left->next=getryt(nd);
        connectsamelvl(nd->left);
    }
    else if(nd->right){
        
        nd->right->next=getryt(nd);
        connectsamelvl(nd->right);
    }
    else
    connectsamelvl(getryt(nd));
}

int main()
{
    struct node*root=buildtree();
    root->next=NULL;
    connectsamelvl(root);
    levelorder(root);
    return 0;
}
