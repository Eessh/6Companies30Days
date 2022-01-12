#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class Trie;

class TrieNode {
  private:
    unordered_map<char, TrieNode*> children;
    int count;
    // To store which all contacts end here
    vector<int> indices;
    friend Trie;

  public:
    TrieNode(int _count) {
      count = _count;
    }
};

class Trie {
  private:
    TrieNode* root;
    
    void insertAllPrefixesUtil(string s, TrieNode* node, int idx) {
      if(s.empty())
        return;
      TrieNode* child = node->children[s[0]];
      if(child == NULL) {
        child = new TrieNode(1);
        node->children[s[0]] = child;
      }
      child->count++;
      child->indices.push_back(idx);
      insertAllPrefixesUtil(s.substr(1), child, idx);
    }
    
    void getDirectoryUtil(string s, vector<vector<string>> &res, TrieNode* node, vector<string> &p) {
      if(s.empty())
        return;
      TrieNode* child = node->children[s[0]];
      if(child == NULL) return;
      int n = child->indices.size();
      vector<string> curr;
      for(int i = 0; i < n; i++)
        curr.push_back(p[child->indices[i]]);
      res.push_back(curr);
      getDirectoryUtil(s.substr(1), res, child, p);
    }
    
  public:
    Trie() {
      root = new TrieNode(0);
    }
    
    void insertAllPrefixes(string s, int idx) {
      insertAllPrefixesUtil(s, root, idx);
    }
    
    void getDirectory(string s, vector<vector<string>> &res, vector<string> &p) {
      getDirectoryUtil(s, res, root, p);
    }
};

// TC: O(K * NlogN), SC: O(N * K)
vector<string> unqContacts(string a[], int n) {
  set<string> s(a, a + n);
  return vector<string>(s.begin(), s.end());
}

vector<vector<string>> displayContacts(int n, string contact[], string s) {
  // SC: O(N * K)
  vector<vector<string>> res;
  vector<string> p = unqContacts(contact, n);
  n = p.size();
  Trie t;
  // TC: O(K * N), SC: O(N^2 * K)
  for(int i = 0; i < n; i++)
    t.insertAllPrefixes(p[i], i);
  // TC: O(S * K * N)
  t.getDirectory(s, res, p);
  // Push 0s for the rest
  while(res.size() < s.size()) res.push_back({"0"});
  
  return res;
}

void solve() {
  int n;
  cin >> n;
  string* contacts = (string*)malloc(n*sizeof(string));
  for (int i = 0; i < n; i++)
    cin >> contacts[i];
  /* vector<string> contacts(n, ""); */
  /* for (string& s: contacts) */
  /*   cin >> s; */
  string s;
  cin >> s;

  vector<vector<string>> results = displayContacts(n, contacts, s);
  cout << "search results:\n\t";
  for (vector<string>& r: results) {
    for (string& s: r)
      cout << s << " ";
    cout << "\n\t";
  }
  cout << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
