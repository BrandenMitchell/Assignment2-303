#include "Linked.h"
#include "Stack.h"

using namespace std;

int main() {

  Linked list;
  list.push_back("bobby");
  list.push_back("dylan");
  list.push_back("copelyn");
  list.push_back("guccimane");

  cout << "list-- " << endl;
  list.print();

  cout << "Push back the name bill and pop_front-- " << endl;
  list.push_back("bill");
  list.pop_front();
  cout << "list: " << endl;
  list.print();

  cout << "insert karen to index 1:" << endl;
  list.inserting(1, "karen");
  list.print();

  // display the front and back of the list
  cout << "front() = " << list.front() << endl;
  cout << "back() = " << list.back();
  cout << endl;
  //////////////////////////////////////stackkkkkk//////////////////////////////////
  Stack stack;
  stack.add(67);
  stack.add(88);
  stack.add(37);
  stack.add(18);
  stack.add(100);
  cout << "Stack : " << endl;
  stack.print_stack();
  cout << endl;
  cout << "Stack after adding 14: " << endl;
  stack.add(14);
  stack.print_stack();
  cout << endl;

  cout << "Stack after removing top element :" << endl;
  stack.del_top();
  stack.print_stack();
  cout << endl;

  return 0;
}
