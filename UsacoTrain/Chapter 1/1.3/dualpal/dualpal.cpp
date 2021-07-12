/*
ID: mohamma176
TASK: dualpal
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

string cbase(int n, int b) {
  string s = "";
  vector<char> c = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
  while (n > 0) {
    s = c[n%b]+s;
    n = n/b;
  }
  return s;
}

// Check Palindrome
bool pdrome(string s) {
  int n = sz(s);
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n-i-1]) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  freopen("dualpal.in","r",stdin);
  freopen("dualpal.out","w",stdout);
  int n, s; cin >> n >> s;
  int count = 0, curr = s+1;
  while (count < n) {
    int cp = 0;
    for (int i = 2; i <= 10; i++) {
      if (pdrome(cbase(curr,i))) cp++;
      if (cp >= 2) break;
    }
    if (cp >= 2) {
      cout << curr << "\n";
      count++;
    }
    curr++;
  }
}
