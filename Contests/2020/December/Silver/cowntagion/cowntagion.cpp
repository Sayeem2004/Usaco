#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector< vector<int> > adj(n+1);
    int a, b;
    while (cin >> a >> b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int v = 1;
    queue<int> q;
    vector<bool> visited(n+1,false);
    q.push(1);
    int ans = 0;
    while (v < n) {
        int c = q.front();
        q.pop();
        if (visited[c]) continue;
        visited[c] = true; v++;
        int count = 0;
        for (int x : adj[c]) {
            if (!visited[x]) {
                count++;
                q.push(x);
            }
        }
        ans += ceil(log2(count+1));
        ans += count;
    }
    cout << ans << "\n";
}
