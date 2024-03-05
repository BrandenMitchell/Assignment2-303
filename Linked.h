#include <iostream>
#include <string>

using namespace std;
// i was told about unsigned int by Michael he was a great help explaining
// linked list structure and this awesome variable but the unsigned prevents
// negatives so it helps with edge cases!

struct node {
  string data;
  unsigned int index;
  node *next;
};

class Linked {
private:
  node *headPtr;
  node *tailPtr;

public:
  Linked();
  void push_front(string data);

  void push_back(string data);

  void pop_front();

  void pop_back();

  void print();

  int length();

  string front();
  string back();
  bool is_empty();

  void inserting(unsigned int, string data);
  bool del_node(unsigned int);
  unsigned int search(string key);
};
