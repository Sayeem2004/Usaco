/*
ID: mohamma176
TASK: beads
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
  freopen("beads.in","r",stdin);
  freopen("beads.out","w",stdout);
  int n; cin >> n;
  string s; cin >> s; s = s+s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    char c = s[i];
    int curr = 0, j = i, t = (c=='w' ? 0 : 1);
    for (; t <= 2; t++) {
      for (; j < n+i && (s[j]==c || s[j]=='w'); j++) curr++;
      c = s[j];
    }
    ans = max(ans, curr);
  }
  cout << ans << "\n"; return 0;
}
