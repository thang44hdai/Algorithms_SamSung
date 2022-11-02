#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
int v, e, u;
vector<int> ke[1005];
int ok[1005];
void dfs(int u)
{
    cout << u << " ";
    ok[u] = 1;
    for (auto i : ke[u])
        if (!ok[i])
            dfs(i);
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
        cin >> v >> e >> u;
        while (e--)
        {
            int x, y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        dfs(u);
        for (int i = 0; i <= v; i++)
            ke[i].clear();
        cout << "\n";
    }
    return 0;
}