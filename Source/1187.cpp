#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
int n, m, q, x, y;
vector<int> ke[1005];
int ok[1005];

void dfs(int u)
{
    ok[u] = 1;
    for (auto i : ke[u])
    {
        if (!ok[i])
            dfs(i);
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
        fill(ok, ok + 1005, 0);
        cin >> n >> m;
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        cin >> q;
        while (q--)
        {
            cin >> x >> y;
            dfs(x);
            if (ok[y])
                cout << "YES\n";
            else
                cout << "NO\n";
            fill(ok, ok + 1005, 0);
        }
        for (int i = 0; i <= n; i++)
            ke[i].clear();
        cout << "\n";
    }
    return 0;
}