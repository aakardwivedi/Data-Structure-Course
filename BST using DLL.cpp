#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;


/*Structure of the nodes required for the tree*/
struct node
{
    int data;
    node* left_son;
    node* right_son;
    int countr;

};


/*Helper Function to allocate space
 and define initial values of the pointer*/
node* getnew(int x)
{
    node* temp = new node;
    temp->data=x;
    temp->left_son=NULL;
    temp->right_son=NULL;
    temp->countr = 1;
    return temp;
}

/*function to find the exact place of the new data to be inserted
and inserting it by creating a new node.
This function uses recursion */
node* addnew(node* rootPtr,int x)
{
        //If the root is empty
     if(rootPtr==NULL)
     {

          node* temp =getnew(x);
            rootPtr = temp;
     }
     else if(((rootPtr)->data)>(x))  //When the new data is less than the original one
     {
        rootPtr->left_son=addnew(rootPtr->left_son,x);  //setting the left child of the original root as the new root
     }
     else if(((rootPtr)->data)<(x))//When the new data is equal to or greater than the original one

     {
        rootPtr->right_son = addnew(rootPtr->right_son,x);//setting the left child of the original root as the ne
     }
     else if((rootPtr->data)==(x))
     {
         rootPtr->countr++;
     }
     return rootPtr;  //Finally returning the root pointer
}

/*Function to print the BST in-order */
void printing(node* rootPtr)
{

   if(rootPtr!=NULL){

        printing(rootPtr->left_son);
        cout<<rootPtr->data<<" "<<rootPtr->countr<<"\n";
        printing(rootPtr->right_son);

    }

}

/*Function that returns the inorder successor of the node to be deleted*/
node* minVal(node* rootPtr)
{
    //Leftmost element
    while(rootPtr->left_son != NULL)
        rootPtr = rootPtr->left_son;

    return rootPtr;
}

/*Fucntion that deletes the node accessed by the data of node*/
struct node* deleteNode(node* rootPtr,int x)
{
    if(rootPtr == NULL)
        return rootPtr;
    if(rootPtr->data < x)
    {
        rootPtr->right_son=deleteNode(rootPtr->right_son,x);
    }
    else if(rootPtr->data > x)
    {
        rootPtr->left_son=deleteNode(rootPtr->left_son,x);
    }
    else
    {
        if(rootPtr->left_son == NULL)
        {
            node* temp = rootPtr->right_son;
            free(rootPtr);
            return temp;
        }
        else if(rootPtr->right_son == NULL)
        {
            node* temp = rootPtr->left_son;
            free(rootPtr);
            return temp;
        }
        else{
                //Part to delete the node with two child
            node* temp = minVal(rootPtr->right_son);
            rootPtr->data = temp->data;
            rootPtr->right_son = deleteNode(rootPtr->right_son,temp->data);
        }
    }

}

/*DRIVER FUNCTION TO CHECK THE PROGRAM*/
int main()
{
    node* root=NULL;
    root = addnew(root,60);
    root = addnew(root,25);
    root = addnew(root,11);
    root = addnew(root,75);
    root = addnew(root,89);
    root = addnew(root,14);
    root = addnew(root,27);
    root = addnew(root,64);

    root = deleteNode(root,60);

    cout<<"\n All inserted :\n";
    printing(root);
    return 0;

}
