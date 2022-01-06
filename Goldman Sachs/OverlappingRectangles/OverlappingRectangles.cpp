#include <iostream>

using namespace std;

struct Coordinate {
  int x;
  int y;
};

class Rectangle {
  public:
    Coordinate l;
    Coordinate r;

    Rectangle(): l({0, 0}), r({0, 0}) {}

    bool hasOverlapWith(Rectangle& rect) {
      if (isLine() || rect.isLine())
        return false;
      if (rect.l.x >= r.x || l.x >= rect.r.x)
        return false;
      if (rect.r.y >= l.y || l.y >= rect.l.y)
        return false;
      return true;
    }

    bool isLine() {
      if (l.x == r.x || l.y == r.y)
        return true;
      return false;
    }
};

void solve() {
  Rectangle r1, r2;
  cin >> r1.l.x >> r1.l.y;
  cin >> r1.r.x >> r1.r.y;
  cin >> r2.l.x >> r2.l.y;
  cin >> r2.r.x >> r2.r.y;
  if (r1.hasOverlapWith(r2) || r2.hasOverlapWith(r1))
    cout << true << "\n";
  else
    cout << false << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
