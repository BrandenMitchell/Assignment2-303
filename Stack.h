#include <vector>

using namespace std;

class Stack {
private:
  vector<int> vec;

public:
  void add(int);
  void del_top();
  bool is_empty() { return vec.empty(); }
  int top();
  double average_of_elems();
  void print_stack();
};
