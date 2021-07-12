/*
ID: mohamma176
TASK: ride
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
  freopen("ride.in","r",stdin);
  freopen("ride.out","w",stdout);
  string s, t; cin >> s >> t;
  int c = 1, c2 = 1;
  for (auto x : s) {
    c *= (x-64);
  }
  for (auto x : t) {
    c2 *= (x-64);
  }
  if (c%47 == c2%47) {
    cout << "GO" << "\n";
  } else {
    cout << "STAY" << "\n";
  }
  return 0;
}
