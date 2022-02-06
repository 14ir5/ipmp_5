/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<iostream>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
struct node{
    int data;
    node*left=NULL,*right=NULL;
};
struct Node* head,*p;
int n;
void build_LL(){
   int k;
    cout<<"enter the no.of nodes"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
            cout<<"enter data"<<endl;
            cin>>k;
            struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); 
            newNode->data = k;  
            newNode->next = NULL;
                
            if(head == NULL) {  
                head = newNode;  
                p= newNode;
            }  
             else { 
                p->next = newNode; 
                p=newNode; 
            } 
                         
    }
}
node* newnode(int k){
    node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=k;
    return newnode;
}
node* build_BST(Node **head_ref, int nd)
{
    if (nd <= 0)
        return NULL;
 
    node *left = build_BST(head_ref,nd/2);
    node *root = newnode((*head_ref)->data);
    root->left = left;
    *head_ref = (*head_ref)->next;
    root->right= build_BST(head_ref,nd-nd/2-1);
    return root;
}
void inorder(node*root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    cout<<"enter nodes in LinkedList in ascending order"<<endl;
  build_LL();
  struct node*root=build_BST(&head,n);  //prev -->left   //nxt-->right
  inorder(root);
  return 0;
}


