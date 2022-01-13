#include <iostream>
#include <queue>

using namespace std;

void solve() {
  int d;
  cin >> d;

  int steps = 0;
  queue<int> q, aux;
  q.push(0);
  while (1) {
    steps += 1;
    while (!q.empty()) {
      int front = q.front();
      if (front == d) {
        cout << "min steps: " << steps-1 << "\n";
        return;
      }
      q.pop();
      aux.push(front-steps);
      aux.push(front+steps);
    }
    while (!aux.empty()) {
      q.push(aux.front());
      aux.pop();
    }
  }
  cout << "min steps: " << steps << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
