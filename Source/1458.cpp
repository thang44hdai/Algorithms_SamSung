#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
ll M = 1e9 + 7;
int n, k;
void sol(ll dp[])
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= min(i, k); j++)
            dp[i] = (dp[i] + dp[i - j]) % M;

    cout << dp[n] << "\n";
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
        ll dp[n + 5] = {}; // số cách đi từ bậc 1 đến bậc n
        sol(dp);
    }
    return 0;
}
