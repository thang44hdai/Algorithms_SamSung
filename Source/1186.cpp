#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
int v, e, a, b;
vector<int> ke[1005];
int ok[1005], go[1005];
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    while (q.size())
    {
        int top = q.front();
        ok[top] = 1;
        q.pop();
        for (auto i : ke[top])
            if (!ok[i])
            {
                go[i] = top;
                q.push(i);
                ok[i] = 1;
            }
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
        bfs(a);
        sol();
        for (int i = 0; i <= v; i++)
            ke[i].clear();
    }
    return 0;
}