#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

bool comp(arr<int, 2> a, arr<int,2> b){
    if (a[0] < b[0]) {
        return true;
    } else if (a[0] == b[0] && a[1] > b[1]){
        return true;
    } else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("mountains.in","r",stdin);
    freopen("mountains.out","w",stdout);
    int n; cin >> n;
    vector<arr<int,2>> S(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        S[i] = {a-b,a+b};
    }
    sort(S.begin(),S.end(),comp);
    vector<int> I(n);
    int mx = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (mx >= S[i][1]) cnt++;
        mx = max(mx, S[i][1]);
    }
    cout << n-cnt << "\n";
}
