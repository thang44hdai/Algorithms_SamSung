#include <bits/stdc++.h>
#pragma GCC optize("Ofast")
using namespace std;
int num[1005] = {};
int low[1005] = {};
int ok[1005] = {};
int par[1005] = {};
vector<int> ke[1005];
vector<pair<int, int>> vt;
int cnt;
void dfs(int u)
{
    ok[u] = 1;
    low[u] = num[u] = cnt++;
    for (auto i : ke[u])
    {
        if (i == par[u])
            continue;
        if (!ok[i])
        {
            par[i] = u;
            dfs(i);
            low[u] = min(low[u], low[i]);
            if (low[i] == num[i])
            {
                if (u < i)
                    vt.push_back({u, i});
                else
                    vt.push_back({i, u});
            }
        }
        else
            low[u] = min(low[u], num[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cnt = 0;
        memset(ok, 0, sizeof(ok));
        memset(num, 0, sizeof(num));
        memset(low, 0, sizeof(low));
        memset(par, 0, sizeof(par));
        int m, n;
        cin >> m >> n;
        while (n--)
        {
            int x, y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        dfs(1);
        if (!vt.size())
            cout << "-1";
        else
        {
            sort(vt.begin(), vt.end());
            for (auto x : vt)
                cout << x.first<<" "<<x.second<< " ";
        }
        vt.clear();
        for (int i = 1; i <= m; i++)
            ke[i].clear();
        cout << "\n";
    }
    return 0;
}