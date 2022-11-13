#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
int v, e, u;
int d[1005];
vector<pair<int, int>> ke[1005];
void dijkstra(int u)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    d[u] = 0;
    pq.push({u, d[u]});
    while (pq.size())
    {
        pair<int, int> top = pq.top();
        pq.pop();
        if (top.second > d[top.first])
            continue;
        for (auto i : ke[top.first])
        {
            if (d[i.first] > d[top.first] + i.second)
            {
                d[i.first] = d[top.first] + i.second;
                pq.push({i.first, d[i.first]});
            }
        }
    }
    for (int i = 1; i <= v; i++)
    {
        if (d[i] != 1e9)
            cout << d[i] << " ";
        else
            cout << -1 << " ";
    }
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
        fill(d, d + 1005, 1e9);
        cin >> v >> e >> u;
        while (e--)
        {
            int x, y, z;
            cin >> x >> y >> z;
            ke[x].push_back({y, z});
            ke[y].push_back({x, z});
        }
        dijkstra(u);
        for (int i = 1; i <= v; i++)
            ke[i].clear();
    }
    return 0;
}
