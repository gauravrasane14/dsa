#include<iostream>
#include<cstring>
using namespace std;
class flight
{
  public:
  char city_index[10][10];
  int am[10][10];
  flight()
  {
    int i,j;
    for(i=0;i<10;i++)
    {
      strcpy(city_index[i],"x");
    }
    for(i=0;i<10;i++)
    {
      for(j=0;j<10;j++)
      {
        am[i][j]=0;
      }
    }
  }
  int create()
  {
    int city_count=0,si,di,wt,i,j;
    char s[10],d[10],c;
    do
    {
      cout<<"Enter Source City: ";
      cin>>s;
      cout<<"Enter Destination City: ";
      cin>>d;
      for(j=0;j<10;j++)
      {
        if(strcmp(city_index[j],s)==0)
        break;
      }
      if(j==10)
      {
        strcpy(city_index[city_count],s);
        city_count++;
      }
      for(j=0;j<10;j++)
      {
        if(strcmp(city_index[j],d)==0)
        break;
      }
      if(j==10)
      {
        strcpy(city_index[city_count],d);
        city_count++;
      }
      cout<<"Distance betn Source & Destination: ";
      cin>>wt;
      for(j=0;j<10;j++)
      {
        if(strcmp(city_index[j],s)==0)
        {
          si=j;
        }
        if(strcmp(city_index[j],d)==0)
        {
          di=j;
        }
      }
      am[si][di]=wt;
      cout<<"Do you want to Continue?(y/n): ";
      cin>>c;
    }
    while(c=='y'|| c=='Y');
    {
      return city_count;
    }
    
  }
  void display(int city_count)
  {
    int i,j;
    cout<<"\n\tDisplaying Adjacency Matrix: \n";
    for(i=0;i<city_count;i++)
    {
      cout<<"\t"<<city_index[i];
    }
    cout<<"\n";
    for(i=0;i<city_count;i++)
    {
      cout<<"\t"<<city_index[i];
      for(j=0;j<city_count;j++)
      {
        cout<<"\t"<<am[i][j];
      }
      cout<<"\n";
    }
  }
};
int main()
{
  int n,city_count;
  char c;
  flight f;
  do{
  cout<<"*****Flight Menu*****"<<endl;
  cout<<"1. Create"<<endl;
  cout<<"2. Adjacency matrix"<<endl;
  cout<<"3. Exit"<<endl;
  cout<<"Enter youe choice: ";
  cin>>n;
  
  switch(n)
  {
  case 1:
   city_count=f.create();
   break;
  case 2:
   f.display(city_count);
   break;
   
  case 3:
  return 0;
  }
}while(n<3);
return 0;
}