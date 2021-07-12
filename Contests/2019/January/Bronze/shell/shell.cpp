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
  freopen("shell.in","r",stdin);
  freopen("shell.out","w",stdout);
  int n; cin >> n;
  vector<vector<int>> v(n);
  for (int i = 0; i < n; i++) {
    vector<int> t(3); cin >> t[0] >> t[1] >> t[2];
    v[i] = t;
  }
  int ans = 0;
  for (int i = 1; i <= 3; i++) {
    int pos = i, count = 0;
    for (auto x : v) {
      if (pos == x[0]) pos = x[1];
      else if (pos == x[1]) pos = x[0];
      if (pos == x[2]) count++;
    }
    ans = max(ans,count);
  }
  cout << ans << "\n";
}
