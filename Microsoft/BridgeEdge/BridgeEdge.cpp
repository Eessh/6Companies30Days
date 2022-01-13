#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class UndirectedGraph {
  private:
    unordered_map<int, vector<int>> map;

  public:
    UndirectedGraph(vector<pair<int, int>>& edges) {
      for (pair<int, int>& e: edges) {
        map[e.first].push_back(e.second);
        map[e.second].push_back(e.first);
      }
    }

    bool isBridge(int src, int dst) {
      /* map[src].erase(find(map[src].begin(), map[src].end(), dst)); */
      /* map[dst].erase(find(map[dst].begin(), map[dst].end(), src)); */

      if (hasRouteBtw(src, dst))
        return false;
      return true;
    }

    bool hasRouteBtw(int src, int dst) {
      queue<int> q;
      unordered_set<int> visited;
      q.push(src);
      while (!q.empty()) {
        int front = q.front();
        if (front == dst)
            return true;
        q.pop();
        visited.insert(front);
        for (int adjNode: map[front])
          if (!(front==src&&adjNode==dst) && visited.find(adjNode) == visited.end())
            q.push(adjNode);
        /* for (int adjNode: map[front]) */
        /*   if (visited.find(adjNode) == visited.end()) */
        /*     q.push(adjNode); */
      }
      return false;
    }
};

void solve() {
  int e, src, dst;
  cin >> e;
  vector<pair<int, int>> edges(e);
  for (pair<int, int>& p: edges)
    cin >> p.first >> p.second;
  cin >> src >> dst;

  UndirectedGraph g(edges);
  cout << "isBridge: " << g.isBridge(src, dst) << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
