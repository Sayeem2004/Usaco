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
  freopen("triangles.in","r",stdin);
  freopen("triangles.out","w",stdout);
  int n; cin >> n;
  vector<int> x(n), y(n);
  int ans = 0;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  for (int a = 0; a < n; a++) {
    for (int b = 0; b < n; b++) {
      for (int c = 0; c < n; c++) {
        if (x[a] == x[b] && y[b] == y[c]) {
          ans = max(ans,abs(y[a]-y[b])*abs(x[b]-x[c]));
        }
      }
    }
  }
  cout << ans << "\n";
}
