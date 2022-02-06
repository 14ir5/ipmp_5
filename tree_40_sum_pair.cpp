/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//find a pair in BST whose sum is given number 
//using vector-2 meth-using find-using fwd and bkwd traversal
//using vector O(n) time and space complexity
//using 2 stacks O(n) time O(log n)
#include <bits/stdc++.h>

using namespace std;
struct node{
    int key;
    struct node *left,*right;
};
struct node* insert(struct node*root,int key){
    if(root==NULL){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->key=key;
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
        return root;
    }
    if(key<root->key){
        root->left=insert(root->left,key);
    }
    else{
        root->right=insert(root->right,key);
    }
    return root;
}
vector<int> v;
bool findpair(struct node* root,int sum){
    if(root==NULL)
    return false;
    
    if(v.empty()==false&&find(v.begin(),v.end(),sum-root->key)!=v.end())
    {
        cout<<"pair found - "<<root->key<<"&"<<sum-root->key<<endl;
        findpair(root->left,sum);
        findpair(root->right,sum);
        return true;
    }
    
    v.push_back(root->key);
    return(findpair(root->left,sum)||findpair(root->right,sum));
    
    
}
int main()
{
    int key,n;
    cout<<"enter root value"<<endl;
    cin>>key;
    struct node *root=NULL;
    root=insert(root,key);
    cout<<"enter no.of nodes"<<endl;
    cin>>n;
    cout<<"enter other nodes"<<endl;
    for(int i=0;i<n;i++){
        cout<<"enter data"<<endl;
        cin>>key;
        root=insert(root,key);
    }
    int sum;
    cout<<"enter sum"<<endl;
    cin>>sum;
    if(!findpair(root,sum))
    cout<<"pair not found"<<endl;
    return 0;
}
