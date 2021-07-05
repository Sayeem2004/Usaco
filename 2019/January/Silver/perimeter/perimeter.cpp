#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
vector<vector<bool>> V1(1000, vector<bool>(1000)), V2(1000, vector<bool>(1000)), T(1000, vector<bool>(1000));
int n;

int ar(int x, int y) {
    if (x >= n || x < 0 || y >= n || y < 0) return 0;
    else if (!T[x][y] || V1[x][y]) return 0;
    V1[x][y] = true;
    return 1 + ar(x-1, y) + ar(x+1, y) + ar(x, y-1) + ar(x, y+1);

}

int pe(int x, int y) {
    if (x >= n || x < 0 || y >= n || y < 0) return 0;
    else if (!T[x][y] || V2[x][y]) return 0;
    int cnt = 0;
    if (x > 0 && T[x-1][y]) cnt++;
    if (y > 0 && T[x][y-1]) cnt++;
    if (x < 999 && T[x+1][y]) cnt++;
    if (y < 999 && T[x][y+1]) cnt++;
    V2[x][y] = true;
    return (4-cnt) + pe(x-1, y) + pe(x+1, y) + pe(x, y-1) + pe(x, y+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("perimeter.in","r",stdin);
    freopen("perimeter.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < n; q++) {
            char c; cin >> c;
            if (c == '#') T[i][q] = true;
        }
    }
    int mx = 0, x = -1, y = -1;
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < n; q++) {
            int a = -1;
            if (!V1[i][q] && T[i][q]) a = ar(i, q);
            if (a > mx) {
                mx = a; x = i; y = q;
            } else if (a == mx) {
                int b = pe(x, y);
                int d = pe(i, q);
                if (d < b) {x = i; y = q;}
            }
        }
    }
    cout << mx << " " << pe(x, y) << "\n";
}
