#include<iostream>
using namespace std;
class node
{
public:
int info;
struct node*left;
struct node *right;
}*root;
   
class bst
{
  public:
  node *root;
  void insert(node *,node*);
  int min(node *);
  int height(node *);
  void mirror(node *);
  void inorderdisplay(node *);
  void search(node *,int);
  bst()
  {
   root=NULL;
   }
};
  
  
  
void bst::insert(node *tree,node *newnode)
{
 if(root==NULL)
 {
  root=newnode;
  root->info=newnode->info;
  root->left=NULL;
  root->right=NULL;
  cout<<"root node is added"<<endl;
  return;
  }
   if(tree->info==newnode->info)
   {
   cout<<"element is already present in the tree"<<endl;
   return;
    }
      
      if(tree->info>newnode->info)
        {
          insert(tree->left,newnode);
         }
         else
         {
          insert(tree->right,newnode);
         }
       }
       
       int bst::min(node *root)
       {
        node *temp;
        if(root==NULL)	
        {
        cout<<"tree is empty";
        }
        else
        {
          temp=root;
          while(temp->left!=NULL)
           {
             temp=temp->left;
            }
            return(temp->info);
        } return 0;
       }
       
        int bst::height(node *root)
        {
         int htleft,htright;
         if(root==NULL)
         {
           cout<<"tree is empty"<<endl;
           return 0;
          }
          else if(root->left==NULL && root->right==NULL)
          {
            return 1;
           }
           htleft=height(root->left);
           htright=height(root->right);
           if(htright>=htleft)
           {
            return(htright+1);
            }
             else
             {
              return(htleft+1);
             }
           }    
           void bst::mirror(node *root)
           {
            node*temp;
            if(root!=NULL)
            {
            
             temp=root->left;
             root->left=root->right;
             root->right=temp;
             mirror(root->left);
             mirror(root->right);
            }
           }
           void bst::inorderdisplay(node *ptr)
           {
            if(ptr!=NULL)
             {
              inorderdisplay(ptr->left);
              cout<<ptr->info<<"/t";
              inorderdisplay(ptr->right);
              cout<<endl;
             }
            }
             void bst::search(node *ptr,int searchdata)
              {
               if(ptr->info==searchdata)
               {
                cout<<"element founf"<<endl;
               }
               else if(ptr->info<searchdata && ptr->right!=NULL)
               {
                 search(ptr->right,searchdata);
                }       
               else if(ptr->info<searchdata && ptr->left!=NULL)
               {
                 search(ptr->left,searchdata);
                }                 
               else
               { cout<<"element not found"<<endl;
               }
              }
        
        
        
        
        
        
        
        
        
         int main()
         {
          int choice,num;
          bst b1;
          node *temp;
          while(1)
          {
          cout<<"bst operation"<<endl;
          cout<<"1.INSERT ELEMENT"<<endl;
          cout<<"2.find min number"<<endl;
          cout<<"3.height of tree"<<endl;
          cout<<"4.mirror of tree"<<endl;
          cout<<"5.inorder display"<<endl;
          cout<<"6.search the element"<<endl;
          cout<<"enter your choice"<<endl;
          cin>>choice;
          switch(choice)
          {
           case 1:
           temp=new node();
           cout<<"enter the number to be inserted:";
           cin>>temp->info;
           b1.insert(b1.root,temp);
           break;
           case 2:
           b1.min(b1.root);
           cout<<"min value of tree"<<endl;
           cout<<temp->info<<endl;
           break;
           case 3:
           int h;
           h=b1.height(b1.root);
           cout<<"the height of tree:"<<h<<endl;
           case 4:
            b1.mirror(b1.root);
            b1.inorderdisplay(b1.root);
            break;
            case 5:
            cout<<"the inorder of the tree is:";
            b1.inorderdisplay(b1.root);
            cout<<endl;
            break;
            case 6:
            int searchdata;
            cout<<"enter the element to be search:";
            cin>>searchdata;
            b1.search(b1.root,searchdata);
            cout<<endl;
            break;
            case 7:
            exit(1);
            default:
            cout<<"wrong choice"<<endl;
             
           
           }
           }
          return 0;
         }