#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
int v, e;
vector<int> ke[1005];
int ok[1005];
int par[1005];
int dfs(int u)
{
    ok[u] = 1;
    for (auto i : ke[u])
        if (!ok[i])
        {
            par[i] = u;
            dfs(i);
        }
        else if (i != par[u])
            return 1;
    return 0;
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

        cin >> v >> e;
        while (e--)
        {
            int x, y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        int check = 1;
        for (int i = 1; i <= v; i++)
            if (dfs(i))
            {
                cout << "YES";
                check = 0;
                break;
            }
            else
                fill(ok, ok + 1005, 0);
        if (check)
            cout << "NO";
        cout << "\n";
        for (int i = 1; i <= v; i++)
            ke[i].clear();
    }
    return 0;
}