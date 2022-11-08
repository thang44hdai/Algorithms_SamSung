#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long

int n, p, k, q;
vector<ll> a;
ll ans = 0, x;

void update(int i, ll val)
{
    int u = p + i;
    a[u] = val;
    u >>= 1;
    while (u)
    {
        a[u] = __gcd(a[2 * u], a[2 * u + 1]);
        u >>= 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 20; i >= 0; i--)
        if ((k >> i) & 1)
        {
            p = 1 << i;
            break;
        }
    if ((k & (-k)) != k)
        p << 1;
    a.assign(4 * k + 5, 0);
    for (int i = 0; i < k; i++)
        cin >> a[p + i];
    for (int i = p - 1; i > 0; i--)
        a[i] = __gcd(a[2 * i], a[2 * i + 1]);
    ans = a[1];
    for (int i = k; i < n; i++)
    {
        cin >> x;
        update(i % k, x);
        ans = max(ans, a[1]);
    }
    cout << ans;
    return 0;
}