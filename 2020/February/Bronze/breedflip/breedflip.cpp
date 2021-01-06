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
  freopen("breedflip.in","r",stdin);
  freopen("breedflip.out","w",stdout);
  int n; cin >> n;
  string s, t; cin >> s >> t;
  int ans = 0;
  if (n == 1) {
    cout << (s[0]==t[0] ? 0 : 1) << "\n";
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (i == n-1) {
      if (s[i] != t[i]) {
        ans++; break;
      }
    }
    if (s[i] == t[i] && s[i-1] != t[i-1]) ans++;
  }
  cout << ans << "\n";
}
