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
  freopen("photo.in","r",stdin);
  freopen("photo.out","w",stdout);
  int n; cin >> n;
  vector<int> v(n-1);
  for (int i = 0; i < n-1; i++) cin >> v[i];
  vector<int> ans(n,1000000);
  for (int i = 1; i < v[0]; i++) {
    vector<int> temp(n,i);
    for (int q = 1; q < n; q++) temp[q] = v[q-1]-temp[q-1];
    bool br = false;
    for (int q = 1; q <= n; q++) {
      if (find(all(temp),q) == temp.end()) {
        br = true; break;
      }
    }
    if (br) continue;
    for (int q = 0; q < n; q++) {
      if (temp[q] > ans[q]) break;
      if (temp[q] < ans[q]) {
        ans = temp; break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (i == n-1) cout << ans[i] << "\n";
    else cout << ans[i] << " ";
  }
}
