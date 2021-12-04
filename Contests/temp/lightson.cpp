#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("lightson.in","r",stdin);
    freopen("lightson.out","w",stdout);
    int n, m; cin >> n >> m;
    map<array<int,2>,vector<array<int,2>>> mp;
    for (int i = 0; i < m; i++) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        mp[{x-1,y-1}].push_back({a-1,b-1});
    }
    bool count[n][n];
    memset(count, 0, sizeof(count));
    int ans = 1;
    count[0][0] = true;
    queue<array<int,2>> q;
    q.push({0,0});
    map<array<int,2>,bool> uv, v;
    v[{0,0}] = true;
    while (!q.empty()) {
        array<int,2> p = q.front();
        if (mp[p].size() != 0) {
            for (int i = 0; i < mp[p].size(); i++) {
                int a = mp[p][i][0], b = mp[p][i][1];
                if (!count[a][b]) {
                    ans++;
                    count[a][b] = true;
                }
                if (v[{a+1,b}] || v[{a-1,b}] || v[{a,b+1}] || v[{a,b-1}]) {
                    q.push({a,b});
                    v[{a,b}] = true;
                    if (uv[{a+1,b}]) {
                        uv[{a+1,b}] = false;
                        q.push({min(a+1,n-1),b});
                    }
                    if (uv[{a-1,b}]) {
                        uv[{a-1,b}] = false;
                        q.push({max(a-1,0),b});
                    }
                    if (uv[{a,b+1}]) {
                        uv[{a,b+1}] = false;
                        q.push({a,min(b+1,n-1)});
                    }
                    if (uv[{a,b+1}]) {
                        uv[{a,b+1}] = false;
                        q.push({a,max(b-1,0)});
                    }
                } else {
                    uv[{a,b}] = true;
                }
            }
        }
        q.pop();
    }
    cout << ans << "\n";
}
