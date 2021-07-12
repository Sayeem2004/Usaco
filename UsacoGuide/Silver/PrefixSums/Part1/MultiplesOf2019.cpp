#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string S; cin >> S;
    map<int, int> M;
    M[0]++;
    ll ans = 0, num = 0, pw = 1;
    for (int i = S.size()-1; i >= 0; i--) {
        int dig = S[i]-'0';
        num = (num + dig * pw) % 2019;
        pw = (pw * 10) % 2019;
        ans += M[num];
        M[num]++;
    }
    cout << ans << "\n";
}
