#include <iostream>

template <typename T> class Node {
public:
  T data;
  Node *next;

  Node(T value) : data(value), next(nullptr) {}
};

template <typename T> class LinkedList {
private:
  Node<T> *head;

public:
  LinkedList() : head(nullptr) {}

  ~LinkedList() {
    while (head) {
      Node<T> *temp = head;
      head = head->next;
      delete temp;
    }
  }

  void push_front(T value) {
    Node<T> *newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
  }

  void print() const {
    Node<T> *current = head;
    while (current) {
      std::cout << current->data << " -> ";
      current = current->next;
    }
    std::cout << "null\n";
  }
};
int main() {
  LinkedList<int> list;
  list.push_front(10);
  list.push_front(20);
  list.push_front(30);

  list.print(); // Output: 30 -> 20 -> 10 -> null
}
