#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
int v, e, u;
vector<int> ke[1005];
int ok[1005];
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    while (q.size())
    {
        int top = q.front();
        ok[top] = 1;
        q.pop();
        cout << top << " ";
        for (auto i : ke[top])
            if (!ok[i])
            {
                q.push(i);
                ok[i] = 1;
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
        fill(ok, ok + 1005, 0);
        cin >> v >> e >> u;
        while (e--)
        {
            int x, y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        bfs(u);
        for (int i = 0; i <= v; i++)
            ke[i].clear();
        cout << "\n";
    }
    return 0;
}