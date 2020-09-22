#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
   int data;
   struct node *left,*right;
};

struct node *create()
{
    return((struct node *)malloc(sizeof(struct node)));
};

struct node *tree_basic()
{
    int x;
    struct node *temp;
    temp=create();
    cout<<"\nEnter the data (Enter -1 for NO NODE ) :: ";
    cin>>x;
    if(x==-1)
        return(NULL);
    else
    {
        temp->data=x;
        cout<<"Enter the LEFT CHILD of :: "<<x;
        temp->left=tree_basic();
        cout<<"Enter the RIGHT CHILD of :: "<<x;
        temp->right=tree_basic();
        return(temp);
    }
}

void preorder_display(struct node *root)
{
    if(root==NULL)
        return;
    else
    {
        cout<<root->data<<" ";
        preorder_display(root->left);
        preorder_display(root->right);
    }
}

int main()
{
    struct node *root=NULL;
    root=tree_basic();

    cout<<endl<<"--------     PREORDER  TRAVERSAL OF TREE     ----------"<<endl;
    preorder_display(root);

    return(0);

}
