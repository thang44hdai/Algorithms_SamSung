#include <bits/stdc++.h>
#pragma GCC optize("Ofast")
using namespace std;
int n;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
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
        cin >> n;
        int a[n + 5], b[n + 5];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        vector<pair<int, int>> vt;
        for (int i = 1; i <= n; i++)
            vt.push_back({a[i], b[i]});
        sort(vt.begin(), vt.end(), cmp);
        int T = vt[0].second, cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (vt[i].first >= T)
            {
                T = vt[i].second;
                cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}