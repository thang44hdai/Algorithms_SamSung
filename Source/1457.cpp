#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
using namespace std;
int n, k;
ll a[1005][1005] = {};
ll m = 1e9 + 7;
ll sol(int x, int y)
{
    if (a[x][y])
        return a[x][y];
    if (x == y)
        return a[x][y] = 1;
    if (x == 1)
        return a[x][y] = y;
    return a[x][y] = (sol(x - 1, y - 1) + sol(x, y - 1)) % m;
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
        cin >> n >> k;
        cout << sol(k, n) << "\n";
    }
    return 0;
}
