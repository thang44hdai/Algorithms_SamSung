#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
int v, e, m;
vector<int> ke[15];
int color[15];
void dfs(int u, int mau)
{
    color[u] = mau;
    for (auto i : ke[u])
    {
        if (color[i])
        {
            color[u]=min(color[u], color[i]+1);
            continue;
        }
        if (color[i] == 0)
        {
            dfs(i, mau + 1);
        }
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
        cin >> v >> e >> m;
        while (e--)
        {
            int x, y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        fill(color, color + 15, 0);
        dfs(1,1);
        for(int i=1;i<=v;i++)
            cout<<color[i]<<" ";
    }
    return 0;
}
