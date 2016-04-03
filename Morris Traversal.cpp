#include<iostream>
#include<stdlib.h>

using namespace std;

/*Structure of the nodes required for the tree*/
struct node{
    int data;
    struct node* left;
    struct node* right;
};

/*Helper Function to allocate space
 and define initial values of the pointer*/
struct node* newnode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data =data;
    newNode->left=NULL;
    newNode->right=NULL;
};

void Morris(struct node* root)
{
    struct node *current,*pre;
    current =root;

    while(current != NULL)
    {
        if(current->left!=NULL)
        {
            pre=current->left;
            while(pre->right != NULL && pre->right != current)
                pre =pre->right;

            if(pre->right == current)
            {
                pre->right = NULL;
                cout<<current->data<<"\n";
                current = current->right;
            }
            else{
                pre->right = current;
                current = current->left;
            }
        }
        else{
            cout<<current->data<<"\n";
            current = current->right;

        }
    }
}

/* Driver function to check the Morris Traversal */
int main()
{
    struct node* root;
 //Testcase 1
  root = newnode(10);
    root->left = newnode(5);
    root->left->left = newnode(-2);
    root->left->left->right = newnode(2);
    root->left->left->right->left = newnode(-1);
    root->left->right = newnode(6);
    root->left->right->right = newnode(8);
    root->right = newnode(40);
    root->right->right = newnode(30);
    /*

    Testcase 2
    root =newnode(1);
    root->left        = newnode(2);
  root->right       = newnode(3);
  root->right->right= newnode(12);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);*/

    cout<<"\n The morris traversal is as follows \n\n";
    Morris(root);

}
