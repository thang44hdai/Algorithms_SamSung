#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
bitset<15> bs;
vector<int> a[15];
bool ok;

void DFS(int u, int v, int cnt = 1)
{
    if(cnt == v)
    {
        ok = 1;
        return;
    }
    if(ok)
        return;
    for(int &i : a[u])
    {
        if(!bs[i])
        {
            bs[i] = 1;
            DFS(i, v, cnt + 1);
            bs[i] = 0;
        }
    }
}

inline bool check(int v)
{
    for(int i = 1; i <= v; ++i)
    {
        bs.reset();
        bs[i] = 1;
        DFS(i, v);
        if(ok)
            return ok;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, v, e, x, y;
    cin >> t;
    while(t--)
    {
        cin >> v >> e;
        for(int i = 0; i < 15; ++i)
            a[i].clear();
        while(e--)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        ok = 0;
        cout << check(v) << endl;
    }
    return 0;
}