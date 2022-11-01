#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
ll n, a, b, c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> a >> b >> c;
    ll cnt = 0;
    ll d = b - c, ans;
    if (a <= d)
        ans = n / a;
    else
    {
        ans = (n - b) / d + 1;
        n -= ans * d;
        ans += n / a;
    }
    cout << ans;
    return 0;
}