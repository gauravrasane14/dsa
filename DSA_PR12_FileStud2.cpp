#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class Student
{
    typedef struct{
    int roll;
    char name[10];
    char div;
    char add[10];
    } stud;
const char* filename = "stud.dat";
stud rec;
public:
    void create();
    void display();
    int search();
    void Delete();
};
void Student::create() {
char ans;
ofstream fout;
// Open the file for both input and output operations in binary mode
fout.open("studn.dat", ios::in | ios::out | ios::binary);
do {
// Prompt user for student information
cout << "\n\tEnter Roll No of Student : ";
cin >> rec.roll;
cout << "\n\tEnter a Name of Student : ";

cin >> rec.name;
cout << "\n\tEnter a Division of Student : ";
cin >> rec.div;
cout << "\n\tEnter a Address of Student : ";
cin >> rec.add;

fout.seekp((rec.roll - 1) * sizeof(stud)); // Move the write pointer to the desired position
// Write the record to the file
fout.write((char*)&rec, sizeof(stud));
cout << "\n\tDo You Want to Add More Records: ";
cin >> ans;
} while (ans == 'y' || ans == 'Y');
fout.close(); // Close the file
}
void Student::display() {
ifstream fin;
// Open the file for input operations in binary mode
fin.open("studn.dat", ios::binary);
cout << "\n\tThe Content of File are:\n";
cout << "\n\tRoll\tName\tDiv\tAddress";
// Read and display all records from the file
while (fin.read((char*)&rec, sizeof(stud))) {
if (rec.roll != -1)
cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
}
fin.close(); // Close the file
}
int Student::search() {
int r;
ifstream fin;
fin.open("studn.dat", ios::binary);
cout << "\n\tEnter a Roll No: ";
cin >> r;

fin.seekg((r - 1) * sizeof(stud)); // Move the read pointer to the desired position
fin.read((char*)&rec, sizeof(stud));

if (rec.roll == r) {
cout << "\n\tRecord Found...\n";
cout << "\n\tRoll\tName\tDiv\tAddress";
cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
return r;
}
else {
cout << "\n\tRecord Not Found...\n";
return -1;

}
fin.close(); // Close the file
return 0;
}
void Student::Delete() {
int pos = search();
if (pos == -1) {
cout << "\n\tRecord Not Found";
return;
}
fstream f;
f.open("studn.dat", ios::in | ios::out | ios::binary);

f.seekp((pos - 1) * sizeof(stud));
rec.roll = -1;
strcpy(rec.name, "NULL");
rec.div = 'N';
strcpy(rec.add, "NULL");
f.write((char*)&rec, sizeof(stud));
f.close();
cout << "\n\tRecord Deleted";
}
int main() {
Student obj;
int ch;
char ans;
do {
cout << "\n*** Student Information ***";
cout << "\n1. Create\n2. Display\n3. Delete\n4. Search\n5. Exit";
cout << "\nEnter Your Choice: ";
cin >> ch;

switch (ch) {
case 1: obj.create(); break;
case 2: obj.display(); break;
case 3: obj.Delete(); break;
case 4: obj.search(); break;
case 5: break;
}
cout << "\n\t..... Do You Want to Continue in Main Menu: ";
cin >> ans;
} while (ans == 'y' || ans == 'Y');
return 0;
}