#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long

int n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &i : a)
        cin >> i;
    // nth_element(a.begin(), a.end() + a.size() / 2, a.end());
    // for (auto i : a)
    //     cout << i << " ";
    ll ans = 1e18;
    for (int i = -1; i <= 1; i += 2)
    {
        vector<ll> b = a;
        for (int j = 0; j < n; j += 2)
            b[j] += k * i;
        ll sum = 0;
        nth_element(b.begin(), b.end() + b.size() / 2, b.end());
        ll val = b[b.size() / 2];
        for (auto j : b)
            sum += abs(j - val);
        ans = min(ans, sum);
    }
    cout << ans;
    return 0;
}