#include<iostream>

using namespace std;

struct node
{
    int data;
    node* left_son;
    node* right_son;

};

node* getnew(int x)
{
    node* temp = new node;
    temp->data=x;
    temp->left_son=NULL;
    temp->right_son=NULL;
    return temp;
}

node* addnew(node* rootPtr,int x)
{

     if(rootPtr==NULL)
     {
      //   cout<<"\n init :";
          node* temp =getnew(x);
            rootPtr = temp;
     }
     else if(((rootPtr)->data)>(x))
     {
        rootPtr->left_son=addnew(rootPtr->left_son,x);
     }
     else if(((rootPtr)->data)<=(x))
     {
        rootPtr->right_son = addnew(rootPtr->right_son,x);
     }
     return rootPtr;
}
void printing(node* rootPtr)
{

    //cout<<"\n Came here :";
    if(rootPtr==NULL)
    {
        cout<<"\n Empty\n ";

    }
    else{
            //cout<<"\n came here too:";
    if((rootPtr->left_son==NULL)&&(rootPtr->right_son==NULL))
        cout<<rootPtr->data<<" ";
    if(rootPtr->left_son!=NULL)
        {
            //cout<<"\n cmae in:";
            node* temp=rootPtr->left_son;
            printing(temp);
            cout<<rootPtr->data<<" ";
        }
    if(rootPtr->right_son!=NULL)
        {
            node* temp=rootPtr->right_son;
            printing(temp);

        }

    }

}
int main()
{
    node* root=NULL;
    //printing(root);
    root = addnew(root,60);

    //printing(root);
    root = addnew(root,25);

   // printing(root);
    root = addnew(root,13);
    root = addnew(root,75);
    root = addnew(root,89);
    root = addnew(root,13);
    root = addnew(root,27);
    root = addnew(root,64);

    cout<<"\n All inserted :\n";
    printing(root);
    return 0;

}
