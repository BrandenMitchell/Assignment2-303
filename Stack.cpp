#include "Stack.h"
#include <iostream>

using namespace std;

void Stack::add(int val) { vec.push_back(val); }

void Stack::del_top() { vec.pop_back(); }

int Stack::top() {
  // end of the vector represents the top
  return vec.at(vec.size() - 1);
}

double Stack::average_of_elems() {
  int sum = 0;
  for (int i = 0; i < vec.size(); i++) {
    sum += vec.at(i);
  }
  // turn to double
  return static_cast<double>(sum) / static_cast<double>(vec.size());
}

void Stack::print_stack() {
  // printing the stack
  for (int i = vec.size() - 1; i >= 0; i--) {
    cout << vec.at(i) << endl;
  }
}
