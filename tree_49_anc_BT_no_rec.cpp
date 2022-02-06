/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
struct node{
    int key;
    struct node *left,*right;
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
void printanc_no_rec(node* root,int key){
    if(root==NULL)
    return;
    stack<node*> st;
    node* curr=root;
    while(1){
        while(curr!=NULL&&curr->key!=key)//all these left nodes are processed
        {
            st.push(curr);
            curr=curr->left;
        }
        if(curr&&curr->key==key)
        break;
        if(st.top()->right==NULL){
            curr=st.top();
            st.pop();
            while(st.empty()==false&&st.top()->right==curr){
                curr=st.top();
                st.pop();
            }
            
        }
       curr = st.empty()? NULL: st.top()->right;
    }
    while (!st.empty())
    {
        cout<<st.top()->key<<" ";
        st.pop();
    }
}
int main()
{
    int key;
    cout<<"enter root node:";
    struct node *root=buildtree();
    cout<<"enter key"<<endl;
    cin>>key;
    printanc_no_rec(root,key)  ;
    return 0;
}
