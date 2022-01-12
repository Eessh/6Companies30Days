#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Node {
  public:
    int value;
    Node* left;
    Node* right;

    Node(const int& nodeValue): value(nodeValue), left(nullptr), right(nullptr) {}
};

class UndirectedGraph {
  private:
    unordered_map<int, vector<int>> map;

  public:
    UndirectedGraph(Node* rootNode) {
      readTree(rootNode);
    }
    void readTree(Node* rootNode) {
      if (rootNode == nullptr)
        return;
      if (map.find(rootNode->value) == map.end())
        map[rootNode->value] = {};
      if (rootNode->left) {
        map[rootNode->value].push_back(rootNode->left->value);
        map[rootNode->left->value].push_back(rootNode->value);
        readTree(rootNode->left);
      }
      if (rootNode->right) {
        map[rootNode->value].push_back(rootNode->left->value);
        map[rootNode->right->value].push_back(rootNode->value);
        readTree(rootNode->right);
      }
      return;
    }

    int burn(int target) {
      int secs = 0;
      queue<int> q, aux;
      q.push(target);
      while (!map.empty()) {
        while (!q.empty()) {
          int front = q.front();
          q.pop();
          for (int x: map[front]) {
            if (map.find(x) != map.end())
              aux.push(x);
          }
          map.erase(front);
        }
        if (aux.empty())
          break;
        while (!aux.empty()) {
          q.push(aux.front());
          aux.pop();
        }
        secs += 1;
      }
      return secs + 1;
    }
};

class BinaryTree {
  private:
    Node* root;

  public:
    BinaryTree(): root(nullptr) {}
    BinaryTree(const vector<int>& nodeValues) {
      root = nullptr;
      for (const int& nodeValue: nodeValues)
        insert(nodeValue);
    }

    void insert(const int& nodeValue) {
      if (root == nullptr) {
        root = new Node(nodeValue);
        return;
      }
      queue<Node*> q;
      q.push(root);
      while (!q.empty()) {
        Node* front = q.front();
        q.pop();
        if (!front->left) {
          front->left = new Node(nodeValue);
          return;
        }
        if (!front->right) {
          front->right = new Node(nodeValue);
          return;
        }
        q.push(front->left);
        q.push(front->right);
      }
      return;
    }

    int timeToBurn(int target) {
      UndirectedGraph g(root);
      return g.burn(target);
    }
};

void solve() {
  int n, target;
  cin >> n >> target;
  vector<int> v(n, 0);
  for (int& x: v)
    cin >> x;
  BinaryTree t(v);
  cout << "seconds to burn: " << t.timeToBurn(target) << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
