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
  freopen("word.in","r",stdin);
  freopen("word.out","w",stdout);
  int n, k; cin >> n >> k;
  vector<vector<string>> v(n);
  int curr = 0, pos = 0;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    int x = sz(s);
    if (curr + x <= k) {
      v[pos].pb(s);
      curr += x;
      continue;
    } else {
      curr = x;
      pos++;
      v[pos].pb(s);
    }
  }
  for (auto x : v) {
    for (int i = 0; i < sz(x); i++) {
      if (i == sz(x)-1) cout << x[i] << "\n";
      else cout << x[i] << " ";
    }
  }
}
