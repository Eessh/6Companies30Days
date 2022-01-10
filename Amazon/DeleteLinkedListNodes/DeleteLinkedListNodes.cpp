#include <iostream>
#include <vector>

using namespace std;

class Node {
  public:
    int value;
    Node* next;

    Node(const int& nodeValue): value(nodeValue), next(nullptr) {}
};

class LinkedList {
  private:
    Node* head;
    int size;

    void helper(Node* headNode, int m, int n) {
      if (headNode == nullptr)
        return;
      int mcopy = m, ncopy = n;
      Node* temp1 = headNode;
      m -= 1;
      while (m-- && temp1!=nullptr)
        temp1 = temp1->next;
      if (temp1 == nullptr)
        return;
      Node* temp2 = temp1->next;
      while (n-- && temp2!=nullptr)
        temp2 = temp2->next;
      temp1->next = temp2;
      helper(temp2, mcopy, ncopy);
      return;
    }

  public:
    LinkedList(): head(nullptr), size(0) {}
    LinkedList(const vector<int>& nodeValues) {
      head = nullptr;
      size = 0;
      for (const int& nodeValue: nodeValues)
        pushback(nodeValue);
    }

    void pushback(const int& nodeValue) {
      size += 1;
      if (head == nullptr) {
        head = new Node(nodeValue);
        return;
      }
      Node* temp = head;
      while (temp->next != nullptr)
        temp = temp->next;
      temp->next = new Node(nodeValue);
      return;
    }

    void deleteNafterM(int m, int n) {
      helper(head, m, n);
      return;
    }

    void print() {
      cout << "LinkedList: [ ";
      Node* temp = head;
      while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
      }
      cout << "]\n";
      return;
    }
};

void solve() {
  int size, m, n;
  cin >> size >> m >> n;
  vector<int> v(size, 0);
  for (int& x: v)
    cin >> x;
  LinkedList l(v);
  l.deleteNafterM(m, n);
  l.print();
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
