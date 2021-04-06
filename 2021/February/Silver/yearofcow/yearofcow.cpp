#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    set<int> Y;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        Y.insert(a/12);
    }
    vector<int> YR;
    YR.push_back(0);
    for (auto x : Y)
        YR.push_back(x);
    YR.push_back(YR[YR.size()-1]+1);
    vector<int> D;
    for (int i = 1; i < YR.size(); i++) {
        D.push_back(YR[i]-YR[i-1]);
    }
    int ans = YR[YR.size()-1]+1;
    sort(D.rbegin(),D.rend());
    for (int i = 0; i < k-1; i++)
        if (D[i] != 1) ans -= D[i];
    cout << ans*12 << "\n";
}
