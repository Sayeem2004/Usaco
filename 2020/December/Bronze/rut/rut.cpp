#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    map<int,array<int,2>> cows;
    vector<int> direction(n);
    vector<int> count(n,0);
    vector<bool> stop(n,false);
    for (int i = 0; i < n; i++) {
        char a; cin >> a;
        int b, c; cin >> b >> c;
        if (a == 'N') {
            cows[i] = {b,c};
            direction[i] = 1;
            count[i] = 0;
        } else {
            cows[i] = {b,c};
            direction[i] = 0;
            count[i] = 0;
        }
    }
    set<array<int,2>> visited;
    int c = n;
    int h = 0;
    while (c > 0) {
        for (int i = 0; i < n; i++) {
            if (stop[i] == false) {
                int a = cows[i][0];
                int b = cows[i][1];
                visited.insert({a,b});
                count[i]++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (stop[i] == false) {
                int a = cows[i][0];
                int b = cows[i][1];
                if (count[i] > 50000) {
                    stop[i] = true;
                    c--;
                    count[i] = -1;
                    continue;
                }
                if (direction[i] == 1) b++;
                else a++;
                if (visited.find({a,b}) != visited.end()) {
                    stop[i] = true;
                    c--;
                } else {
                    cows[i][0] = a;
                    cows[i][1] = b;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (count[i] == -1) {
            cout << "Infinity" << "\n";
        } else {
            cout << count[i] << "\n";
        }
    }
}
