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
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int a[k + 1];
        for (int i = 1; i <= k; i++)
            cin >> a[i];
        int i = k;
        while (i > 0 and a[i - 1] + 1 == a[i])
            i--;
        if (i == 1 and a[i] == 1)
        {
            for (int j = n - k + 1; j <= n; j++)
                cout << j << " ";
        }
        else
        {
            a[i]--;
            for (int j = i + 1; j <= k; j++)
                a[j] = n - k + j;
            for (int j = 1; j <= k; j++)
                cout << a[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
