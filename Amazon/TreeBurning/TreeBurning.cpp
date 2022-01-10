#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Node {
  public:
    int value;
    Node* left;
    Node* right;

    Node(const int& nodeValue): value(nodeValue), left(nullptr), right(nullptr) {}
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

    vector<int> levelorder() {
      vector<int> ans;
      if (root == nullptr)
        return ans;
      queue<Node*> q;
      q.push(root);
      while (!q.empty()) {
        Node* front = q.front();
        q.pop();
        ans.push_back(front->value);
        if (front->left)
          q.push(front->left);
        if (front->right)
          q.push(front->right);
      }
      return ans;
    }

    int parent(int index) {
      if (index == 0)
        return -1;
      return index%2==0 ? (index-2)/2 : (index-1)/2;
    }
    int leftChild(int index, int n) {
      return index*2+1 < n ? index*2+1 : -1;
    }
    int rightChild(int index, int n) {
      return index*2+2 < n ? index*2+2 : -1;
    }

    int timeToBurn(int target) {
      if (root == nullptr)
        return 0;
      int seconds = 0;
      vector<int> nodes = levelorder();
      int n = nodes.size();
      int targetIndex = find(nodes.begin(), nodes.end(), target) - nodes.begin();
      queue<int> q, storage;
      q.push(targetIndex);
      while (1) {
        while (!q.empty()) {
          int frontIndex = q.front();
          nodes[frontIndex] = -1;
          q.pop();
          if (parent(frontIndex) != -1 && nodes[parent(frontIndex)] != -1)
            storage.push(parent(frontIndex));
          if (leftChild(frontIndex, n) != -1 && nodes[leftChild(frontIndex, n)] != -1)
            storage.push(leftChild(frontIndex, n));
          if (rightChild(frontIndex, n) != -1 && nodes[rightChild(frontIndex, n)] != -1)
            storage.push(rightChild(frontIndex, n));
        }
        if (storage.empty())
          break;
        while (!storage.empty()) {
          q.push(storage.front());
          storage.pop();
        }
        seconds += 1;
      }
      return seconds;
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
