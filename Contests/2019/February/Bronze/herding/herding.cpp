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
  vector<int> v(3); cin >> v[0] >> v[1] >> v[2];
  sort(all(v));
  int ans = -1, ans2 = -1;
  if (v[2]-v[0] == 2) ans = 0;
  else if (v[1]-v[0] == 2 || v[2]-v[1] == 2) ans = 1;
  else ans = 2;
  ans2 = max(v[1]-v[0],v[2]-v[1])-1;
  cout << ans << "\n" << ans2 << "\n";
}
