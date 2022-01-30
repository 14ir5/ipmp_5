/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//kth node in nth level in tree of 0's and 1's
#include <iostream>
#include<math.h>
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
string complement(string a){
    int n=a.length();
    for(int i=0;i<n;i++){
        if(a[i]=='1')
        a[i]='0';
        else
        a[i]='1';
    }
    return a;
}
string getLevel(int level)
{
    int n=pow(2,level);
    string upperlevel;
    if(level == 0)
    return "0";
    upperlevel = getLevel(level - 1);
    return upperlevel + complement(upperlevel);
}

int main()
{
    int n,k;
    cout<<"enter level number"<<endl;
    cin>>n;
    string nthlvl=getLevel(n);
    cout<<"Enter k to get kth element"<<endl;
    cin>>k;
    cout<<"level n elements="<<nthlvl<<endl;
    cout<<"element at position "<<k<<" is "<<nthlvl[k-1];
    return 0;
}
