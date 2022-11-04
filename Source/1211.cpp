#include <bits/stdc++.h>
#pragma GCC optize("Ofast")
using namespace std;
int num[100005] = {};
int low[100006] = {};
int ok[100005] = {};
int par[100005] = {};
vector<int> ke[100005];
vector<int> vt;
int cnt;
void dfs(int u)
{
    ok[u] = 1;
    low[u] = num[u] = cnt++;
    int cnt_ke = 0;
    for (auto i : ke[u])
    {
        if (i == par[u])
            continue;
        if (!ok[i])
        {
            cnt_ke++;
            par[i] = u;
            dfs(i);
            low[u] = min(low[u], low[i]);
            if (low[i] >= num[u] and par[u])
            {
                vt.push_back(u);
                return;
            }
        }
        else
            low[u] = min(low[u], num[i]);
    }
    if (cnt_ke > 1 and par[u] == 0)
        vt.push_back(u);
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
        cout<<vt.size()<<"\n";
        // if (vt.size())
        //     cout << "NO\n";
        // else
        //     cout << "YES\n";
        // vt.clear();
        for (int i = 1; i <= m; i++)
            ke[i].clear();
    }
    return 0;
}