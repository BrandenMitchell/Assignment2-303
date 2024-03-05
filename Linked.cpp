#include "Linked.h"

using namespace std;
// constructor
Linked::Linked() {
  headPtr = nullptr;
  tailPtr = nullptr;
}

void Linked::push_front(string data) {
  node *temp = new node;
  temp->data = data;
  temp->index = 0;
  if (headPtr != nullptr) { // not empty
    temp->next = headPtr;
    headPtr = temp;

    temp = headPtr->next;
    while (temp != nullptr) {
      temp->index += 1;

      temp = temp->next;
    }
  } else {
    headPtr = temp;
    tailPtr = temp;
  }
}

void Linked::push_back(string data) {
  node *temp = new node;
  temp->data = data;
  temp->index = length();
  if (headPtr != nullptr) {
    tailPtr->next = temp;
    temp->next = nullptr; // make new tail with new node
    tailPtr = temp;
  } else {
    headPtr = temp;
    tailPtr = temp;
  }
}

void Linked::pop_front() {
  if (headPtr == nullptr)
    return;
  else {
    node *temp = new node;
    temp = headPtr->next;
    delete headPtr; // free memory
    headPtr = temp;

    temp = headPtr;
    while (temp != nullptr) { // adjust index
      temp->index -= 1;
      temp = temp->next;
    }
  }
}

void Linked::pop_back() {
  if (headPtr == nullptr)
    return;
  else {
    node *temp = headPtr;
    while (temp->next != tailPtr) {
      temp = temp->next;
    }
    delete tailPtr;
    tailPtr = temp;
  }
}
// prints list for viewing
void Linked::print() {
  node *temp = headPtr;
  while (temp != nullptr) {
    cout << temp->data << endl;
    temp = temp->next;
  }
}

int Linked::length() {
  int size = 0;
  if (headPtr == nullptr)
    return size;
  else {

    node *temp = headPtr;
    while (temp != nullptr) {
      size++;
      temp = temp->next;
    }
    return size;
  }
}

void Linked::inserting(unsigned int index, string data) {
  if (index > length() - 1) {
    push_back(data);
  } else {
    node *temp = headPtr;
    node *newNode = new node;
    newNode->index = index;
    while (temp != nullptr) {
      if (temp->next->index == index) {
        newNode->data = data;
        newNode->next = temp->next;
        temp->next = newNode;
        break;
      }
      temp = temp->next;
    }
    temp = newNode->next;
    while (temp != nullptr) {
      temp->index += 1;
      temp = temp->next;
    }
  }
}

unsigned int Linked::find(std::string key) {
  bool found = false;
  node *temp = headPtr;
  while (temp != nullptr) {
    if (temp->data == key) {
      found = true;
      break;
    }
    temp = temp->next;
  }
  if (found)
    return temp->index;
  else
    return length();
}

bool Linked::del_node(unsigned int index) {
  if (index > length() - 1) // Check to see of index is out of bounds
    return false;
  else {
    node *temp = headPtr;
    node *removed = new node; // temp node to hold removed node
    while (temp != nullptr) {
      if (temp->next->index == index) {
        removed = temp->next;
        temp->next = removed->next;
        delete removed;
        break;
      }
      temp = temp->next;
    }
    temp = temp->next;
    while (temp != nullptr) {
      temp->index -= 1;
      temp = temp->next;
    }
    return true;
  }
}

// below are some "utility" functions
string Linked::front() { return headPtr->data; }

string Linked::back() { return tailPtr->data; }

bool Linked::empty() {
  if (headPtr == nullptr)
    return true;
  else
    return false;
}
