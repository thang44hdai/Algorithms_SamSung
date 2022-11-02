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
        cin >> n;
        int a[n + 5];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int i = n - 1;
        while (i > 0 and a[i] >= a[i + 1])
            i--;
        if (i == 0)
            for (int j = 1; j <= n; j++)
                cout << j << " ";
        else
        {
            int j = n;
            while (a[i] > a[j])
                j--;
            swap(a[i], a[j]);
            int l = i + 1, r = n;
            while (l < r)
            {
                swap(a[l], a[r]);
                l--, r++;
            }
            for (int j = 1; j <= n; j++)
                cout << a[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}