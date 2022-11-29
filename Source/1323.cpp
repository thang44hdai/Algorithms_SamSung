#include <bits/stdc++.h>
#pragma GCC optize("Ofast")
using namespace std;
#define ll long long
ll n, len;
string s;
int check(ll ans)
{
    string a = to_string(ans);
    int i = 0;
    int l = a.length();
    if (l == 1)
        if (s.find(a) != -1)
            return 1;
        else
            return 0;
    int idx = 0;
    for (; i < l - 1; i++)
    {
        int x = s.find(a[i], idx);
        if (x == -1)
            return 0;
        idx = x;
        int y = s.find(a[i + 1], idx + 1);
        if (y == -1)
            return 0;
        idx = y;
    }
    if (i == l - 1)
        return 1;
    return 0;
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
        cin >> s;
        bool test = false;
        n = ceil(pow(stoll(s), 1.0 / 3));
        for (ll i = n; i >= 0; --i)
        {
            ll ans = i * i * i;
            // cout << i << "^3 = " << ans << "\n";
            if (check(ans))
            {
                cout << ans;
                test = true;
                break;
            }
        }
        if (test == false)
            cout << -1;
        cout << "\n";
    }
    return 0;
}