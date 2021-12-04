/*
ID: mohamma176
TASK: buckets
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

#define itos(x) to_string(x)
#define stoi(x) stoi(x)
#define ctoi(x) (x-'0')
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
const ll mod = 1e9 + 7;
const ld pi = acos((ld)-1);
const ld e = exp(1);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  freopen("buckets.in","r",stdin);
  freopen("buckets.out","w",stdout);
  int x, y, x2, y2, x3, y3;
  for (int i = 0; i < 10; i++) {
    for (int q = 0; q < 10; q++) {
      char c; cin >> c;
      if (c == 'B') {
        y = i;
        x = q;
      }
      if (c == 'L') {
        y2 = i;
        x2 = q;
      }
      if (c == 'R') {
        y3 = i;
        x3 = q;
      }
    }
  }
  if (x == x2 && x2 == x3) cout << abs(y2-y)+1 << "\n";
  else if (y == y2 && y2 == y3) cout << abs(x2-x)+1 << "\n";
  else if (abs(x2-x) == 1 || abs(y2-y) == 1) cout << 2 << "\n";
  else cout << abs(x2-x)+abs(y2-y)-1 << "\n";
}
