/*
ID: mohamma176
TASK: milk2
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
  freopen("milk2.in","r",stdin);
  freopen("milk2.out","w",stdout);
  int n; cin >> n;
  vector<int> v(1000001);
  int mx = 0, mn = 1000000;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    for (int q = x; q < y; q++) v[q] = 1;
    mx = max(mx,y);
    mn = min(mn,x);
  }
  int c1 = 0, c0 = 0, ans1 = 0, ans0 = 0;
  for (int i = mn; i < mx; i++) {
    if (v[i] == 1) {
      c1++;
      c0 = 0;
    } else {
      c0++;
      c1 = 0;
    }
    ans1 = max(c1,ans1);
    ans0 = max(c0,ans0);
  }
  cout << ans1 << " " << ans0 << "\n";
}
