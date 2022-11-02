#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
int v, e, a, b;
vector<int> ke[1005];
int ok[1005];
int go[1005];
void dfs(int u)
{
    if (ok[u])
        return;
    ok[u] = 1;
    for (auto i : ke[u])
        if (!ok[i])
        {
            go[i] = u;
            dfs(i);
        }
}
void sol()
{
    if (!go[b] and a != b)
    {
        cout << -1 << "\n";
        return;
    }
    else if (a == b)
    {
        cout << a << "\n";
        return;
    }
    vector<int> vt;
    while (a != b)
    {
        vt.push_back(b);
        b = go[b];
    }
    vt.push_back(a);
    for (int i = vt.size() - 1; i >= 0; i--)
        cout << vt[i] << " ";
    cout << "\n";
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
        fill(go, go + 1005, 0);
        cin >> v >> e >> a >> b;
        while (e--)
        {
            int x, y;
            cin >> x >> y;
            ke[x].push_back(y);
        }
        dfs(a);
        sol();
        for (int i = 0; i <= v; i++)
            ke[i].clear();
    }
    return 0;
}