#include<iostream>
using namespace std;
class Heap
{
int n;
int *minheap,*maxheap;
public:
void get();
void displayMin()
{
cout<<"Minimum marks :"<<minheap[0]<<endl;
}
void displayMax()
{
cout<<"Maximum marks:"<<maxheap[0]<<endl;
}
void upAdjust(bool,int);
};
void Heap::get()
{
cout<<"Enter number of students:"<<endl;
cin>>n;

int k;
minheap=new int[n];
maxheap=new int[n];
cout<<"Enter marks of student:"<<endl;
for(int i;i<n;i++)
{
cin>>k;
minheap[i]=k;
upAdjust(0,i);
maxheap[i]=k;
upAdjust(1,i);
}
}
void Heap::upAdjust(bool m,int l)
{
int s;
if (!m)
{
while(minheap[(l-1)/2]>minheap[l])
{
s=minheap[l];
minheap[l]=minheap[(l-1)/2];
minheap[(l-1)/2]=s;
l=(l-1)/2;
if(l==-1)
break;
}
}
else
{
while(maxheap[(l-1)/2]<maxheap[l])
{
s=maxheap[l];
maxheap[l]=maxheap[(l-1)/2];
maxheap[(l-1)/2]=s;
l=(l-1)/2;
if(l==-1)
break;
}
}
}
int main()
{
Heap h;

h.get();
h.displayMin();
h.displayMax();
return 0;
}
