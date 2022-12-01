#include <bits/stdc++.h>
#pragma GCC optize("Ofast")
using namespace std;
#define ll long long
ll n, k;
ll f[93];
void Set()
{
    f[1] = f[2] = 1;
    for (int i = 3; i <= 92; i++)
        f[i] = f[i - 1] + f[i - 2];
}
void sol()
{
    while (n > 2)
    {
        if (k <= f[n - 2])
            n -= 2;
        else
        {
            k -= f[n - 2];
            n--;
        }
    }
    (n == 1) ? cout << "A\n" : cout << "B\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Set();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        sol();
    }
    return 0;
}