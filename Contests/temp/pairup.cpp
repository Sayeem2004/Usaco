#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("pairup.in","r",stdin);
    freopen("pairup.out","w",stdout);
    int n; cin >> n;
    vector<int> V;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        for (int q = 0; q < a; q++) {
            V.push_back(b);
        }
    }
    sort(V.begin(),V.end());
    int mx = 0;
    for (int i = 0; i < V.size()/2; i++) {
        mx = max(V[i]+V[n-i-1],mx);
    }
    cout << mx << "\n";
}
