#include<iostream>
#include <fstream>
#include <string.h>
using namespace std ;

class Student
{
public:
struct stud
{
int roll_no;
char name[10] ;
char addr[20];
};
stud st;
void create();
void deletee();
int search();
void display();
};
void Student:: create()
{
char y;
ofstream out;
out.open("Student.txt" ,ios::out);
do
{
cout<<"Enter Roll No.:";
cin>>st.roll_no;
cout<<"Enter Name of the student :\t";
cin>>st.name;
cout<<"Enter your address:";
cin>>st.addr;
out.write((char*)&st,sizeof(stud));
cout<<"Do you want to add more records:";
cin>>y;
}while(y=='y' ||y=='Y');
out.close();
}

void Student ::display()
{
ifstream in ;
in.open("Student.txt" ,ios::in);
in.seekg(0,ios::beg);
cout<<"The content of file are :"<<endl;;
cout<<"Roll No \t Name \t Address\t\n";
while(in.read((char*)&st,sizeof(stud)))
{
if(st.roll_no != -1)
{
cout<<"\n"<<st.roll_no<<"\t"<<st.name<<"\t"<<st.addr<<"\t\n";
}
}
in.close();
}
int Student ::search()
{
int r ,i=0;
ifstream fin;
fin.open("Student.txt" ,ios::in);
fin.seekg(0, ios::beg);
cout<<"Enter roll No.:";
cin>>r;
while(fin.read((char*)&st,sizeof(stud)))
{
if(st.roll_no ==r)
{
cout<<"Record Found !!!";
cout<<"\n"<<st.roll_no<<"\t"<<st.name<<"\t"<<st.addr<<"\t\n";
return i;
}
i++;
}
fin.close();
return -1;
}
void Student::deletee()
{
int pos;
pos=search();
fstream f;
f.open("Student.txt" , ios::in);
f.seekg(0,ios::beg);
if(pos==-1)
{
cout<<"Record is not found .";
return ;
}
int offset =pos*sizeof(stud);
f.seekp(offset);
st.roll_no=-1;
strcpy(st.name ,"NULL");
st.roll_no=-1;
strcpy(st.addr , "NULL");

f.write((char*) &st,sizeof(stud));
f.seekg(0);
f.close();
cout<<"Record deleted ";
}
int main()
{
Student s;
int ch;
cout<<" 1. Insert\n 2. Search \n 3. Delete \n 4. Display \n 5. Exit"<<endl;
while(1)
{
cout<<"Enter your choice :";
cin>>ch;
switch(ch)
{
case 1:
s.create();
break;
case 2:
s.search();
break;
case 3:
s.deletee();
break;
case 4:
s.display();
break;
case 5:
exit(0);
break;
}
}
}
