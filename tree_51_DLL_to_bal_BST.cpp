/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<iostream>
using namespace std;
struct Node {
     struct Node* prev;
    int data;
    struct Node* next;
};
struct Node* head,*p;
int n;
void build_DLL(){
   int k;
    cout<<"enter the no.of nodes"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
            cout<<"enter data"<<endl;
            cin>>k;
            struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); 
            newNode->data = k;  
            newNode->next = NULL;
            newNode->prev = NULL;
            if(head == NULL) {  
                head = newNode;  
                p= newNode;
            }  
            else { 
                p->next = newNode; 
                newNode->prev=p;
                p=newNode; 
            } 
    }
}
Node* build_BST(Node **head_ref, int nd)
{
    if (nd <= 0)
        return NULL;
 
    Node *left = build_BST(head_ref,nd/2);
    Node *root = *head_ref;
    root->prev = left;
    *head_ref = (*head_ref)->next;
    root->next = build_BST(head_ref,nd-nd/2-1);
    return root;
}
void inorder(Node*root){
    if(root==NULL)
    return;
    inorder(root->prev);
    cout<<root->data<<" ";
    inorder(root->next);
}
int main()
{
    cout<<"enter nodes in DLL in ascending order"<<endl;
  build_DLL();
  struct Node*root=build_BST(&head,n);  //prev -->left   //nxt-->right
  inorder(root);
  return 0;
}


