#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int solve(string s) {
    int count = 1;
    int n = s.size();
    if (n == 0) return 0;
    vector<int> last(26,-1);
    set<char> painted;
    last[int(s[0])-65] = 0;
    painted.insert(s[0]);
    for (int i = 1; i < n; i++) {
        int a = int(s[i])-65;
        if (int(s[i]) > int(s[i-1]) || painted.find(s[i]) == painted.end()) {
            count++;
            last[a] = i;
            painted.insert(s[i]);
            continue;
        }
        if (int(s[i]) == int(s[i-1])) continue;
        for (int q = 0; q < a; q++) {
            if (last[q] > a) {
                count++; break;
            }
        }
        last[a] = i;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        string s2 = s.substr(0,a-1);
        string s3 = s.substr(b-1);
        cout << solve(s2)+solve(s3) << "\n";
    }
}
