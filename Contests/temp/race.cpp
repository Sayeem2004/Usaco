/*
ID: mohamma176
TASK: race
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
  freopen("race.in","r",stdin);
  freopen("race.out","w",stdout);
  int k, n; cin >> k >> n;
  while (n--) {
    int x; cin >> x;
    int curr = 0;
    bool br = false;
    for (int i = 1; i <= x; i++) {
      curr += i;
      if (curr >= k) {
        cout << i << "\n";
        br = true; break;
      }
    }
    if (br) continue;
    int rem = k-curr, time = x;
    int i = 0;
    while ((i+1)*(x+1+x+i+1)-(x+i+1) < rem) i++;
    rem -= (i)*(x+1+x+i)-(x+i);
    int rest = rem/(x+i);
    rem -=  rem/(x+i)*(x+i);
    int rest2;
    if (rem%x == 0) rest2 = rem/x;
    else rest2 = rem/x + 1;
    cout << time+i*2-1+rest+rest2 << "\n";
  }
}
