#include<iostream>

using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;

};
struct node* head=NULL;     ////Declaration of the tail pointer
struct node* tail=NULL;  ////Declaration of the tail pointer
struct node* Createnewnode(int x)
{
 struct node* temp = new node;
 temp->data=x;
 temp->prev =NULL;
 temp->next = NULL;
 return temp;
}


/* Function to insert an element at the beggining of linklist*/
void InsertatHead(int x)
{
    struct node* newnode = Createnewnode(x);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
       head->prev=newnode;
       newnode->next = head;
       head= newnode;
    }

}

/* Function to insert an element at the end of linklist*/
void InsertatTail(int x)
{
     struct node* newnode = Createnewnode(x);
     if(head==NULL)
     {
         head=newnode;
         tail=newnode;

     }
     else
     {
         struct node* temp = tail;
         tail->next=newnode;
         newnode->prev=tail;
         tail=tail->next;
     }
}

/* Function to print the linklist */
void printll()
{
    struct node* temp;
    temp = head;
 do
 {
     cout<<temp->data<<"  ";
     temp=temp->next;
 }while(temp->next!=NULL);
 cout<<temp->data;
}

/* Function to print the reversed linklist */
void ReversePrint()
{
    struct node* temp;
    temp = head;
    if(temp->prev==NULL)
        cout<<"\n Reversed:";
 do
 {

     temp=temp->next;
 }while(temp->next!=NULL);

    while(temp->prev!=NULL)
    {
        cout<<temp->data<<"   ";
        temp=temp->prev;
    }
    cout<<temp->data;
}
int main()
{

    int x;
    for(int i=0;i<10;i++)
    {
    cin>>x;
    InsertatHead(x);
    }
for(int i=0;i<10;i++)
    {
    cin>>x;
    InsertatTail(x);
    }
    printll();
    cout<<"\n\n";
    ReversePrint();
    return 0;


}
