#include <iostream>
using namespace std;

class Node {
int lbit, rbit;
int value;
Node *left, *right;
public:
Node()
{
lbit = rbit = 0;
value = 0;
left = right = NULL;
}
friend class DTBT;
};
class DTBT {
 Node* head;
public:
DTBT()
{
head = new Node();
head->value = 9999;
head->rbit = 1;
head->lbit = 0;
head->left = head;
head->right = head;
}
void create();
void insert(int value);
void inorder();
Node* inorderSuccessor(Node*);
};
void DTBT::create()
{
int n;
cout<<"Enter no. of nodes\n";
cin>>n;
for(int i=0; i<n; i++)
{ int x;
cout<<"Enter data\n";
cin>>x;
this->insert(x);
}
}
void DTBT::insert(int data)
{
if (head->left == head
&& head->right == head) {
Node* p = new Node();
p->value = data;
p->left = head->left;
p->lbit = head->lbit;
p->rbit = 0;
p->right = head->right;
head->left = p;
head->lbit = 1;
return;
}
Node* cur = new Node;
cur = head->left;
while (1) {
if (cur->value < data) {
Node* p = new Node();
p->value = data;
if (cur->rbit == 0) {
p->right = cur->right;
p->rbit = cur->rbit;
p->lbit = 0;
p->left = cur;
cur->rbit = 1;
cur->right = p;
return;
}
else
cur = cur->right;
}
if (cur->value > data) {
Node* p = new Node();
p->value = data;
if (cur->lbit == 0) {
p->left = cur->left;
p->lbit = cur->lbit;
p->rbit = 0;
p->right = cur;
cur->lbit = 1;
cur->left = p;
return;
}
else
cur = cur->left;
}
}
}
void DTBT::inorder()
{
Node* c;
c = head->left;
while (c->lbit == 1)
c = c->left;
while (c != head) {
cout << " " << c->value;
c = inorderSuccessor(c);
}
}
Node* DTBT::inorderSuccessor(Node* c)
{
if (c->rbit == 0)
return c->right;
else
c = c->right;
while (c->lbit == 1) {
c = c->left;
}
return c;
}
int main()
{
DTBT t1;
t1.create();
cout << "Inorder Traversal of DTBST\n";
t1.inorder();
return 0;
}
