#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll f[n];
        priority_queue<ll, vector<ll>, greater<>> pq;
        for (int i = 0; i < n; i++)
        {
            cin >> f[i];
            pq.push(f[i]);
        }
        ll cnt = 0;
        while (pq.size() > 1)
        {
            ll x = 0;
            x += pq.top();
            pq.pop();
            x += pq.top();
            pq.pop();
            pq.push(x);
            cnt += x;
        }
        cout << cnt << "\n";
    }

    return 0;
}
