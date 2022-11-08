#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
ll sol(ll n, ll m, ll h, ll w)
{
    int ans = 0;
    while (h < n)
        ans++, h <<= 1;
    while (w < m)
        ans++, w <<= 1;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, h, w;
    cin >> n >> m >> h >> w;
    cout << min(sol(n, m, h, w), sol(m, n, h, w));
    return 0;
}