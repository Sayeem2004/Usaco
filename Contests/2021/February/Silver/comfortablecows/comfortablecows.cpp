#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int update(map<array<int,2>,int> m) {
    map<array<int,2>,int> mp;
    for (auto a : m) {
        int count = 0;
        array<int,2> x = a.first;
        if (m[{x[0]-1,x[1]}] != 0) count++;
        if (m[{x[0]+1,x[1]}] != 0) count++;
        if (m[{x[0],x[1]-1}] != 0) count++;
        if (m[{x[0],x[1]+1}] != 0) count++;
        mp[x] = count;
        cout << "HI" << "\n";
    }
    for (auto a : mp) {
        array<int,2> x = a.first;
        if (mp[{x[0],x[1]}] == 3) {
            mp[{x[0],x[1]}] = 4;
            mp[{x[0]-1,x[1]}] = -1;
            mp[{x[0]+1,x[1]}] = -1;
            mp[{x[0],x[1]-1}] = -1;
            mp[{x[0],x[1]+1}] = -1;
            return 1 + update(mp);
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    map<array<int,2>,int> mp;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if (mp[{a-1,b}] != 0) {
            mp[{a-1,b}]++;
            mp[{a,b}]++;
        }
        if (mp[{a+1,b}] != 0) {
            mp[{a+1,b}]++;
            mp[{a,b}]++;
        }
        if (mp[{a,b-1}] != 0) {
            mp[{a,b-1}]++;
            mp[{a,b}]++;
        }
        if (mp[{a,b+1}] != 0) {
            mp[{a,b+1}]++;
            mp[{a,b}]++;
        }
        cout << update(mp) << "\n";
    }
}
