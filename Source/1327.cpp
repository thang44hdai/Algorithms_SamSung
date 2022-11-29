#include <bits/stdc++.h>
#pragma GCC optize("Ofast")
using namespace std;
#define ll long long
int n, k;
ll f[93];
ll m = 1e9 + 7;
void Set()
{
    f[1] = f[2] = 1;
    for (int i = 3; i <= 92; i++)
        f[i] = (f[i - 1] + f[i - 2]) % m;
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
        cin >> n;
        cout << f[n] << "\n";
    }
    return 0;
}