/*
ID: mohamma176
TASK: friday
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
  freopen("friday.in","r",stdin);
  freopen("friday.out","w",stdout);
  vector<int> ans(7,0);
  ll day = 1, year = 1900;
  int n; cin >> n;
  vector<int> norm = {31,28,31,30,31,30,31,31,30,31,30,31};
  vector<int> leap = {31,29,31,30,31,30,31,31,30,31,30,31};
  for (int i = 0; i < n; i++) {
    vector<int> curr;
    if (year%400 == 0) curr = leap;
    else if (year%100 == 0) curr = norm;
    else if (year%4 == 0) curr = leap;
    else curr = norm;
    for (auto x : curr) {
      day += 13;
      ans[day%7]++;
      day += x-13;
    }
    year++;
  }
  for (int i = 0; i < 7; i++) {
    if (i == 6) {
      cout << ans[i] << "\n";
      break;
    }
    cout << ans[i] << " ";
  }
}
