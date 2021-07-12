#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);
    int n, m; cin >> n >> m;
    vector<vector<int>> S(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for (int q = 0; q < m; q++)
        {
            if (s[q] == 'A') S[i][q] = 0;
            if (s[q] == 'C') S[i][q] = 1;
            if (s[q] == 'G') S[i][q] = 2;
            if (s[q] == 'T') S[i][q] = 3;
        }
    }
    vector<vector<int>> P(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for (int q = 0; q < m; q++)
        {
            if (s[q] == 'A') P[i][q] = 0;
            if (s[q] == 'C') P[i][q] = 1;
            if (s[q] == 'G') P[i][q] = 2;
            if (s[q] == 'T') P[i][q] = 3;
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int q = i+1; q < m; q++)
        {
            for (int r = q+1; r < m; r++)
            {
                bool works = true;
                vector<int> C(64);
                for (auto x : P)
                {
                    C[x[i]*16+x[q]*4+x[r]] = 1;
                }
                for (auto x : S)
                {
                    if (C[x[i]*16+x[q]*4+x[r]] == 1) works = false;
                }
                if (works) ans++;
            }
        }
    }
    cout << ans << "\n";
}
