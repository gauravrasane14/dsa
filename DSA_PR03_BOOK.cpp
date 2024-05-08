#include<iostream>
using namespace std;
struct node
{
    char label[30];
    int ch_count;
    struct node *child[20];
}*root;
class book
{
    public:
    book()
    {
        root=NULL;
    }
    
    void create_tree()
    {
        int tbook,tchapters,i,j,k;
        root=new node();
        cout<<"Enter name of the book: ";
        cin>>root->label;
        cout<<"Enter no of chapters in book: ";
        cin>>tchapters;
        root->ch_count=tchapters;
        for(i=0;i<tchapters;i++)
        {
            root->child[i]=new node();
            cout<<"Enter name of the chapter: ";
            cin>>root->child[i]->label;
            cout<<"Enter no of sections in chapter "<<root->child[i]->label<<"=";
            cin>>root->child[i]->ch_count;
            for(j=0;j<root->child[i]->ch_count;j++)
            {
                root->child[i]->child[j]=new node();
                cout<<"Enter section "<<j+1<<" name\n";
                cin>>root->child[i]->child[j]->label;
                cout<<"Enter no of subsections in "<<root->child[i]->child[j]->label<<"=";
                cin>>root->child[i]->child[j]->ch_count;
                for(k=0;k<root->child[i]->child[j]->ch_count;k++)
                {
                    root->child[i]->child[j]->child[k]=new node();
                    cout<<"Enter subsection "<<k+1<<" name\n";
                    cin>>root->child[i]->child[j]->child[k]->label;
                }
            }
        }
    }
    
    void display(node *r1)
    {
        int i,j,k,tchapters;
        if(r1!=NULL)
        {
            cout<<"\nBook Hierarchy"<<endl;
            tchapters=r1->ch_count;
            cout<<"Book name: "<<root->label;
            cout<<"\nChapters: "<<endl;
            for(i=0;i<tchapters;i++)
            {
                cout<<"\nChapter "<<i+1<<endl;
                cout<<"\t"<<r1->child[i]->label;
                cout<<"\t\t"<<"\nSections ="<<endl;
                for(j=0;j<r1->child[i]->ch_count;j++)
                {
                    cout<<"\t\t"<<r1->child[i]->child[j]->label;
                    cout<<"\t\t"<<"\nSubSections = "<<endl;
                    for(k=0;k<r1->child[i]->child[j]->ch_count;k++)
                    {
                        cout<<"\t\t"<<r1->child[i]->child[j]->child[k]->label;
                    }
                }
            }
        }
    }
};

int main()
{
    book tb;
    int ch;
    while(1)
    {
        cout<<"\n*****Book Management*****\n1. Create\n2. Display\n3. Exit\nEnter Your Choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                tb.create_tree();
                break;
            case 2:
                tb.display(root);
                break;
            case 3:
                exit(0);
        }
    }
    return 0;
}