#include <iostream>
#include <queue>

using namespace std;

class Node {
  public:
    int value;
    Node* left;
    Node* right;
    Node* next;

    Node(int nodeValue): value(nodeValue), left(nullptr), right(nullptr), next(nullptr) {}
};

class BinaryTree {
  private:
    Node* root;

  public:
    BinaryTree(const vector<int>& nodeValues) {
      root = nullptr;
      for (const int& nodeValue: nodeValues)
        insert(nodeValue);
    }

    void insert(int nodeValue) {
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

    void connect() {
      if (root == nullptr)
        return;
      queue<Node*> q, aux;
      root->next = nullptr;
      q.push(root);
      while (1) {
        while (!q.empty()) {
          Node* front = q.front();
          q.pop();
          if (front->left)
            aux.push(front->left);
          if (front->right)
            aux.push(front->right);
        }
        if (aux.empty())
          break;
        while (!aux.empty()) {
          Node* front = aux.front();
          aux.pop();
          front->next = aux.empty() ? nullptr : aux.front();
          q.push(front);
        }
      }
      return;
    }

    vector<vector<Node*>> levelorder() {
      vector<vector<Node*>> ans;
      if (root == nullptr)
        return ans;
      queue<Node*> q;
      vector<Node*> row;
      ans.push_back({root});
      q.push(root);
      while (1) {
        while (!q.empty()) {
          Node* front = q.front();
          q.pop();
          if (front->left)
            row.push_back(front->left);
          if (front->right)
            row.push_back(front->right);
        }
        if (row.empty())
          break;
        ans.push_back(row);
        while (!row.empty()) {
          q.push(*row.begin());
          row.erase(row.begin());
        }
      }
      return ans;
    }
};

void print(vector<vector<Node*>>& traversal) {
  cout << "traversal:\n\t";
  for (vector<Node*>& row: traversal) {
    Node* temp = *row.begin();
    while (temp != nullptr) {
      cout << temp->value << " ";
      temp = temp->next;
    }
    cout << "\n\t";
  }
  cout << "\n";
  return;
}

void solve() {
  int n;
  cin >> n;
  vector<int> v(n, 0);
  for (int& x: v)
    cin >> x;

  BinaryTree t(v);
  t.connect();
  vector<vector<Node*>> traversal = t.levelorder();
  print(traversal);
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
