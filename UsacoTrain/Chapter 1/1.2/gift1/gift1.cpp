/*
ID: mohamma176
TASK: gift1
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
  freopen("gift1.in","r",stdin);
  freopen("gift1.out","w",stdout);
  int n; cin >> n;
  map<string,int> m;
  vector<string> e;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    m[s] = 0;
    e.pb(s);
  }
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    int t, v; cin >> t >> v;
    if (v != 0) {
      m[s] += (t%v)-t;
      for (int q = 0; q < v; q++) {
        string o; cin >> o;
        m[o] += t/v;
      }
    } else {
      m[s] += 0;
    }
  }
  for (auto x : e) cout << x << " " << m[x] << "\n";
  return 0;
}
