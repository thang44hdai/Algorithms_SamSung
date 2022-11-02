#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
ll n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int a[n];
    map<int, int> mp;
    for (auto &i : a)
        cin >> i;
    for (auto i : a)
        if (!mp[i])
        {
            cout << 0 << " ";
            mp[i] = 1;
        }
        else
            cout << 1 << " ";
    return 0;
}