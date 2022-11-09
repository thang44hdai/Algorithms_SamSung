#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
int n;
int a[15];
vector<int> vt;
int ok[15];
void Try(int i )
{
    if (vt.size() == n)
    {
        for (auto j : vt)
            cout << j;
        cout << " ";
    }
    for (int j = n; j >= 1; j--)
    {
        if (!ok[j])
        {
            vt.push_back(j);
            ok[j] = 1;
            Try(j - 1);
            vt.pop_back();
            ok[j] = 0;
        }
    }
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
        fill(ok, ok + n, 0);
        Try(n);
        cout<<"\n";
    }
    return 0;
}
