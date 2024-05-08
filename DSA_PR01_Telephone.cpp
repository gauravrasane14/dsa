#include <iostream>
using namespace std;
#define size 10
class node {
  int id;
  long int tel;
  string name;
  friend class hashing;

 public:
  node() {
    id = 0;
    tel = 0;
    name = " ";
  }
};
class hashing {
  node data[size];
  int index;
 public:
  void create() {
      int i;
      long int t;
      string n;
    cout << "\nEnter ID:";
    cin >> i;
    cout << "\nEnter Name:";
    cin >> n;
    cout << "\nEnter Telephone No:";
    cin >> t;
    index = i % size;
    for (int j = 0; j < size; j++) {
      if (data[index].id == 0) {
        data[index].id = i;
        data[index].name = n;
        data[index].tel = t;

        break;
      } else {
        index = (index + 1) % size;
      }
    }
  }
  void display() {
    cout << "\n\tID\tName\tTelephone No.";
    for (int j = 0; j < size; j++) {
      if (data[j].id != 0) {
        cout << "\n\t" << data[j].id;
        cout << "\t" << data[j].name;
        cout << "\t" << data[j].tel;
      }
    }
  }
  
  
  void search() {
    int flag = 0, i;
    cout << "\nEnter the ID you want to search:";
    cin >> i;
    index = i % size;
    for (int j = 0; j < size; j++) {
      if (data[index].id == i) {
        flag = 1;
        cout << "Record Found\n";
        cout << "\n\tId\tName\tTelephone no";
        cout << "\n\t" << data[index].id;
        cout << "\t" << data[index].name;
        cout << "\t" << data[index].tel << "\n";
        break;
      } else {
        index = (index + 1) % size;
      }
    }
    if (flag == 0) {
        cout << "ID NOT Found\n";
      }
  }
  void Delete() {
    int flag = 0, i;
    cout << "\nEnter the ID you want to delete:";
    cin >> i;
    index = i % size;
    for (int j = 0; j < size; j++) {
      if (data[index].id = i) {
        data[index].id = 0;
        data[index].name = " ";
        data[index].tel = 0;
        cout << "Record Deleted";
        break;
      } else {
        index = (index + 1) % size;
      }
      if (flag == 0) {
        cout << "ID NOT Found\n";
      }
    }
  }
};
int main() {
  hashing h;
  int i, ch;
  long int t;
  string n;
  while (1) {
    cout << "\n*****TELEPHONE DIRECTORY*****\n";
    cout << "1 .Create ID\n2. Display ID\n3. Search\n4. Delete\n5. Exit\n";
    cin >> ch;
    switch (ch) {
      case 1: {
        h.create();
        break;
      }
      case 2: {
        h.display();
        break;
      }
      case 3: {
        h.search();
        break;
      }
      case 4: {
        h.Delete();
        break;
      }
      case 5: {
        exit(0);
        break;
      }

      default: {
        cout << "Enter correct choice";
      }
    }
  }

  return 0;
}