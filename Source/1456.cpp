#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
using namespace std;
int n;
ll a[55];
void Set()
{
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    for (int i = 3; i <= 50; i++)
        a[i] = a[i - 2] + a[i - 1] + a[i - 3];
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
        cout << a[n] << "\n";
    }
    return 0;
}
