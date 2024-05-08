#include<iostream>
using namespace std;
#define TABLE_SIZE 10
struct node
{
    int data;
    string value1;
    struct node *next;
};
struct node *head[TABLE_SIZE]={NULL},*c;
void insert()
{
    int i,key;
    string value;
    cout<<"Enter Key Element: ";
    cin>>key;
    cout<<"Enter Value: ";
    cin>>value;
    i=key%TABLE_SIZE;
    struct node *newnode=(struct node*)new node();
    newnode->data=key;
    newnode->value1=value;
    newnode->next=NULL;
    if (head[i]==NULL)
        head[i]=newnode;
    else
    {
        c=head[i];
        while(c->next!=NULL)
        {
            c=c->next;
            c->next=newnode;
        }
        c->next=newnode;
    }
}

void search()
{
    int key,index;
    string value;
    cout<<"Enter Element to Search: ";
    cin>>key;
    index=key%TABLE_SIZE;
    if (head[index]==NULL)
        cout<<"Element NOT Found";
    else
    {
        for(c=head[index];c!=NULL;c=c->next)
        {
            if(c->data==key)
            {
                cout<<"Element found"<<"("<<c->data<<","<<c->value1<<")"<<endl;
                cout<<"\n";
                break;
            }
        }
    }
    if (c==NULL)
        cout<<"Element not found";
}

void display()
{
    int i;
    string value;
    for(i=0;i<TABLE_SIZE;i++)
    {
        cout<<"Entries at index "<<i;
        if (head[i]==NULL)
            cout<<"\t"<<"No hash entry"<<endl;
        else
        {
            for(c=head[i];c!=NULL;c=c->next)
            cout<<"\t"<<"("<<c->data<<","<<c->value1<<")"<<endl;
        }
    }
}

void deletekey()
{
    int key,index;
    cout<<"Enter key to be deleted ";
    cin>>key;
    index=key%TABLE_SIZE;
    c=head[index];
    if(c==NULL)
        cout<<"Element not found";
    if(c->data==key)
        head[index]=c->next;
    while((c->next)->data!=key)
    {
        c=c->next;
    }
    c->next=(c->next)->next;
}

int main()
{
    int key,ch,i;
    do
    {
        cout<<"\n 1.Insert \n 2.Display \n 3.Search \n 4.Delete \n 5.Exit \n Enter your choice ";
        cin>>ch;
        cout<<"\n";
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                deletekey();
                break;
            case 5:
                exit(0);
            default :
                cout<<"Enter valid choice";
        }
    }while(ch<5);
    return 0;
}