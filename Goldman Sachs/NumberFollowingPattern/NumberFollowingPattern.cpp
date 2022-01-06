#include <iostream>
#include <string>
#include <stack>

using namespace std;

void solve() {
  string s;
  cin >> s;
  string ans;
  stack<int> stk;
  int num = 1;
  for(auto it:s){
    if (it == 'D') {
      stk.push(num);
      num++;
    }
    else {
      stk.push(num);
      num++;
      while (!stk.empty()) {
        ans += to_string(stk.top());
        stk.pop();
      }
    }
  }
  stk.push(num);
  while(!stk.empty()){
    ans += to_string(stk.top());
    stk.pop();
  }
  cout << "min number: " << ans << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
